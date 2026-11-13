// SPDX-License-Identifier: GPL-3.0-only
package com.mp240.android.smb

import java.io.ByteArrayOutputStream
import java.net.DatagramPacket
import java.net.Inet4Address
import java.net.InetAddress
import java.net.MulticastSocket
import java.net.NetworkInterface
import java.net.SocketTimeoutException
import java.util.Locale

/**
 * Looks up a `.local` name (`tower.local`, `nas.local`) with multicast DNS, as macOS and Linux
 * (Avahi) do. Android only learned this in Android 12, so on the bike's Android 7 the system
 * lookup of a `.local` name always fails.
 *
 * The query is a "legacy unicast" one (RFC 6762 §6.7): sent to 224.0.0.251:5353 from an ordinary
 * port, so the responder answers straight back to that port and no multicast receive (and no
 * Wi-Fi multicast lock) is needed. IPv4 only: an SMB server on a home network has one.
 */
object MdnsResolver {
    private val GROUP: InetAddress = InetAddress.getByName("224.0.0.251")
    private const val PORT = 5353
    private const val TYPE_A = 1
    private const val CLASS_IN = 1

    /**
     * The IPv4 addresses for [name], or an empty list if nothing answered within [timeoutMs].
     * Asks on every network interface at once (Wi-Fi, Ethernet, a VPN's), and asks again halfway
     * through in case the first packet was lost. [log] hears what was tried and what came back.
     */
    fun resolve(name: String, timeoutMs: Int = 2000, log: (String) -> Unit = {}): List<InetAddress> {
        val host = name.trimEnd('.').lowercase(Locale.ROOT)
        val query = query(host)
        val interfaces = candidateInterfaces()
        if (interfaces.isEmpty()) {
            log("mDNS: no network interface to ask on")
            return emptyList()
        }
        val sockets = interfaces.mapNotNull { nif ->
            val local = nif.inetAddresses.toList().filterIsInstance<Inet4Address>().joinToString { it.hostAddress ?: "" }
            try {
                MulticastSocket().apply {
                    networkInterface = nif
                    timeToLive = 255
                    soTimeout = 50
                } to "${nif.name} ($local)"
            } catch (e: Exception) {
                log("mDNS: can't ask on ${nif.name} ($local): ${e.javaClass.simpleName}: ${e.message}")
                null
            }
        }
        try {
            log("mDNS: asking for $host on " + sockets.joinToString { it.second })
            val send = { sockets.forEach { (socket, label) ->
                try {
                    socket.send(DatagramPacket(query, query.size, GROUP, PORT))
                } catch (e: Exception) {
                    log("mDNS: sending on $label failed: ${e.javaClass.simpleName}: ${e.message}")
                }
            } }
            send()
            val started = System.currentTimeMillis()
            var resent = false
            val buf = ByteArray(9000)
            while (System.currentTimeMillis() - started < timeoutMs) {
                if (!resent && System.currentTimeMillis() - started > timeoutMs / 2) {
                    send()
                    resent = true
                }
                for ((socket, label) in sockets) {
                    val packet = DatagramPacket(buf, buf.size)
                    try {
                        socket.receive(packet)
                    } catch (e: SocketTimeoutException) {
                        continue
                    } catch (e: Exception) {
                        continue
                    }
                    val found = runCatching { answers(buf, packet.length, host) }.getOrDefault(emptyList())
                    if (found.isNotEmpty()) {
                        log("mDNS: $label answered by ${packet.address.hostAddress}: " +
                            found.joinToString { it.hostAddress ?: "" } + " (${System.currentTimeMillis() - started} ms)")
                        return found
                    }
                }
            }
            log("mDNS: nothing answered for $host in $timeoutMs ms")
            return emptyList()
        } finally {
            sockets.forEach { runCatching { it.first.close() } }
        }
    }

    /** Up, non-loopback interfaces with an IPv4 address that can multicast (Wi-Fi, Ethernet). */
    private fun candidateInterfaces(): List<NetworkInterface> =
        runCatching { NetworkInterface.getNetworkInterfaces().toList() }.getOrDefault(emptyList()).filter { nif ->
            runCatching {
                nif.isUp && !nif.isLoopback && nif.supportsMulticast() &&
                    nif.inetAddresses.toList().any { it is Inet4Address }
            }.getOrDefault(false)
        }

    /** A one-question DNS query for [host]'s A record. */
    internal fun query(host: String): ByteArray {
        val out = ByteArrayOutputStream()
        // id 0, flags 0 (standard query), 1 question, no answers or other records.
        out.write(byteArrayOf(0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0))
        for (label in host.split('.').filter { it.isNotEmpty() }) {
            val bytes = label.toByteArray(Charsets.UTF_8)
            out.write(bytes.size)
            out.write(bytes)
        }
        out.write(0)
        out.write(byteArrayOf(0, TYPE_A.toByte(), 0, CLASS_IN.toByte()))
        return out.toByteArray()
    }

    /** The A records for [host] in a DNS response (any section: responders put them in answers or additionals). */
    internal fun answers(buf: ByteArray, length: Int, host: String): List<InetAddress> {
        fun u16(at: Int): Int {
            if (at + 2 > length) throw IndexOutOfBoundsException()
            return ((buf[at].toInt() and 0xff) shl 8) or (buf[at + 1].toInt() and 0xff)
        }
        if (length < 12 || (buf[2].toInt() and 0x80) == 0) return emptyList() // not a response
        val questions = u16(4)
        val records = u16(6) + u16(8) + u16(10)
        var at = 12
        repeat(questions) { at = readName(buf, length, at).second + 4 }
        val out = mutableListOf<InetAddress>()
        repeat(records) {
            val (name, next) = readName(buf, length, at)
            val type = u16(next)
            val dataLength = u16(next + 8)
            val data = next + 10
            if (data + dataLength > length) return out
            if (type == TYPE_A && dataLength == 4 && name.equals(host, ignoreCase = true)) {
                out += InetAddress.getByAddress(host, buf.copyOfRange(data, data + 4))
            }
            at = data + dataLength
        }
        return out
    }

    /** A (possibly compressed) DNS name at [start]: the name and the offset just after it. */
    private fun readName(buf: ByteArray, length: Int, start: Int): Pair<String, Int> {
        val labels = mutableListOf<String>()
        var at = start
        var end = -1
        var jumps = 0
        while (true) {
            if (at >= length) throw IndexOutOfBoundsException()
            val len = buf[at].toInt() and 0xff
            when {
                len == 0 -> {
                    if (end < 0) end = at + 1
                    return labels.joinToString(".") to end
                }
                len and 0xc0 == 0xc0 -> {
                    if (at + 1 >= length || ++jumps > 32) throw IndexOutOfBoundsException()
                    if (end < 0) end = at + 2
                    at = ((len and 0x3f) shl 8) or (buf[at + 1].toInt() and 0xff)
                }
                else -> {
                    if (at + 1 + len > length) throw IndexOutOfBoundsException()
                    labels += String(buf, at + 1, len, Charsets.UTF_8)
                    at += 1 + len
                }
            }
        }
    }
}

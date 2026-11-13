// SPDX-License-Identifier: GPL-3.0-only
package com.mp240.android.smb

import android.net.Uri
import com.hierynomus.mserref.NtStatus
import com.hierynomus.mssmb2.SMBApiException
import com.hierynomus.security.bc.BCSecurityProvider
import com.hierynomus.smbj.SMBClient
import com.hierynomus.smbj.SmbConfig
import com.hierynomus.smbj.auth.AuthenticationContext
import com.hierynomus.smbj.connection.Connection
import com.hierynomus.smbj.session.Session
import com.hierynomus.smbj.share.DiskShare
import org.json.JSONObject
import java.io.IOException
import java.net.ConnectException
import java.net.Inet4Address
import java.net.InetAddress
import java.net.InetSocketAddress
import java.net.NetworkInterface
import java.net.NoRouteToHostException
import java.net.Socket
import java.net.SocketTimeoutException
import java.net.UnknownHostException
import java.util.Locale
import java.util.concurrent.TimeUnit

/** Where the share is and who to sign in as. [port] 445 unless the server field says otherwise. */
data class ShareConfig(
    val host: String,
    val port: Int,
    val share: String,
    val username: String,
    val password: String,
    val domain: String,
) {
    companion object {
        /** From the JSON NetworkSharesBackend sends: {host, port, share, username, password, domain}. */
        fun fromJson(json: String): ShareConfig {
            val o = JSONObject(json)
            return ShareConfig(
                host = o.optString("host").trim(),
                port = o.optInt("port", DEFAULT_PORT).takeIf { it > 0 } ?: DEFAULT_PORT,
                share = o.optString("share").trim().trim('/', '\\'),
                username = o.optString("username"),
                password = o.optString("password"),
                domain = o.optString("domain"),
            )
        }

        const val DEFAULT_PORT = 445
    }
}

/** A file on a share, from an `smb://host[:port]/share/dir/file.mkv` URI. [path] uses backslashes, as SMB does. */
data class SmbLocation(val host: String, val port: Int, val share: String, val path: String) {
    companion object {
        fun parse(uri: Uri): SmbLocation {
            val segments = uri.pathSegments
            if (uri.scheme != "smb" || uri.host.isNullOrEmpty() || segments.isEmpty()) {
                throw IOException("not an smb:// file address: $uri")
            }
            return SmbLocation(
                host = uri.host!!,
                port = if (uri.port > 0) uri.port else ShareConfig.DEFAULT_PORT,
                share = segments.first(),
                path = segments.drop(1).joinToString("\\"),
            )
        }
    }
}

/**
 * The SMB 2/3 connection to the configured share (smbj), shared by browsing and the player.
 *
 * One connection and session are kept open and reused; smbj multiplexes requests over it, so the
 * browser and ExoPlayer's loader can use it at the same time. A request that fails because the
 * connection dropped (the NAS slept, Wi-Fi blinked) reconnects once and retries.
 *
 * Android's own crypto has no MD4, which NTLM sign-in needs, so smbj is given its BouncyCastle
 * provider.
 *
 * Server names are looked up here rather than by smbj, so that `.local` names work (see
 * [resolve]), and each step is written to [SmbLog] for the diagnostics screen.
 */
object SmbConnections {
    @Volatile
    var config: ShareConfig? = null
        private set

    private val client: SMBClient by lazy {
        SMBClient(
            SmbConfig.builder()
                .withSecurityProvider(BCSecurityProvider())
                // Long enough for a sleeping NAS to spin up; short enough that a connection the
                // NAS dropped (rebooted) is noticed and redone without a long stall.
                .withTimeout(10, TimeUnit.SECONDS)
                .withSoTimeout(30, TimeUnit.SECONDS)
                .build(),
        )
    }

    private var connection: Connection? = null
    private var session: Session? = null
    private var share: DiskShare? = null
    private var connectedTo: ShareConfig? = null

    /** Sets the share to use from now on; an open connection to another one is dropped. */
    @Synchronized
    fun configure(newConfig: ShareConfig?) {
        if (newConfig != config) reset()
        config = newConfig
    }

    /** Runs [block] against the share for [location] (or the configured share), reconnecting once on a dropped connection. */
    fun <T> withShare(location: SmbLocation? = null, block: (DiskShare) -> T): T {
        val cfg = target(location)
        return try {
            block(share(cfg))
        } catch (e: Exception) {
            if (!isConnectionLoss(e)) throw e
            SmbLog.add("Connection lost (${SmbLog.causes(e).first()}), reconnecting")
            reset()
            block(share(cfg))
        }
    }

    /** Signs in to [cfg] without disturbing the configured connection; throws with a reason if that fails. */
    fun test(cfg: ShareConfig) {
        SmbLog.add("Sign-in test: ${cfg.describe()}")
        val address = resolve(cfg.host)
        client.connect(address, cfg.port).use { conn ->
            SmbLog.add("Connected to $address:${cfg.port}, ${conn.negotiatedProtocol.dialect}")
            val s = conn.authenticate(AuthenticationContext(cfg.username, cfg.password.toCharArray(), cfg.domain))
            SmbLog.add("Signed in as ${who(cfg)}${sessionKind(s)}")
            try {
                (s.connectShare(cfg.share) as? DiskShare ?: throw IOException("\"${cfg.share}\" is not a file share")).use { it.list("") }
                SmbLog.add("Opened share \"${cfg.share}\"")
            } finally {
                s.close()
            }
        }
    }

    /**
     * Checks [cfg] one step at a time (look up the server, open TCP, SMB negotiate, sign in, open
     * and list the share), writing each step and its outcome to [SmbLog]. Never throws. Doesn't
     * touch the configured connection.
     */
    fun diagnose(cfg: ShareConfig) {
        val log = SmbLog::add
        log("===== Diagnose: ${cfg.describe()} =====")
        log("This device: " + localAddresses().ifEmpty { "no network address (is Wi-Fi on?)" })
        var step = "1/5 Look up ${cfg.host}"
        try {
            log(step)
            val addresses = lookUp(cfg.host, log)
            if (addresses.isEmpty()) {
                log("FAILED at 1/5: can't find a server called ${cfg.host}." +
                    if (isLocalName(cfg.host)) " Check the name, or enter the server's IP address instead." else
                        " Try the server's IP address, or its name with .local on the end.")
                return
            }
            val address = addresses.first().hostAddress ?: cfg.host

            step = "2/5 TCP connect to $address:${cfg.port}"
            log(step)
            var started = System.currentTimeMillis()
            Socket().use { it.connect(InetSocketAddress(address, cfg.port), 5000) }
            log("  open (${System.currentTimeMillis() - started} ms)")

            step = "3/5 SMB negotiate"
            log(step)
            started = System.currentTimeMillis()
            client.connect(address, cfg.port).use { conn ->
                val ctx = conn.connectionContext
                log("  ${conn.negotiatedProtocol.dialect}, signing ${if (ctx.isServerRequiresSigning) "required" else "optional"}, " +
                    "server ${ctx.serverName ?: "?"} (${System.currentTimeMillis() - started} ms)")

                step = "4/5 Sign in as ${who(cfg)}"
                log("$step (password ${if (cfg.password.isEmpty()) "empty" else "${cfg.password.length} characters"})")
                started = System.currentTimeMillis()
                val session = conn.authenticate(AuthenticationContext(cfg.username, cfg.password.toCharArray(), cfg.domain))
                try {
                    log("  signed in${sessionKind(session)} (${System.currentTimeMillis() - started} ms)")

                    step = "5/5 Open share \"${cfg.share}\""
                    log(step)
                    val share = session.connectShare(cfg.share) as? DiskShare
                        ?: throw IOException("\"${cfg.share}\" is not a file share (a printer or pipe?)")
                    share.use {
                        val entries = it.list("").count { e -> e.fileName != "." && e.fileName != ".." }
                        log("  open, $entries entries in its top folder")
                    }
                } finally {
                    runCatching { session.close() }
                }
            }
            log("PASSED: every step worked.")
        } catch (e: Exception) {
            log("FAILED at $step: ${describe(e, cfg)}")
            SmbLog.causes(e).forEach { log("  $it") }
        }
    }

    /**
     * The address to connect to for [host]: an IP address as it is, otherwise the system's DNS,
     * and for a `.local` name (or a bare name like `TOWER` that DNS doesn't know) multicast DNS,
     * which Android 7 doesn't do on its own. Throws [UnknownHostException] when nothing works.
     */
    fun resolve(host: String): String {
        if (isIpAddress(host)) return host
        resolved[host.lowercase(Locale.ROOT)]?.let { (address, at) ->
            if (System.currentTimeMillis() - at < CACHE_MS) return address
        }
        val found = lookUp(host, SmbLog::add).firstOrNull()?.hostAddress
            ?: throw UnknownHostException("Can't find a server called $host")
        resolved[host.lowercase(Locale.ROOT)] = found to System.currentTimeMillis()
        return found
    }

    private val resolved = java.util.concurrent.ConcurrentHashMap<String, Pair<String, Long>>()
    private const val CACHE_MS = 10 * 60 * 1000L

    /** Every way [resolve] looks [host] up, logging each; IPv4 first. Empty when none worked. */
    private fun lookUp(host: String, log: (String) -> Unit): List<InetAddress> {
        if (isIpAddress(host)) {
            log("  $host is an IP address, no lookup needed")
            return listOf(InetAddress.getByName(host))
        }
        val started = System.currentTimeMillis()
        try {
            val all = InetAddress.getAllByName(host).sortedBy { if (it is Inet4Address) 0 else 1 }
            log("  DNS: ${all.joinToString { it.hostAddress ?: "" }} (${System.currentTimeMillis() - started} ms)")
            return all
        } catch (e: UnknownHostException) {
            log("  DNS: not found (${System.currentTimeMillis() - started} ms)" +
                if (isLocalName(host)) "; expected for a .local name on Android 7" else "")
        }
        val mdnsName = when {
            isLocalName(host) -> host
            !host.contains('.') -> "$host.local"
            else -> return emptyList()
        }
        return MdnsResolver.resolve(mdnsName, log = { log("  $it") })
    }

    private fun isLocalName(host: String) = host.trimEnd('.').lowercase(Locale.ROOT).endsWith(".local")

    private fun isIpAddress(host: String) =
        host.matches(Regex("""\d{1,3}(\.\d{1,3}){3}""")) || host.contains(':')

    private fun localAddresses(): String =
        runCatching {
            NetworkInterface.getNetworkInterfaces().toList()
                .filter { it.isUp && !it.isLoopback }
                .flatMap { nif -> nif.inetAddresses.toList().filterIsInstance<Inet4Address>().map { "${nif.name} ${it.hostAddress}" } }
                .joinToString(", ")
        }.getOrDefault("")

    private fun who(cfg: ShareConfig) =
        "\"${cfg.username}\"" + if (cfg.domain.isNotBlank()) " (domain \"${cfg.domain}\")" else ""

    /** " as guest" when the server let us in as a guest instead of the account, which then usually can't open the share. */
    private fun sessionKind(s: Session) = when {
        s.isAnonymous -> " ANONYMOUSLY (the server ignored the account)"
        s.isGuest -> " as GUEST (the server didn't accept the account and let us in as a guest)"
        else -> ""
    }

    private fun ShareConfig.describe() =
        "server $host:$port, share \"$share\", user \"$username\"" + if (domain.isNotBlank()) ", domain \"$domain\"" else ""

    /** The configured credentials, aimed at [location]'s host and share when it names one. */
    private fun target(location: SmbLocation?): ShareConfig {
        val cfg = config ?: throw IOException("no network share is set up")
        if (location == null) return cfg
        return cfg.copy(host = location.host, port = location.port, share = location.share)
    }

    @Synchronized
    private fun share(cfg: ShareConfig): DiskShare {
        val open = share
        if (open != null && connectedTo == cfg && open.isConnected) return open
        reset()
        try {
            val address = resolve(cfg.host)
            val conn = client.connect(address, cfg.port)
            val s = conn.authenticate(AuthenticationContext(cfg.username, cfg.password.toCharArray(), cfg.domain))
            val disk = s.connectShare(cfg.share) as? DiskShare
                ?: throw IOException("\"${cfg.share}\" is not a file share")
            SmbLog.add("Connected: ${cfg.describe()} at $address, ${conn.negotiatedProtocol.dialect}${sessionKind(s)}")
            connection = conn
            session = s
            share = disk
            connectedTo = cfg
            return disk
        } catch (e: Exception) {
            SmbLog.failure("Connecting failed: ${cfg.describe()}: ${describe(e, cfg)}", e)
            throw e
        }
    }

    @Synchronized
    private fun reset() {
        runCatching { share?.close() }
        runCatching { session?.close() }
        runCatching { connection?.close(true) }
        share = null
        session = null
        connection = null
        connectedTo = null
    }

    private fun isConnectionLoss(e: Throwable): Boolean {
        var t: Throwable? = e
        while (t != null) {
            if (t is com.hierynomus.protocol.transport.TransportException || t is java.net.SocketException ||
                t is java.io.EOFException
            ) {
                return true
            }
            if (t is SMBApiException && (t.status == NtStatus.STATUS_NETWORK_NAME_DELETED ||
                    t.status == NtStatus.STATUS_USER_SESSION_DELETED)
            ) {
                return true
            }
            t = t.cause
        }
        return false
    }

    /** A sentence for the rider about why [e] happened. */
    fun describe(e: Throwable, cfg: ShareConfig? = config): String {
        var t: Throwable? = e
        while (t != null) {
            when (t) {
                is UnknownHostException -> return "Can't find a server called ${cfg?.host ?: "that"}" +
                    " (try its IP address)"
                is ConnectException, is NoRouteToHostException, is SocketTimeoutException ->
                    return "Can't reach ${cfg?.host ?: "the server"} (is SMB on, and the address right?)"
                is SMBApiException -> return when (t.status) {
                    NtStatus.STATUS_LOGON_FAILURE -> "Wrong username or password"
                    NtStatus.STATUS_PASSWORD_EXPIRED -> "That account's password has expired"
                    NtStatus.STATUS_ACCOUNT_DISABLED, NtStatus.STATUS_LOGON_TYPE_NOT_GRANTED -> "That account isn't allowed to sign in"
                    NtStatus.STATUS_BAD_NETWORK_PATH -> "Can't reach ${cfg?.host ?: "the server"}"
                    NtStatus.STATUS_BAD_NETWORK_NAME -> "No share called \"${cfg?.share ?: ""}\" on that server"
                    NtStatus.STATUS_ACCESS_DENIED -> "Access denied"
                    NtStatus.STATUS_OBJECT_NAME_NOT_FOUND, NtStatus.STATUS_OBJECT_PATH_NOT_FOUND -> "That file or folder is gone"
                    else -> "The server said ${t.status}"
                }
            }
            t = t.cause
        }
        return e.message ?: e.javaClass.simpleName
    }
}

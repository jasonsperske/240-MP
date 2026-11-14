// SPDX-License-Identifier: GPL-3.0-only
package com.mp240.android.smb

import android.net.Uri
import com.hierynomus.msdtyp.AccessMask
import com.hierynomus.mssmb2.SMB2CreateDisposition
import com.hierynomus.mssmb2.SMB2ShareAccess
import java.io.BufferedReader
import java.io.IOException
import java.io.InputStreamReader
import java.io.OutputStream
import java.net.InetAddress
import java.net.ServerSocket
import java.net.Socket
import java.net.URLEncoder
import java.util.EnumSet
import java.util.concurrent.ConcurrentHashMap
import java.util.concurrent.Executors
import java.util.concurrent.atomic.AtomicInteger

/**
 * Serves files on the SMB share over HTTP on 127.0.0.1, for the VLC fallback player
 * ([com.mp240.android.VlcPlayer]). VLC can't use the app's SMB connection, and its own SMB
 * support can't look up `.local` names or reuse the sign-in. So it is given an
 * `http://127.0.0.1:<port>/<id>/<name>` address instead, and each request is answered by reading
 * the file through [SmbConnections], with byte ranges so VLC can seek.
 *
 * Only addresses handed out by [url] are served, and only to this device.
 */
object SmbHttpServer {
    private const val CHUNK = 1 shl 20

    private var server: ServerSocket? = null
    private val files = ConcurrentHashMap<String, String>()
    private val nextId = AtomicInteger(1)
    private val pool = Executors.newCachedThreadPool { r -> Thread(r, "240mp-smb-http").apply { isDaemon = true } }

    /** A loopback HTTP address that serves [smbUri] (`smb://host/share/dir/file.avi`). */
    @Synchronized
    fun url(smbUri: String): String {
        val port = start()
        val id = nextId.getAndIncrement().toString()
        files[id] = smbUri
        val name = Uri.parse(smbUri).lastPathSegment ?: "file"
        return "http://127.0.0.1:$port/$id/" + URLEncoder.encode(name, "UTF-8").replace("+", "%20")
    }

    @Synchronized
    private fun start(): Int {
        server?.let { return it.localPort }
        val s = ServerSocket(0, 16, InetAddress.getByName("127.0.0.1"))
        server = s
        Thread({
            while (true) {
                val client = try { s.accept() } catch (e: IOException) { break }
                pool.execute { serve(client) }
            }
        }, "240mp-smb-http-accept").apply { isDaemon = true }.start()
        SmbLog.add("Started the local server for the fallback player on port ${s.localPort}")
        return s.localPort
    }

    private fun serve(socket: Socket) {
        socket.use { sock ->
            sock.soTimeout = 30_000
            val input = BufferedReader(InputStreamReader(sock.getInputStream(), Charsets.ISO_8859_1))
            val out = sock.getOutputStream()
            val requestLine = input.readLine() ?: return
            var range: String? = null
            while (true) {
                val line = input.readLine() ?: break
                if (line.isEmpty()) break
                if (line.startsWith("Range:", ignoreCase = true)) range = line.substringAfter(':').trim()
            }
            val parts = requestLine.split(' ')
            val method = parts.getOrNull(0) ?: ""
            val id = parts.getOrNull(1)?.trim('/')?.substringBefore('/') ?: ""
            val smbUri = files[id]
            if ((method != "GET" && method != "HEAD") || smbUri == null) {
                status(out, "404 Not Found", 0)
                return
            }
            try {
                send(out, smbUri, range, method == "HEAD")
            } catch (e: IOException) {
                // The player closed the connection (a seek or the end); nothing to report.
            } catch (e: Exception) {
                SmbLog.failure("Fallback player: serving $smbUri failed: ${SmbConnections.describe(e)}", e)
                runCatching { status(out, "502 Bad Gateway", 0) }
            }
        }
    }

    private fun send(out: OutputStream, smbUri: String, range: String?, headOnly: Boolean) {
        val location = SmbLocation.parse(Uri.parse(smbUri))
        val file = SmbConnections.withShare(location) { share ->
            share.openFile(location.path, EnumSet.of(AccessMask.GENERIC_READ), null, SMB2ShareAccess.ALL,
                SMB2CreateDisposition.FILE_OPEN, null)
        }
        file.use { f ->
            val size = f.fileInformation.standardInformation.endOfFile
            // "bytes=START-" or "bytes=START-END" (suffix ranges aren't asked for by VLC).
            val match = range?.let { Regex("""bytes=(\d+)-(\d*)""").find(it) }
            val start = match?.groupValues?.get(1)?.toLongOrNull() ?: 0L
            val end = match?.groupValues?.get(2)?.toLongOrNull()?.coerceAtMost(size - 1) ?: (size - 1)
            if (match != null && start >= size) {
                out.write("HTTP/1.1 416 Range Not Satisfiable\r\nContent-Range: bytes */$size\r\nContent-Length: 0\r\nConnection: close\r\n\r\n".toByteArray())
                return
            }
            val length = end - start + 1
            val head = StringBuilder()
                .append(if (match != null) "HTTP/1.1 206 Partial Content\r\n" else "HTTP/1.1 200 OK\r\n")
                .append("Content-Type: application/octet-stream\r\n")
                .append("Accept-Ranges: bytes\r\n")
                .append("Content-Length: $length\r\n")
            if (match != null) head.append("Content-Range: bytes $start-$end/$size\r\n")
            head.append("Connection: close\r\n\r\n")
            out.write(head.toString().toByteArray(Charsets.ISO_8859_1))
            if (headOnly) return
            val buf = ByteArray(CHUNK)
            var pos = start
            while (pos <= end) {
                val want = minOf(CHUNK.toLong(), end - pos + 1).toInt()
                val n = f.read(buf, pos, 0, want)
                if (n <= 0) break
                out.write(buf, 0, n)
                pos += n
            }
            out.flush()
        }
    }

    private fun status(out: OutputStream, status: String, length: Int) {
        out.write("HTTP/1.1 $status\r\nContent-Length: $length\r\nConnection: close\r\n\r\n".toByteArray())
    }
}

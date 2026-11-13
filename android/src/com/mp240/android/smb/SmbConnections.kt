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
import java.net.NoRouteToHostException
import java.net.SocketTimeoutException
import java.net.UnknownHostException
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
            reset()
            block(share(cfg))
        }
    }

    /** Signs in to [cfg] without disturbing the configured connection; throws with a reason if that fails. */
    fun test(cfg: ShareConfig) {
        client.connect(cfg.host, cfg.port).use { conn ->
            val s = conn.authenticate(AuthenticationContext(cfg.username, cfg.password.toCharArray(), cfg.domain))
            try {
                (s.connectShare(cfg.share) as? DiskShare ?: throw IOException("\"${cfg.share}\" is not a file share")).use { it.list("") }
            } finally {
                s.close()
            }
        }
    }

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
        val conn = client.connect(cfg.host, cfg.port)
        val s = conn.authenticate(AuthenticationContext(cfg.username, cfg.password.toCharArray(), cfg.domain))
        val disk = s.connectShare(cfg.share) as? DiskShare
            ?: throw IOException("\"${cfg.share}\" is not a file share")
        connection = conn
        session = s
        share = disk
        connectedTo = cfg
        return disk
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
                is UnknownHostException -> return "Can't find a server called ${cfg?.host ?: "that"}"
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

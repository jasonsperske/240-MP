// SPDX-License-Identifier: GPL-3.0-only
package com.mp240.android.smb

import android.util.Log
import com.hierynomus.msfscc.FileAttributes
import org.json.JSONArray
import org.json.JSONObject
import java.util.Locale
import java.util.concurrent.Executors

/**
 * What the Network Shares module's C++ backend (src/modules/network_shares/NetworkSharesBackend.cpp)
 * asks of the share, over JNI. Network work runs on a private thread; each answer comes back
 * through a `native*` method, registered by C++, carrying the request's id.
 */
object SmbBridge {
    private const val TAG = "240mp.smb"
    private val worker = Executors.newSingleThreadExecutor { r -> Thread(r, "240mp-smb").apply { isDaemon = true } }

    /** File types the browser shows; subtitles are attached to their video instead of listed. */
    private val MEDIA = setOf(
        "mp4", "m4v", "mkv", "mov", "avi", "webm", "ts", "m2ts", "mts", "mpg", "mpeg", "wmv", "flv", "3gp", "ogv", "vob",
        "mp3", "m4a", "aac", "flac", "ogg", "opus", "wav",
    )
    private val SUBTITLES = setOf("srt", "vtt", "ass", "ssa")

    /** The share to use (JSON as in [ShareConfig.fromJson]), or "" for none. */
    @JvmStatic
    fun configure(json: String) {
        SmbConnections.configure(if (json.isBlank()) null else ShareConfig.fromJson(json))
    }

    /** Tries signing in to the share in [json]; answers with [nativeTestResult]. */
    @JvmStatic
    fun test(requestId: Int, json: String) {
        worker.execute {
            val cfg = ShareConfig.fromJson(json)
            val result = runCatching { SmbConnections.test(cfg) }
            result.exceptionOrNull()?.let { Log.w(TAG, "sign-in to ${cfg.host}/${cfg.share} failed", it) }
            nativeTestResult(requestId, result.isSuccess, result.exceptionOrNull()?.let { SmbConnections.describe(it, cfg) } ?: "")
        }
    }

    /**
     * Lists the folder [path] ("" for the share's top, "/" separated) of the configured share;
     * answers with [nativeListResult]:
     * `{"ok":true,"items":[{"name","path","isFolder","size","subtitles":[paths]}]}` or `{"ok":false,"error":"..."}`.
     * Folders come first, then media files, each by name; hidden and system entries are left out.
     */
    @JvmStatic
    fun list(requestId: Int, path: String) {
        worker.execute {
            val json = try {
                listing(path.trim('/'))
            } catch (e: Exception) {
                Log.w(TAG, "listing \"$path\" failed", e)
                JSONObject().put("ok", false).put("error", SmbConnections.describe(e)).toString()
            }
            nativeListResult(requestId, json)
        }
    }

    private fun listing(path: String): String {
        val entries = SmbConnections.withShare { it.list(path.replace('/', '\\')) }
        val hiddenOrSystem = FileAttributes.FILE_ATTRIBUTE_HIDDEN.value or FileAttributes.FILE_ATTRIBUTE_SYSTEM.value
        val visible = entries.filter { e ->
            val n = e.fileName
            n != "." && n != ".." && !n.startsWith(".") && !n.startsWith("$") && (e.fileAttributes and hiddenOrSystem) == 0L
        }
        val subtitles = visible.filter { extension(it.fileName) in SUBTITLES }.map { it.fileName }
        val items = visible.mapNotNull { e ->
            val isFolder = (e.fileAttributes and FileAttributes.FILE_ATTRIBUTE_DIRECTORY.value) != 0L
            if (!isFolder && extension(e.fileName) !in MEDIA) return@mapNotNull null
            Triple(e.fileName, isFolder, e.endOfFile)
        }.sortedWith(compareBy<Triple<String, Boolean, Long>>({ !it.second }, { it.first.lowercase(Locale.ROOT) }))

        val out = JSONArray()
        for ((name, isFolder, size) in items) {
            val itemPath = if (path.isEmpty()) name else "$path/$name"
            val item = JSONObject().put("name", name).put("path", itemPath).put("isFolder", isFolder).put("size", size)
            if (!isFolder) {
                val base = name.substringBeforeLast('.')
                // "Movie.srt", "Movie.en.srt", "Movie.forced.en.srt" all belong to "Movie.mkv".
                val subs = subtitles.filter { it.startsWith("$base.", ignoreCase = true) }.sorted()
                    .map { if (path.isEmpty()) it else "$path/$it" }
                item.put("subtitles", JSONArray(subs))
            }
            out.put(item)
        }
        return JSONObject().put("ok", true).put("items", out).toString()
    }

    private fun extension(name: String) = name.substringAfterLast('.', "").lowercase(Locale.ROOT)

    // Registered by C++ (JNI RegisterNatives); called on the SMB thread.
    @JvmStatic external fun nativeTestResult(requestId: Int, ok: Boolean, message: String)

    @JvmStatic external fun nativeListResult(requestId: Int, json: String)
}

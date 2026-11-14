// SPDX-License-Identifier: GPL-3.0-only
package com.mp240.android.smb

import android.util.Log
import java.text.SimpleDateFormat
import java.util.ArrayDeque
import java.util.Date
import java.util.Locale

/**
 * What the network-share code did, for the Network Shares diagnostics screen: lookups,
 * connections, sign-ins and failures, newest last. Kept in memory (the last [MAX_LINES] lines,
 * cleared when the app restarts) and copied to logcat under [TAG].
 */
object SmbLog {
    const val TAG = "240mp.smb"
    private const val MAX_LINES = 400
    private val lines = ArrayDeque<String>()
    private val clock = SimpleDateFormat("HH:mm:ss.SSS", Locale.US)

    @Synchronized
    fun add(message: String) {
        Log.i(TAG, message)
        for (line in message.lines()) {
            lines.addLast("${clock.format(Date())} $line")
            while (lines.size > MAX_LINES) lines.removeFirst()
        }
    }

    /** [message], then [e] and each of its causes as "Class: message" lines. */
    fun failure(message: String, e: Throwable) {
        Log.w(TAG, message, e)
        add("$message\n" + causes(e).joinToString("\n") { "  $it" })
    }

    @Synchronized
    fun text(): String = lines.joinToString("\n")

    /** Whether [e] only says the reading thread was stopped (the player let go of the file), not a failure. */
    fun isInterruption(e: Throwable): Boolean =
        generateSequence(e) { it.cause.takeIf { c -> c !== it } }.take(12)
            .any { it is InterruptedException || it is java.io.InterruptedIOException }

    /** [e] and its causes, outermost first, as "Class: message". */
    fun causes(e: Throwable): List<String> {
        val out = mutableListOf<String>()
        var t: Throwable? = e
        while (t != null && out.size < 8) {
            out += "${t.javaClass.simpleName}: ${t.message ?: ""}".trimEnd(' ', ':')
            t = t.cause.takeIf { it !== t }
        }
        return out
    }
}

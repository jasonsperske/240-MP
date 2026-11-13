// SPDX-License-Identifier: GPL-3.0-only
package com.mp240.android

import android.content.Context
import android.content.Intent

/**
 * The seam between the C++ player controller (src/player/AndroidPlayerController.cpp) and
 * [PlayerActivity]. On Android, 240-MP hands video off to that Activity the way it hands off to an
 * mpv process on the desktop: the shell launches it and resumes when it finishes.
 *
 * C++ calls the static methods below through JNI; the activity reports back through the
 * `native*` methods, which C++ registers when the controller is created.
 */
object PlayerBridge {
    /** The activity playing now, if any; main thread only. */
    @Volatile internal var current: PlayerActivity? = null

    /** Starts playback. [requestJson] is built by AndroidPlayerController::loadAndPlay; see PlayerRequest. */
    @JvmStatic
    fun play(context: Context, requestJson: String) {
        val intent = Intent(context, PlayerActivity::class.java)
            .putExtra(PlayerActivity.EXTRA_REQUEST, requestJson)
        // The Qt activity is the usual caller; NEW_TASK covers a call with the application context.
        if (context !is android.app.Activity) intent.addFlags(Intent.FLAG_ACTIVITY_NEW_TASK)
        context.startActivity(intent)
    }

    @JvmStatic
    fun stop() {
        current?.let { it.runOnUiThread { it.finishWith(PlayerActivity.REASON_STOPPED) } }
    }

    @JvmStatic
    fun seekTo(positionMs: Int) {
        current?.let { it.runOnUiThread { it.seekTo(positionMs.toLong()) } }
    }

    @JvmStatic
    fun showSkipPrompt(show: Boolean) {
        current?.let { it.runOnUiThread { it.showSkipPrompt(show) } }
    }

    // Registered by C++ (JNI RegisterNatives); called on the main thread.

    // [session] is the request's "session": C++ drops reports from a playback it has moved on from.

    /** About twice a second while playing. [playlistPos] is the index into the request's urls. */
    @JvmStatic external fun nativeProgress(session: Int, positionMs: Int, durationMs: Int, playlistPos: Int)

    /** Once per playback: "eof", "stopped" or "failed", as MpvController's playbackEnded. */
    @JvmStatic external fun nativeEnded(session: Int, positionMs: Int, durationMs: Int, reason: String)

    /** The rider took the skip prompt (Plex's "skip intro"). */
    @JvmStatic external fun nativeSkipRequested(session: Int)
}

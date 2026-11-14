// SPDX-License-Identifier: GPL-3.0-only
package com.mp240.android

import com.mp240.exercise.Difficulty
import com.mp240.exercise.Workout
import org.json.JSONArray
import org.json.JSONObject

/**
 * What to play and how: the JSON that AndroidPlayerController::loadAndPlay sends, mirroring the
 * arguments of MpvController::loadAndPlay that make sense outside mpv.
 */
class PlayerRequest(json: String) {
    private val o = JSONObject(json)

    /** Numbers the playback; echoed back in every report to C++. */
    val session: Int = o.optInt("session")

    /** The primary url followed by any extra playlist entries. */
    val urls: List<String> = strings(o.optJSONArray("urls"))
    val playlistStart: Int = o.optInt("playlistStart", 0).coerceAtLeast(0)
    val startMs: Long = o.optLong("startMs", 0)
    val loop: Boolean = o.optBoolean("loop")
    val shuffle: Boolean = o.optBoolean("shuffle")
    val mute: Boolean = o.optBoolean("mute")

    /** HTTP request headers (the Plex or Jellyfin token). */
    val headers: Map<String, String> = o.optJSONObject("headers")?.let { h ->
        h.keys().asSequence().associateWith { h.getString(it) }
    } ?: emptyMap()

    val subFiles: List<String> = strings(o.optJSONArray("subFiles"))
    val subLangs: List<String> = strings(o.optJSONArray("subLangs"))
    val subTitles: List<String> = strings(o.optJSONArray("subTitles"))

    /** As mpv's: >0 picks that (1-based) subtitle track, 0 automatic, <0 off. */
    val subTrack: Int = o.optInt("subTrack", 0)

    /** As mpv's: >0 picks that (1-based) audio track, otherwise the default. */
    val audioTrack: Int = o.optInt("audioTrack", 0)

    /** The app's VCR font, for the HUD; empty for the system monospace. */
    val fontPath: String = o.optString("fontPath")

    val exercise: Exercise = Exercise(o.optJSONObject("exercise") ?: JSONObject())

    class Exercise(o: JSONObject) {
        val enabled: Boolean = o.optBoolean("enabled")
        val workout: Workout = Workout.fromLabel(o.optString("workout"))
        val difficulty: Difficulty = Difficulty.fromLabel(o.optString("difficulty"))
        val simulate: Boolean = o.optBoolean("simulate")
        /** Exercise module's Stats View and Stats Corner, as their labels ("Minimal", "Top Right"). */
        val statsStyle: RideHud.Style = RideHud.Style.fromLabel(o.optString("statsStyle"))
        val statsCorner: RideHud.Corner = RideHud.Corner.fromLabel(o.optString("statsCorner"))
    }

    private fun strings(a: JSONArray?): List<String> =
        if (a == null) emptyList() else (0 until a.length()).map { a.getString(it) }
}

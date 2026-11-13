// SPDX-License-Identifier: GPL-3.0-only
package com.mp240.android

import android.content.Context
import android.content.Intent
import com.mp240.exercise.Difficulty
import com.mp240.exercise.Program
import com.mp240.exercise.Workout
import com.mp240.exercise.toJson
import dev.soloton.bike.BikeDiagnosticsActivity
import dev.soloton.bike.BikePaceSource
import dev.soloton.bike.BikeState
import org.json.JSONObject

/**
 * What the exercise module's C++ backend (src/modules/exercise/ExerciseBackend.cpp) reads from the
 * bike for its Ride Check screen. Called through JNI from the Qt thread; everything here is cheap
 * and thread-safe.
 */
object RideBridge {
    private var bike: BikePaceSource? = null

    /** Connects to the bike (or keeps the connection) while Ride Check is open. */
    @JvmStatic
    @Synchronized
    fun start(context: Context) {
        if (bike == null) bike = Bike.acquire(context)
    }

    @JvmStatic
    @Synchronized
    fun stop() {
        if (bike != null) {
            bike = null
            Bike.release()
        }
    }

    /**
     * The bike now, as JSON:
     * `{"state":"Connected (...)","connected":true,"live":true,"absent":false,"rpm":72,"watts":118,"resistance":34}`.
     */
    @JvmStatic
    @Synchronized
    fun status(): String {
        val s = bike ?: return JSONObject().put("state", "Not started").put("connected", false)
            .put("live", false).put("absent", false).put("rpm", 0).put("watts", 0).put("resistance", 0).toString()
        val sample = Bike.sample(s)
        return JSONObject()
            .put("state", s.sensors.state.description)
            .put("connected", s.sensors.state is BikeState.Connected)
            .put("live", sample.live)
            .put("absent", Bike.absent(s))
            .put("rpm", Math.round(sample.rpm))
            .put("watts", Math.round(Bike.watts(s)))
            .put("resistance", Math.round(sample.resistance))
            .toString()
    }

    /** The program [workout] at [difficulty] lays over a video of [durationSec] seconds, as JSON (see Program.toJson). */
    @JvmStatic
    fun preview(workout: String, difficulty: String, durationSec: Int): String =
        Program.build(Workout.fromLabel(workout), Difficulty.fromLabel(difficulty), durationSec * 1000L).toJson()

    /** Opens the bike library's diagnostics screen (its "Copy report" is what to send when a bike won't connect). */
    @JvmStatic
    fun openDiagnostics(context: Context) {
        val intent = Intent(context, BikeDiagnosticsActivity::class.java)
        if (context !is android.app.Activity) intent.addFlags(Intent.FLAG_ACTIVITY_NEW_TASK)
        context.startActivity(intent)
    }
}

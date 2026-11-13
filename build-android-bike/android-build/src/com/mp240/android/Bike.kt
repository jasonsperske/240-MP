// SPDX-License-Identifier: GPL-3.0-only
package com.mp240.android

import android.content.Context
import android.os.Handler
import android.os.Looper
import com.mp240.exercise.RideSample
import dev.soloton.bike.BikePaceSource
import dev.soloton.bike.BikeState

/**
 * The one connection to the bike's sensor service, shared by everything in the process that reads
 * it: the exercise module's Ride Check screen and the player.
 *
 * Users [acquire] and [release] it. The service is unbound a few seconds after the last user lets
 * go, not at once, so going from Ride Check into a video does not rebind. That matters on
 * Affernet, which stops talking to the bike when its last client of an Intent unbinds
 * (docs/BIKE_SENSORS.md in soloton).
 *
 * Reads follow ExerDoom's: cadence is the latest raw sample (the gate wants what the rider is
 * doing, not a smoothed pace), resistance is the library's spike-filtered knob, 0 once stale.
 */
object Bike {
    private const val RELEASE_DELAY_MS = 5_000L

    private val main = Handler(Looper.getMainLooper())
    private var source: BikePaceSource? = null
    private var users = 0
    private val stopLater = Runnable { synchronized(this) { if (users == 0) source?.stop() } }

    @Synchronized
    fun acquire(context: Context): BikePaceSource {
        val s = source ?: BikePaceSource(context.applicationContext).also { source = it }
        main.removeCallbacks(stopLater)
        users++
        if (!s.sensors.isStarted) s.start()
        return s
    }

    @Synchronized
    fun release() {
        if (users == 0) return
        if (--users == 0) main.postDelayed(stopLater, RELEASE_DELAY_MS)
    }

    /** A snapshot for the ride gate. */
    fun sample(s: BikePaceSource): RideSample {
        val live = s.isLive
        return RideSample(
            live = live,
            rpm = if (live) s.sensors.latest?.cadenceRpm ?: 0f else 0f,
            resistance = if (live) s.resistance.fraction * 100f else 0f,
        )
    }

    fun watts(s: BikePaceSource): Float = if (s.isLive) s.sensors.latest?.powerWatts ?: 0f else 0f

    /** True when no Peloton sensor service is installed at all (an emulator, a phone): waiting will not help. */
    fun absent(s: BikePaceSource): Boolean = s.sensors.state is BikeState.Unavailable && s.sensors.route == null &&
        (s.sensors.state as BikeState.Unavailable).reason.startsWith("no Peloton sensor service")
}

/**
 * A stand-in bike for trying exercise mode without one (the emulator, a desk). Turned on by the
 * exercise module's "Simulated Bike" setting. It starts at the target the player asks for and the
 * rider nudges it with the keys (up/down: cadence, page up/down or [ and ]: resistance).
 */
class SimulatedBike(var rpm: Float, var resistance: Float) {
    fun sample() = RideSample(live = true, rpm = rpm, resistance = resistance)

    fun nudgeRpm(delta: Float) {
        rpm = (rpm + delta).coerceIn(0f, 150f)
    }

    fun nudgeResistance(delta: Float) {
        resistance = (resistance + delta).coerceIn(0f, 100f)
    }
}

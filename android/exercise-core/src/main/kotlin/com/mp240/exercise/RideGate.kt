// SPDX-License-Identifier: GPL-3.0-only
package com.mp240.exercise

/** One sample of the bike as the gate sees it. */
data class RideSample(
    /** True while a real (or simulated) bike is connected and sending cadence. */
    val live: Boolean,
    val rpm: Float,
    /** The resistance knob, 0..100. */
    val resistance: Float,
)

/**
 * Decides, a few times a second, whether the video may play: it plays while the rider stays at or
 * above the program's target cadence and resistance.
 *
 * - **Starting.** The video waits until the rider first reaches the target.
 * - **Riding.** At or above target: the video plays.
 * - **Slipping.** Below target for less than [graceMs]: the video keeps playing and the HUD warns.
 *   The bike reports about once a second and resistance two samples late, so a single low sample
 *   must not stop the video.
 * - **Held.** Below target for [graceMs] or more, or no bike: the video is paused until the rider
 *   is back at target.
 *
 * The program runs on video time ([Program]), so while the video is held the target holds too.
 * Not thread-safe: call it from one thread (the player's main thread).
 */
class RideGate(
    val program: Program,
    private val graceMs: Long = DEFAULT_GRACE_MS,
    private val rampMs: Long = Program.DEFAULT_RAMP_MS,
) {
    enum class Phase { STARTING, RIDING, SLIPPING, HELD }

    /** Why the gate is not simply open; what the HUD tells the rider. */
    enum class Shortfall { NONE, NO_BIKE, CADENCE, RESISTANCE, BOTH }

    data class Status(
        val phase: Phase,
        val shortfall: Shortfall,
        val target: Target,
        val segment: Segment,
        val segmentIndex: Int,
        /** Milliseconds left in the current segment of video. */
        val segmentRemainingMs: Long,
        /** The segment coming up, or null at the end. */
        val next: Segment?,
        /** Milliseconds until the video stops, while [Phase.SLIPPING]; 0 otherwise. */
        val graceRemainingMs: Long,
        val sample: RideSample,
    ) {
        /** May the video play? */
        val open: Boolean get() = phase == Phase.RIDING || phase == Phase.SLIPPING
    }

    private var phase = Phase.STARTING
    private var belowSinceMs = -1L

    /** Wall-clock milliseconds spent with the video playing at target, and held. For the end-of-ride summary. */
    var ridingMs = 0L
        private set
    var heldMs = 0L
        private set
    private var lastNowMs = -1L

    /**
     * Feeds one sample. [nowMs] is a monotonic wall clock (for the grace period); [positionMs] is
     * the video position (for the target).
     */
    fun update(nowMs: Long, positionMs: Long, sample: RideSample): Status {
        val target = program.targetAt(positionMs, rampMs)
        val shortfall = shortfallOf(sample, target)

        val previous = phase
        phase = when {
            shortfall == Shortfall.NONE -> Phase.RIDING
            previous == Phase.STARTING || previous == Phase.HELD -> previous
            // No bike at all is not a slip of the legs: stop straight away.
            shortfall == Shortfall.NO_BIKE -> Phase.HELD
            else -> {
                if (previous == Phase.RIDING) belowSinceMs = nowMs
                if (nowMs - belowSinceMs >= graceMs) Phase.HELD else Phase.SLIPPING
            }
        }
        if (phase != Phase.SLIPPING) belowSinceMs = -1L

        if (lastNowMs >= 0) {
            val dt = (nowMs - lastNowMs).coerceIn(0L, 5_000L)
            when (previous) {
                Phase.RIDING, Phase.SLIPPING -> ridingMs += dt
                Phase.HELD -> heldMs += dt
                Phase.STARTING -> Unit
            }
        }
        lastNowMs = nowMs

        val index = program.indexAt(positionMs)
        return Status(
            phase = phase,
            shortfall = shortfall,
            target = target,
            segment = program.segments[index],
            segmentIndex = index,
            segmentRemainingMs = program.remainingInSegmentMs(positionMs),
            next = program.nextAfter(positionMs),
            graceRemainingMs = if (phase == Phase.SLIPPING) (graceMs - (nowMs - belowSinceMs)).coerceAtLeast(0) else 0,
            sample = sample,
        )
    }

    /**
     * Starts over as if the video had just begun, for the next item of a playlist. The rider has
     * to reach the target again before it plays.
     */
    fun restart() {
        phase = Phase.STARTING
        belowSinceMs = -1L
    }

    companion object {
        const val DEFAULT_GRACE_MS = 3_000L

        fun shortfallOf(sample: RideSample, target: Target): Shortfall {
            if (!sample.live) return Shortfall.NO_BIKE
            val slow = sample.rpm < target.rpm
            val light = sample.resistance < target.resistance
            return when {
                slow && light -> Shortfall.BOTH
                slow -> Shortfall.CADENCE
                light -> Shortfall.RESISTANCE
                else -> Shortfall.NONE
            }
        }
    }
}

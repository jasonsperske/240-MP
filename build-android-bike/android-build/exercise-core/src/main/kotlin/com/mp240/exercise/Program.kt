// SPDX-License-Identifier: GPL-3.0-only
package com.mp240.exercise

import kotlin.math.abs
import kotlin.math.max
import kotlin.math.min
import kotlin.math.roundToInt
import kotlin.math.roundToLong

/**
 * A workout laid over a video: consecutive [segments] covering 0 until [lengthMs] of video time.
 *
 * The program runs on the video's clock, not the wall clock. The video stops whenever the rider
 * drops below the target, so the program stops with it, and a rider who stops does not skip ahead.
 *
 * When the video's length is not known (a live stream), the program is built for
 * [UNKNOWN_LENGTH_MS] and repeats ([repeats]).
 */
class Program(val workout: Workout, val difficulty: Difficulty, val segments: List<Segment>, val repeats: Boolean = false) {
    init {
        require(segments.isNotEmpty()) { "a program has at least one segment" }
        require(segments.first().startMs == 0L) { "a program starts at 0" }
        segments.zipWithNext().forEach { (a, b) -> require(a.endMs == b.startMs) { "segments are contiguous" } }
        segments.forEach { require(it.durationMs > 0) { "segments are not empty" } }
    }

    val lengthMs: Long get() = segments.last().endMs

    /** The segment index at video [positionMs]; the last segment past the end (or wraps if [repeats]). */
    fun indexAt(positionMs: Long): Int {
        val p = normalise(positionMs)
        // Few segments (tens): a linear scan is as quick as anything and obviously right.
        val i = segments.indexOfFirst { p in it }
        return if (i >= 0) i else segments.lastIndex
    }

    fun segmentAt(positionMs: Long): Segment = segments[indexAt(positionMs)]

    /** The segment after the one at [positionMs], or null at the end of a program that does not repeat. */
    fun nextAfter(positionMs: Long): Segment? {
        val i = indexAt(positionMs)
        return when {
            i < segments.lastIndex -> segments[i + 1]
            repeats -> segments.first()
            else -> null
        }
    }

    /** Milliseconds from [positionMs] to the end of its segment. */
    fun remainingInSegmentMs(positionMs: Long): Long = segmentAt(positionMs).endMs - normalise(positionMs).coerceAtMost(lengthMs)

    /**
     * The target the rider is held to at [positionMs]. For the first [rampMs] of a segment that asks
     * for more than the one before it, each of cadence and resistance stays at the lower of the two,
     * so the rider has time to turn the knob and spin up before the video stops on them.
     */
    fun targetAt(positionMs: Long, rampMs: Long = DEFAULT_RAMP_MS): Target {
        val i = indexAt(positionMs)
        val seg = segments[i]
        val previous = when {
            i > 0 -> segments[i - 1]
            repeats && normalise(positionMs) != positionMs -> segments.last()
            else -> null
        } ?: return seg.target
        if (normalise(positionMs) - seg.startMs >= rampMs) return seg.target
        return Target(min(seg.target.rpm, previous.target.rpm), min(seg.target.resistance, previous.target.resistance))
    }

    private fun normalise(positionMs: Long): Long {
        val p = max(0L, positionMs)
        return if (repeats && lengthMs > 0) p % lengthMs else p
    }

    companion object {
        /** How long a rider has to reach a higher target at the start of a segment. */
        const val DEFAULT_RAMP_MS = 10_000L

        /** Program length assumed when the video's length is unknown; the program then repeats. */
        const val UNKNOWN_LENGTH_MS = 45 * 60_000L

        /** Videos shorter than this get a [Workout.STEADY] ride, whatever the workout: there is no room for structure. */
        const val MIN_STRUCTURED_MS = 3 * 60_000L

        /** No segment of a structured program is shorter than this, so targets don't flicker by. */
        const val MIN_SEGMENT_MS = 20_000L

        /**
         * Lays [workout] at [difficulty] over a video of [durationMs] (0 or less when unknown).
         * The same inputs always give the same program.
         */
        fun build(workout: Workout, difficulty: Difficulty, durationMs: Long): Program {
            val unknown = durationMs <= 0
            val length = if (unknown) UNKNOWN_LENGTH_MS else durationMs
            val effective = if (length < MIN_STRUCTURED_MS) Workout.STEADY else workout
            val plan = when (effective) {
                Workout.STEADY -> listOf(Planned(Effort.STEADY, 1.0))
                Workout.INTERVALS -> framed(length, ::intervals)
                Workout.HILLS -> framed(length, ::hills)
                Workout.SPIN_CLASS -> framed(length, ::spinClass)
            }
            return Program(workout, difficulty, layOut(length, plan, difficulty), repeats = unknown)
        }

        // ── Planning ───────────────────────────────────────────────────────────────────────────

        /** A planned piece: an effort, its share of the time, and any extra on top of the effort's offsets. */
        private data class Planned(val effort: Effort, val weight: Double, val extra: Extra = Extra(0, 0))

        private data class Extra(val rpm: Int, val resistance: Int)

        /** Warm-up and cool-down around a middle section planned by [middle] (given the middle's length). */
        private fun framed(lengthMs: Long, middle: (Long) -> List<Planned>): List<Planned> {
            val warm = (lengthMs * 0.10).roundToLong().coerceIn(30_000L, 5 * 60_000L)
            val cool = (lengthMs * 0.08).roundToLong().coerceIn(30_000L, 4 * 60_000L)
            val mid = lengthMs - warm - cool
            return listOf(Planned(Effort.WARMUP, warm.toDouble())) +
                middle(mid).let { pieces -> scale(pieces, mid.toDouble()) } +
                Planned(Effort.COOLDOWN, cool.toDouble())
        }

        /** Rescales [pieces]' weights so they add up to [total]. */
        private fun scale(pieces: List<Planned>, total: Double): List<Planned> {
            val sum = pieces.sumOf { it.weight }
            return pieces.map { it.copy(weight = it.weight * total / sum) }
        }

        /** One-minute pushes and one-minute recoveries, as many pairs as fit. */
        private fun intervals(middleMs: Long): List<Planned> {
            val pairs = max(1, (middleMs / 120_000.0).roundToInt())
            return (0 until pairs).flatMap { listOf(Planned(Effort.PUSH, 1.0), Planned(Effort.RECOVER, 1.0)) }
        }

        /**
         * Steps of about 90 s climbing to a peak and back down. A long video gets several hills of
         * about ten steps each, with a recovery between them. Step levels run 1 (the foot of the
         * hill) to [HILL_LEVELS] (the summit).
         */
        private fun hills(middleMs: Long): List<Planned> {
            val steps = max(3, (middleMs / 90_000.0).roundToInt())
            val hillCount = max(1, (steps / 10.0).roundToInt())
            val pieces = mutableListOf<Planned>()
            for (h in 0 until hillCount) {
                // Share the steps out evenly, the recovery between hills included.
                val share = steps * (h + 1) / hillCount - steps * h / hillCount
                val climbSteps = if (h < hillCount - 1) max(1, share - 1) else share
                for (k in 0 until climbSteps) {
                    val level = hillLevel(k, climbSteps)
                    // Five knob points a step; cadence eases by 3 rpm a step as the hill steepens.
                    // Level 3 is the CLIMB effort as it stands.
                    pieces += Planned(Effort.CLIMB, 1.0, Extra(rpm = 3 * (3 - level), resistance = 5 * (level - 3)))
                }
                if (h < hillCount - 1) pieces += Planned(Effort.RECOVER, 1.0)
            }
            return pieces
        }

        private const val HILL_LEVELS = 5

        /** Step [k] of an [n]-step hill: 1 at the ends rising to [HILL_LEVELS] in the middle. */
        internal fun hillLevel(k: Int, n: Int): Int {
            if (n <= 1) return HILL_LEVELS
            val t = k.toDouble() / (n - 1)               // 0..1 along the hill
            val tri = 1.0 - abs(2.0 * t - 1.0)            // 0 at the ends, 1 at the summit
            return 1 + (tri * (HILL_LEVELS - 1)).roundToInt()
        }

        /**
         * Sets of about six minutes: flat road, a climb, a push, a sprint, recovery. Each set adds five
         * points of resistance to the climb and the push until the middle set, then eases back.
         */
        private fun spinClass(middleMs: Long): List<Planned> {
            val sets = max(1, (middleMs / 360_000.0).roundToInt())
            val peak = (sets - 1) / 2.0
            return (0 until sets).flatMap { s ->
                val build = (5 * (peak - abs(s - peak))).roundToInt().coerceAtMost(15)
                listOf(
                    Planned(Effort.FLAT, 1.5),
                    Planned(Effort.CLIMB, 1.5, Extra(0, build)),
                    Planned(Effort.RECOVER, 0.75),
                    Planned(Effort.PUSH, 1.0, Extra(0, build)),
                    Planned(Effort.SPRINT, 0.5),
                    Planned(Effort.RECOVER, 0.75),
                )
            }
        }

        // ── Layout ─────────────────────────────────────────────────────────────────────────────

        /**
         * Turns planned weights into whole-millisecond segments covering exactly [lengthMs]. Pieces
         * shorter than [MIN_SEGMENT_MS] are folded into the piece before them (the warm-up never is),
         * and neighbouring pieces with the same target are merged.
         */
        private fun layOut(lengthMs: Long, plan: List<Planned>, difficulty: Difficulty): List<Segment> {
            val total = plan.sumOf { it.weight }
            val raw = mutableListOf<Segment>()
            var acc = 0.0
            var start = 0L
            plan.forEachIndexed { i, piece ->
                acc += piece.weight
                val end = if (i == plan.lastIndex) lengthMs else (acc / total * lengthMs).roundToLong()
                if (end <= start) return@forEachIndexed
                val target = Target.clamped(
                    difficulty.baseRpm + piece.effort.rpmOffset + piece.extra.rpm,
                    difficulty.baseResistance + piece.effort.resistanceOffset + piece.extra.resistance,
                )
                raw += Segment(start, end, piece.effort, target)
                start = end
            }
            val merged = mutableListOf<Segment>()
            for (seg in raw) {
                val last = merged.lastOrNull()
                when {
                    last == null -> merged += seg
                    last.effort == seg.effort && last.target == seg.target ->
                        merged[merged.lastIndex] = last.copy(endMs = seg.endMs)
                    seg.durationMs < MIN_SEGMENT_MS && raw.size > 1 && seg !== raw.last() ->
                        merged[merged.lastIndex] = last.copy(endMs = seg.endMs)
                    else -> merged += seg
                }
            }
            return merged
        }
    }
}

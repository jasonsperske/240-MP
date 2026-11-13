// SPDX-License-Identifier: GPL-3.0-only
package com.mp240.exercise

/**
 * How hard the rider has to work. Each level is a base cadence and a base resistance; a [Workout]
 * holds them steady (Steady) or moves around them over the length of the video.
 *
 * Resistance is the Peloton knob's 0..100 scale. For reference, Peloton instructors call
 * 25-35 a flat road and 45-60 a climb.
 */
enum class Difficulty(val label: String, val baseRpm: Int, val baseResistance: Int) {
    EASY("Easy", 60, 20),
    MODERATE("Moderate", 70, 30),
    HARD("Hard", 80, 40),
    EXPERT("Expert", 90, 50);

    companion object {
        /** The level whose label matches [label], ignoring case; [MODERATE] for anything else. */
        fun fromLabel(label: String?): Difficulty =
            entries.firstOrNull { it.label.equals(label?.trim(), ignoreCase = true) } ?: MODERATE
    }
}

/** The shape of the ride over the length of the video. */
enum class Workout(val label: String) {
    /** The difficulty's base cadence and resistance, held for the whole video. */
    STEADY("Steady"),

    /** Warm-up, then one-minute pushes alternating with one-minute recoveries, then a cool-down. */
    INTERVALS("Intervals"),

    /** Warm-up, then resistance stepping up to a peak and back down (cadence easing as it rises), then a cool-down. */
    HILLS("Hills"),

    /** A spin class: warm-up, sets of flat road, climbs, a sprint and recoveries that build in intensity, then a cool-down. */
    SPIN_CLASS("Spin Class");

    companion object {
        /** The workout whose label matches [label], ignoring case; [STEADY] for anything else. */
        fun fromLabel(label: String?): Workout =
            entries.firstOrNull { it.label.equals(label?.trim(), ignoreCase = true) } ?: STEADY
    }
}

/**
 * The kind of effort a segment asks for, as offsets from the difficulty's base. Resistance offsets
 * are in knob points (as spin instructors call them: "add ten"), cadence offsets in rpm.
 */
enum class Effort(val label: String, val rpmOffset: Int, val resistanceOffset: Int) {
    WARMUP("WARM UP", -10, -10),
    STEADY("STEADY", 0, 0),
    FLAT("FLAT ROAD", 0, 0),
    PUSH("PUSH", 10, 10),
    CLIMB("CLIMB", -15, 15),
    SPRINT("SPRINT", 20, 0),
    RECOVER("RECOVER", -10, -10),
    COOLDOWN("COOL DOWN", -15, -15),
}

/** Minimum cadence and resistance; the video plays while the rider is at or above both. */
data class Target(val rpm: Int, val resistance: Int) {
    fun isMetBy(rpm: Float, resistance: Float): Boolean = rpm >= this.rpm && resistance >= this.resistance

    companion object {
        const val MIN_RPM = 40
        const val MAX_RPM = 120
        const val MIN_RESISTANCE = 5
        const val MAX_RESISTANCE = 100

        /** A target clamped to what a rider can actually hold on the bike. */
        fun clamped(rpm: Int, resistance: Int) = Target(
            rpm.coerceIn(MIN_RPM, MAX_RPM),
            resistance.coerceIn(MIN_RESISTANCE, MAX_RESISTANCE),
        )
    }
}

/** One stretch of the program, from [startMs] (inclusive) to [endMs] (exclusive) of video time. */
data class Segment(val startMs: Long, val endMs: Long, val effort: Effort, val target: Target) {
    val durationMs: Long get() = endMs - startMs

    operator fun contains(positionMs: Long): Boolean = positionMs in startMs until endMs
}

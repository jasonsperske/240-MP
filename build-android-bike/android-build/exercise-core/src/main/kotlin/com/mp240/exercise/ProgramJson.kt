// SPDX-License-Identifier: GPL-3.0-only
package com.mp240.exercise

/**
 * The program as JSON, for the QML side (the exercise module's preview). Hand-written so this
 * module needs nothing but the Kotlin standard library:
 *
 * ```
 * {"workout":"Hills","difficulty":"Hard","lengthMs":1800000,"repeats":false,
 *  "segments":[{"startMs":0,"endMs":180000,"label":"WARM UP","rpm":70,"resistance":30}, ...]}
 * ```
 */
fun Program.toJson(): String = buildString {
    append("{\"workout\":\"").append(workout.label)
    append("\",\"difficulty\":\"").append(difficulty.label)
    append("\",\"lengthMs\":").append(lengthMs)
    append(",\"repeats\":").append(repeats)
    append(",\"segments\":[")
    segments.forEachIndexed { i, s ->
        if (i > 0) append(',')
        append("{\"startMs\":").append(s.startMs)
        append(",\"endMs\":").append(s.endMs)
        append(",\"label\":\"").append(s.effort.label)
        append("\",\"rpm\":").append(s.target.rpm)
        append(",\"resistance\":").append(s.target.resistance)
        append('}')
    }
    append("]}")
}

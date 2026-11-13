// SPDX-License-Identifier: GPL-3.0-only
package com.mp240.exercise

import kotlin.test.Test
import kotlin.test.assertEquals
import kotlin.test.assertNull
import kotlin.test.assertTrue

class ProgramTest {
    private val minute = 60_000L

    private fun assertWellFormed(p: Program, length: Long) {
        assertEquals(0L, p.segments.first().startMs)
        assertEquals(length, p.lengthMs)
        p.segments.zipWithNext().forEach { (a, b) -> assertEquals(a.endMs, b.startMs) }
        p.segments.forEach { s ->
            assertTrue(s.target.rpm in Target.MIN_RPM..Target.MAX_RPM, "rpm in range: $s")
            assertTrue(s.target.resistance in Target.MIN_RESISTANCE..Target.MAX_RESISTANCE, "resistance in range: $s")
        }
    }

    @Test
    fun `steady holds the difficulty's base for the whole video`() {
        for (d in Difficulty.entries) {
            val p = Program.build(Workout.STEADY, d, 42 * minute)
            assertWellFormed(p, 42 * minute)
            assertEquals(1, p.segments.size)
            assertEquals(Target(d.baseRpm, d.baseResistance), p.targetAt(20 * minute))
        }
    }

    @Test
    fun `every workout covers the video exactly, from a short clip to a feature film`() {
        for (w in Workout.entries) for (d in Difficulty.entries) {
            for (len in listOf(30_000L, 3 * minute, 5 * minute + 17, 22 * minute, 45 * minute, 2 * 60 * minute + 31_000)) {
                val p = Program.build(w, d, len)
                assertWellFormed(p, len)
            }
        }
    }

    @Test
    fun `structured workouts warm up, vary, and cool down`() {
        for (w in listOf(Workout.INTERVALS, Workout.HILLS, Workout.SPIN_CLASS)) {
            val p = Program.build(w, Difficulty.MODERATE, 30 * minute)
            assertEquals(Effort.WARMUP, p.segments.first().effort, "$w")
            assertEquals(Effort.COOLDOWN, p.segments.last().effort, "$w")
            assertTrue(p.segments.map { it.target }.toSet().size >= 3, "$w varies its targets")
            assertTrue(p.segments.all { it.durationMs >= Program.MIN_SEGMENT_MS }, "$w has no flicker segments")
        }
    }

    @Test
    fun `videos too short for structure get a steady ride`() {
        val p = Program.build(Workout.SPIN_CLASS, Difficulty.HARD, 2 * minute)
        assertEquals(1, p.segments.size)
        assertEquals(Target(80, 40), p.segments.single().target)
    }

    @Test
    fun `intervals alternate push and recover about once a minute`() {
        val p = Program.build(Workout.INTERVALS, Difficulty.MODERATE, 30 * minute)
        val middle = p.segments.drop(1).dropLast(1)
        assertTrue(middle.size >= 20)
        middle.zipWithNext().forEach { (a, b) -> assertTrue(a.effort != b.effort) }
        middle.forEach { assertTrue(it.durationMs in 45_000L..75_000L, "about a minute: ${it.durationMs}") }
        val push = middle.first { it.effort == Effort.PUSH }.target
        assertEquals(Target(80, 40), push)
    }

    @Test
    fun `hills climb in resistance to a summit and come back down`() {
        val p = Program.build(Workout.HILLS, Difficulty.MODERATE, 20 * minute)
        val climb = p.segments.filter { it.effort == Effort.CLIMB }.map { it.target.resistance }
        val summit = climb.indexOf(climb.max())
        assertTrue(summit in 1 until climb.lastIndex, "summit in the middle: $climb")
        climb.take(summit + 1).zipWithNext().forEach { (a, b) -> assertTrue(b >= a, "rising: $climb") }
        climb.drop(summit).zipWithNext().forEach { (a, b) -> assertTrue(b <= a, "falling: $climb") }
        // Cadence eases as resistance rises.
        val steepest = p.segments.filter { it.effort == Effort.CLIMB }.maxBy { it.target.resistance }
        val gentlest = p.segments.filter { it.effort == Effort.CLIMB }.minBy { it.target.resistance }
        assertTrue(steepest.target.rpm < gentlest.target.rpm)
    }

    @Test
    fun `a long hills ride has several hills with recoveries between`() {
        val p = Program.build(Workout.HILLS, Difficulty.EASY, 60 * minute)
        assertTrue(p.segments.count { it.effort == Effort.RECOVER } >= 2)
    }

    @Test
    fun `hill levels rise to the summit and fall`() {
        assertEquals(listOf(1, 2, 3, 4, 5, 4, 3, 2, 1), (0 until 9).map { Program.hillLevel(it, 9) })
        assertEquals(listOf(5), listOf(Program.hillLevel(0, 1)))
        assertEquals(listOf(1, 5, 1), (0 until 3).map { Program.hillLevel(it, 3) })
    }

    @Test
    fun `a spin class builds resistance toward the middle sets`() {
        val p = Program.build(Workout.SPIN_CLASS, Difficulty.MODERATE, 45 * minute)
        val climbs = p.segments.filter { it.effort == Effort.CLIMB }.map { it.target.resistance }
        assertTrue(climbs.size >= 5, "several sets: $climbs")
        assertTrue(climbs.max() > climbs.first() && climbs.max() > climbs.last(), "builds then eases: $climbs")
        assertTrue(p.segments.any { it.effort == Effort.SPRINT && it.target.rpm == 90 })
    }

    @Test
    fun `the same inputs give the same program`() {
        val a = Program.build(Workout.SPIN_CLASS, Difficulty.EXPERT, 37 * minute)
        val b = Program.build(Workout.SPIN_CLASS, Difficulty.EXPERT, 37 * minute)
        assertEquals(a.segments, b.segments)
    }

    @Test
    fun `a rising target eases in over the ramp`() {
        val p = Program.build(Workout.INTERVALS, Difficulty.MODERATE, 30 * minute)
        val push = p.segments.first { it.effort == Effort.PUSH && p.segments.indexOf(it) > 1 }
        val before = p.segments[p.segments.indexOf(push) - 1].target
        assertEquals(Target(minOf(before.rpm, push.target.rpm), minOf(before.resistance, push.target.resistance)),
            p.targetAt(push.startMs + 5_000))
        assertEquals(push.target, p.targetAt(push.startMs + Program.DEFAULT_RAMP_MS))
        // A falling target applies at once.
        val recover = p.segments[p.segments.indexOf(push) + 1]
        assertEquals(recover.target, p.targetAt(recover.startMs))
    }

    @Test
    fun `unknown length repeats a 45 minute program`() {
        val p = Program.build(Workout.SPIN_CLASS, Difficulty.MODERATE, 0)
        assertTrue(p.repeats)
        assertEquals(Program.UNKNOWN_LENGTH_MS, p.lengthMs)
        assertEquals(p.segmentAt(5 * minute), p.segmentAt(5 * minute + p.lengthMs))
        assertEquals(p.segments.first(), p.nextAfter(p.lengthMs - 1))
    }

    @Test
    fun `past the end stays on the last segment and has no next`() {
        val p = Program.build(Workout.HILLS, Difficulty.MODERATE, 20 * minute)
        assertEquals(p.segments.last(), p.segmentAt(21 * minute))
        assertNull(p.nextAfter(21 * minute))
    }

    @Test
    fun `labels parse loosely and fall back to defaults`() {
        assertEquals(Workout.SPIN_CLASS, Workout.fromLabel("spin class"))
        assertEquals(Workout.STEADY, Workout.fromLabel(null))
        assertEquals(Difficulty.EXPERT, Difficulty.fromLabel(" Expert "))
        assertEquals(Difficulty.MODERATE, Difficulty.fromLabel("bogus"))
    }

    @Test
    fun `json lists every segment`() {
        val p = Program.build(Workout.INTERVALS, Difficulty.EASY, 10 * minute)
        val json = p.toJson()
        assertTrue(json.startsWith("{\"workout\":\"Intervals\",\"difficulty\":\"Easy\",\"lengthMs\":600000,\"repeats\":false"))
        assertEquals(p.segments.size, Regex("\"startMs\"").findAll(json).count())
    }
}

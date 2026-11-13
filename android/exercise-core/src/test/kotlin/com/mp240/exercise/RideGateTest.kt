// SPDX-License-Identifier: GPL-3.0-only
package com.mp240.exercise

import com.mp240.exercise.RideGate.Phase
import com.mp240.exercise.RideGate.Shortfall
import kotlin.test.Test
import kotlin.test.assertEquals
import kotlin.test.assertFalse
import kotlin.test.assertTrue

class RideGateTest {
    private val steady = Program.build(Workout.STEADY, Difficulty.MODERATE, 30 * 60_000L) // 70 rpm, 30 resistance
    private fun riding(rpm: Float = 75f, res: Float = 35f) = RideSample(live = true, rpm = rpm, resistance = res)

    @Test
    fun `the video waits for the rider to reach the target`() {
        val gate = RideGate(steady)
        val s0 = gate.update(0, 0, riding(rpm = 0f, res = 35f))
        assertEquals(Phase.STARTING, s0.phase)
        assertFalse(s0.open)
        assertEquals(Shortfall.CADENCE, s0.shortfall)
        // Still waiting long after the grace period: starting is not slipping.
        assertEquals(Phase.STARTING, gate.update(10_000, 0, riding(rpm = 50f)).phase)
        val s1 = gate.update(11_000, 0, riding())
        assertEquals(Phase.RIDING, s1.phase)
        assertTrue(s1.open)
    }

    @Test
    fun `a short dip keeps playing, a long one holds the video`() {
        val gate = RideGate(steady, graceMs = 3_000)
        gate.update(0, 0, riding())
        val dip = gate.update(1_000, 1_000, riding(rpm = 60f))
        assertEquals(Phase.SLIPPING, dip.phase)
        assertTrue(dip.open)
        assertEquals(3_000, dip.graceRemainingMs)
        assertEquals(Phase.SLIPPING, gate.update(3_500, 3_500, riding(rpm = 60f)).phase)
        val held = gate.update(4_000, 4_000, riding(rpm = 60f))
        assertEquals(Phase.HELD, held.phase)
        assertFalse(held.open)
        // Back at target: plays again straight away.
        assertEquals(Phase.RIDING, gate.update(5_000, 4_000, riding()).phase)
    }

    @Test
    fun `recovering within the grace period resets it`() {
        val gate = RideGate(steady, graceMs = 3_000)
        gate.update(0, 0, riding())
        gate.update(1_000, 1_000, riding(res = 10f))
        gate.update(2_000, 2_000, riding())
        val again = gate.update(3_000, 3_000, riding(res = 10f))
        assertEquals(Phase.SLIPPING, again.phase)
        assertEquals(Shortfall.RESISTANCE, again.shortfall)
        assertEquals(Phase.SLIPPING, gate.update(5_500, 5_500, riding(res = 10f)).phase)
    }

    @Test
    fun `losing the bike holds the video at once`() {
        val gate = RideGate(steady)
        gate.update(0, 0, riding())
        val s = gate.update(500, 500, RideSample(live = false, rpm = 0f, resistance = 0f))
        assertEquals(Phase.HELD, s.phase)
        assertEquals(Shortfall.NO_BIKE, s.shortfall)
    }

    @Test
    fun `both short reports both`() {
        assertEquals(Shortfall.BOTH, RideGate.shortfallOf(riding(rpm = 1f, res = 1f), Target(70, 30)))
        assertEquals(Shortfall.NONE, RideGate.shortfallOf(riding(rpm = 70f, res = 30f), Target(70, 30)))
    }

    @Test
    fun `the target follows video time through the program`() {
        val p = Program.build(Workout.INTERVALS, Difficulty.MODERATE, 30 * 60_000L)
        val gate = RideGate(p)
        val push = p.segments.first { it.effort == Effort.PUSH }
        val s = gate.update(0, push.startMs + Program.DEFAULT_RAMP_MS, riding(rpm = 100f, res = 60f))
        assertEquals(push.target, s.target)
        assertEquals(push, s.segment)
        assertEquals(push.durationMs - Program.DEFAULT_RAMP_MS, s.segmentRemainingMs)
        assertEquals(p.segments[s.segmentIndex + 1], s.next)
    }

    @Test
    fun `time riding and held is tallied`() {
        val gate = RideGate(steady, graceMs = 1_000)
        gate.update(0, 0, riding())
        gate.update(1_000, 1_000, riding())          // +1 s riding
        gate.update(2_000, 2_000, riding(rpm = 0f))  // +1 s riding (slipping counts)
        gate.update(3_000, 2_000, riding(rpm = 0f))  // +1 s slipping, now held
        gate.update(4_000, 2_000, riding(rpm = 0f))  // +1 s held
        assertEquals(3_000, gate.ridingMs)
        assertEquals(1_000, gate.heldMs)
    }

    @Test
    fun `restart makes the rider reach the target again`() {
        val gate = RideGate(steady)
        gate.update(0, 0, riding())
        gate.restart()
        assertEquals(Phase.STARTING, gate.update(100, 0, riding(rpm = 10f)).phase)
    }
}

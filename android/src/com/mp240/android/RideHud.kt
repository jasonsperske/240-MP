// SPDX-License-Identifier: GPL-3.0-only
package com.mp240.android

import android.content.Context
import android.graphics.Canvas
import android.graphics.Color
import android.graphics.Paint
import android.graphics.RectF
import android.graphics.Typeface
import android.os.SystemClock
import android.view.MotionEvent
import android.view.View
import com.mp240.exercise.Program
import com.mp240.exercise.RideGate
import com.mp240.exercise.RideGate.Phase
import com.mp240.exercise.RideGate.Shortfall
import com.mp240.exercise.Target
import kotlin.math.max
import kotlin.math.min

/**
 * The exercise overlay, drawn in 240-MP's on-screen-display style (VCR font, the "Video 1" blue).
 * Two [Style]s, picked with the exercise module's Stats View setting:
 *
 * - [Style.DETAILED]: along the top, the ride's profile (one bar per segment, as tall as its
 *   resistance, with the playhead), and a panel with the segment, its time left, and the rider's
 *   cadence and resistance against the target, with bars;
 * - [Style.MINIMAL]: one slim bar with the time left and the two numbers against their targets.
 *
 * Numbers are green at or above the target, amber in the grace period, red below. The panel sits
 * in the [Corner] set by Stats Corner. When the video is held, a card in the middle says what to do.
 *
 * The view covers the screen but takes no taps except on the "no bike" card ([onCardTap]), so the
 * player's controls underneath stay usable.
 *
 * Sizes follow the view's height, as the QML side's do (`root.sh`), so it reads the same at
 * 1080p on the bike and on a small emulator.
 */
class RideHud(context: Context, val typeface: Typeface) : View(context) {
    enum class Style(val label: String) {
        DETAILED("Detailed"), MINIMAL("Minimal");

        companion object {
            fun fromLabel(label: String) = values().firstOrNull { it.label.equals(label.trim(), ignoreCase = true) } ?: DETAILED
        }
    }

    enum class Corner(val label: String, val top: Boolean, val left: Boolean) {
        TOP_LEFT("Top Left", true, true), TOP_RIGHT("Top Right", true, false),
        BOTTOM_LEFT("Bottom Left", false, true), BOTTOM_RIGHT("Bottom Right", false, false);

        companion object {
            fun fromLabel(label: String) = values().firstOrNull { it.label.equals(label.trim(), ignoreCase = true) } ?: TOP_LEFT
        }
    }

    var style = Style.DETAILED
        set(value) { field = value; invalidate() }
    var corner = Corner.TOP_LEFT
        set(value) { field = value; invalidate() }

    /** While the player's controls show, a panel in a bottom corner moves up clear of the seek bar. */
    var controlsShown = false
        set(value) { field = value; invalidate() }

    /** A tap on the "no bike" card: the touch way to watch without exercise. */
    var onCardTap: (() -> Unit)? = null

    private val cardRect = RectF()
    private var cardShown = false

    private var status: RideGate.Status? = null
    private var program: Program? = null
    private var positionMs = 0L
    private var bikeAbsent = false
    private var simulated = false

    private val text = Paint(Paint.ANTI_ALIAS_FLAG).apply { this.typeface = this@RideHud.typeface; color = WHITE }
    private val fill = Paint(Paint.ANTI_ALIAS_FLAG)
    private val rect = RectF()

    fun show(status: RideGate.Status, program: Program, positionMs: Long, bikeAbsent: Boolean, simulated: Boolean) {
        this.status = status
        this.program = program
        this.positionMs = positionMs
        this.bikeAbsent = bikeAbsent
        this.simulated = simulated
        visibility = VISIBLE
        invalidate()
    }

    override fun onDraw(canvas: Canvas) {
        val s = status ?: return
        val p = program ?: return
        val u = height / 100f // one percent of the screen's height
        if (style == Style.DETAILED) {
            drawProfile(canvas, p, u)
            drawPanel(canvas, s, p, u)
        } else {
            drawBar(canvas, s, p, u)
        }
        cardShown = !s.open
        if (cardShown) drawCard(canvas, s, u) else cardRect.setEmpty()
    }

    override fun onTouchEvent(event: MotionEvent): Boolean {
        val s = status
        val onCard = cardShown && s?.shortfall == Shortfall.NO_BIKE && cardRect.contains(event.x, event.y)
        if (!onCard) return false // let the tap reach the player's controls
        if (event.actionMasked == MotionEvent.ACTION_UP) onCardTap?.invoke()
        return true
    }

    /** Where a [w] by [h] panel goes for [corner]: its top-left point. */
    private fun place(w: Float, h: Float, u: Float): Pair<Float, Float> {
        val margin = 2f * u
        val x = if (corner.left) margin else width - w - margin
        val y = when {
            corner.top && style == Style.DETAILED -> 7.5f * u // below the profile
            corner.top -> margin
            controlsShown -> height - h - 14f * u // above the seek bar and time
            else -> height - h - margin
        }
        return x to y
    }

    /** [Style.MINIMAL]: "0:54  RPM 75/70  RES 35/30" in one bar, with the ride's progress along its foot. */
    private fun drawBar(canvas: Canvas, s: RideGate.Status, p: Program, u: Float) {
        text.textSize = 3.6f * u
        val gap = 2.5f * u
        val pad = 2f * u
        val blink = s.segmentRemainingMs < 5_000 && (SystemClock.uptimeMillis() / 400) % 2 == 0L
        val time = (if (showNext(s)) nextArrow(s) + " " else "") + clock(s.segmentRemainingMs)
        val cadence = String.format("RPM %d/%d", Math.round(s.sample.rpm), s.target.rpm)
        val resistance = String.format("RES %d/%d", Math.round(s.sample.resistance), s.target.resistance)
        val w = pad * 2 + text.measureText(time) + gap + text.measureText(cadence) + gap + text.measureText(resistance)
        val h = 6.5f * u
        val (left, top) = place(w, h, u)
        fill.color = PANEL
        rect.set(left, top, left + w, top + h)
        canvas.drawRect(rect, fill)

        val y = top + 4.6f * u
        var x = left + pad
        text.color = if (showNext(s) && !blink) ACCENT else WHITE
        canvas.drawText(time, x, y, text)
        x += text.measureText(time) + gap
        text.color = metricColour(s, slow = s.shortfall == Shortfall.CADENCE || s.shortfall == Shortfall.BOTH)
        canvas.drawText(cadence, x, y, text)
        x += text.measureText(cadence) + gap
        text.color = metricColour(s, slow = s.shortfall == Shortfall.RESISTANCE || s.shortfall == Shortfall.BOTH)
        canvas.drawText(resistance, x, y, text)

        // The ride's progress, as a thin line along the bar's foot.
        val pos = if (p.repeats) positionMs % p.lengthMs else min(positionMs, p.lengthMs)
        val done = if (p.lengthMs > 0) pos / p.lengthMs.toFloat() else 0f
        fill.color = TERTIARY
        canvas.drawRect(left, top + h - 0.6f * u, left + w, top + h, fill)
        fill.color = ACCENT
        canvas.drawRect(left, top + h - 0.6f * u, left + w * done, top + h, fill)
    }

    private fun metricColour(s: RideGate.Status, slow: Boolean) = when {
        s.shortfall == Shortfall.NO_BIKE -> TERTIARY
        !slow -> GOOD
        s.phase == Phase.SLIPPING -> WARN
        else -> BAD
    }

    private fun nextArrow(s: RideGate.Status): String {
        val next = s.next ?: return "►"
        return when {
            next.target.resistance > s.segment.target.resistance || next.target.rpm > s.segment.target.rpm -> "▲"
            next.target.resistance < s.segment.target.resistance || next.target.rpm < s.segment.target.rpm -> "▼"
            else -> "►"
        }
    }

    /** The ride's shape across the top: bar height is resistance; past segments are dimmed. */
    private fun drawProfile(canvas: Canvas, p: Program, u: Float) {
        val top = 0f
        val h = 5.5f * u
        fill.color = PANEL
        canvas.drawRect(0f, top, width.toFloat(), top + h, fill)
        val length = p.lengthMs.toFloat()
        val pos = if (p.repeats) positionMs % p.lengthMs else min(positionMs, p.lengthMs)
        for (seg in p.segments) {
            val x0 = seg.startMs / length * width
            val x1 = seg.endMs / length * width
            val barH = h * (0.2f + 0.8f * seg.target.resistance / Target.MAX_RESISTANCE.toFloat())
            fill.color = when {
                pos in seg.startMs until seg.endMs -> ACCENT
                seg.endMs <= pos -> TERTIARY
                else -> SECONDARY
            }
            canvas.drawRect(x0 + 1, top + h - barH, x1 - 1, top + h, fill)
        }
        fill.color = WHITE
        val px = pos / length * width
        canvas.drawRect(px - 0.25f * u, top, px + 0.25f * u, top + h, fill)
    }

    private fun drawPanel(canvas: Canvas, s: RideGate.Status, p: Program, u: Float) {
        val w = 58f * u
        // Mode, segment, RPM, RES, and NEXT when it is coming up; 5.5u a line plus padding.
        val lines = if (showNext(s)) 5 else 4
        val h = (7f + (lines - 1) * 5.5f) * u
        val (left, top) = place(w, h, u)
        fill.color = PANEL
        rect.set(left, top, left + w, top + h)
        canvas.drawRect(rect, fill)

        var y = top + 4.5f * u
        val x = left + 2f * u
        text.textSize = 2.8f * u
        text.color = SECONDARY
        val mode = p.workout.label.uppercase() + " · " + p.difficulty.label.uppercase() + if (simulated) " · SIM" else ""
        canvas.drawText(mode, x, y, text)

        y += 5.5f * u
        text.textSize = 4.6f * u
        text.color = WHITE
        canvas.drawText(s.segment.effort.label, x, y, text)
        val left_ = clock(s.segmentRemainingMs)
        canvas.drawText(left_, left + w - 2f * u - text.measureText(left_), y, text)

        y += 5.5f * u
        drawMetric(canvas, "RPM", s.sample.rpm, s.target.rpm, s, slow = s.shortfall == Shortfall.CADENCE || s.shortfall == Shortfall.BOTH, x, y, w - 4f * u, u)
        y += 5.5f * u
        drawMetric(canvas, "RES", s.sample.resistance, s.target.resistance, s, slow = s.shortfall == Shortfall.RESISTANCE || s.shortfall == Shortfall.BOTH, x, y, w - 4f * u, u)

        if (showNext(s)) {
            val next = s.next!!
            y += 5.5f * u
            text.textSize = 3f * u
            // Blink in the last few seconds before the change.
            val blink = s.segmentRemainingMs < 5_000 && (SystemClock.uptimeMillis() / 400) % 2 == 0L
            text.color = if (blink) WHITE else ACCENT
            val arrow = nextArrow(s)
            canvas.drawText("NEXT $arrow ${next.effort.label} ${next.target.rpm}/${next.target.resistance} IN ${clock(s.segmentRemainingMs)}", x, y, text)
        }
    }

    /** "RPM  84 / 65" with a bar: the target is the tick, the bar is the rider. */
    private fun drawMetric(canvas: Canvas, name: String, value: Float, target: Int, s: RideGate.Status, slow: Boolean, x: Float, y: Float, w: Float, u: Float) {
        val colour = metricColour(s, slow)
        text.textSize = 3.6f * u
        text.color = colour
        val label = String.format("%s %3d / %d", name, Math.round(value), target)
        canvas.drawText(label, x, y, text)

        // Clear of the widest label, "RPM 120 / 120".
        val barX = x + 31f * u
        val barW = w - 31f * u
        val barY = y - 2.6f * u
        val barH = 2.4f * u
        val scale = max(target * 1.5f, 1f)
        fill.color = TERTIARY
        canvas.drawRect(barX, barY, barX + barW, barY + barH, fill)
        fill.color = colour
        canvas.drawRect(barX, barY, barX + barW * min(value / scale, 1f), barY + barH, fill)
        fill.color = WHITE
        val tx = barX + barW * (target / scale)
        canvas.drawRect(tx - 0.2f * u, barY - 0.6f * u, tx + 0.2f * u, barY + barH + 0.6f * u, fill)
    }

    /** The card in the middle while the video is held. */
    private fun drawCard(canvas: Canvas, s: RideGate.Status, u: Float) {
        val (title, lines) = when {
            s.shortfall == Shortfall.NO_BIKE && bikeAbsent ->
                "NO BIKE FOUND" to listOf("THIS DEVICE HAS NO PELOTON SENSOR SERVICE", "PRESS OK OR TAP TO WATCH WITHOUT EXERCISE")
            s.shortfall == Shortfall.NO_BIKE ->
                "WAITING FOR BIKE" to listOf("START PEDALLING TO WAKE THE SENSORS", "PRESS OK OR TAP TO WATCH WITHOUT EXERCISE")
            s.phase == Phase.STARTING ->
                "PEDAL TO PLAY" to listOf("REACH ${s.target.rpm} RPM AT RESISTANCE ${s.target.resistance}") + shortfallLines(s)
            else ->
                "PICK IT UP!" to shortfallLines(s)
        }
        val cx = width / 2f
        val cy = height / 2f
        val boxW = 70f * u
        val boxH = (12f + lines.size * 5f) * u
        fill.color = CARD
        rect.set(cx - boxW, cy - boxH / 2, cx + boxW, cy + boxH / 2)
        canvas.drawRect(rect, fill)
        cardRect.set(rect)

        text.color = if (s.phase == Phase.STARTING || s.shortfall == Shortfall.NO_BIKE) WHITE else BAD
        text.textSize = 7f * u
        var y = rect.top + 9f * u
        canvas.drawText(title, cx - text.measureText(title) / 2, y, text)
        text.color = WHITE
        text.textSize = 3.4f * u
        for (line in lines) {
            y += 5f * u
            canvas.drawText(line, cx - text.measureText(line) / 2, y, text)
        }
    }

    private fun shortfallLines(s: RideGate.Status): List<String> {
        val out = mutableListOf<String>()
        if (s.shortfall == Shortfall.CADENCE || s.shortfall == Shortfall.BOTH) {
            out += "CADENCE ${Math.round(s.sample.rpm)} ▲ ${s.target.rpm} RPM"
        }
        if (s.shortfall == Shortfall.RESISTANCE || s.shortfall == Shortfall.BOTH) {
            out += "RESISTANCE ${Math.round(s.sample.resistance)} ▲ ${s.target.resistance}"
        }
        return out
    }

    private fun showNext(s: RideGate.Status) = s.next != null && s.segmentRemainingMs <= NEXT_WARNING_MS

    private fun clock(ms: Long): String {
        val sec = (ms + 999) / 1000
        return String.format("%d:%02d", sec / 60, sec % 60)
    }

    companion object {
        /** Show what is coming this long before a segment ends. */
        const val NEXT_WARNING_MS = 15_000L

        // The "Video 1" scheme from Main.qml, plus traffic-light status colours.
        private val WHITE = Color.WHITE
        private val SECONDARY = Color.parseColor("#C2BFE4")
        private val TERTIARY = Color.parseColor("#8480C9")
        private val ACCENT = Color.parseColor("#AECFFF")
        private val PANEL = Color.parseColor("#B30A0094")
        private val CARD = Color.parseColor("#E60A0094")
        private val GOOD = Color.parseColor("#7CFC7C")
        private val WARN = Color.parseColor("#FFB000")
        private val BAD = Color.parseColor("#FF5050")
    }
}

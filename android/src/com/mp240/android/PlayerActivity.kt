// SPDX-License-Identifier: GPL-3.0-only
package com.mp240.android

import android.app.Activity
import android.graphics.Color
import android.graphics.Typeface
import android.net.Uri
import android.os.Bundle
import android.os.Handler
import android.os.Looper
import android.os.SystemClock
import android.util.Log
import android.view.Gravity
import android.view.KeyEvent
import android.view.View
import android.view.WindowManager
import android.widget.FrameLayout
import android.widget.TextView
import androidx.media3.common.C
import androidx.media3.common.ForwardingPlayer
import androidx.media3.common.MediaItem
import androidx.media3.common.MimeTypes
import androidx.media3.common.PlaybackException
import androidx.media3.common.Player
import androidx.media3.common.TrackSelectionOverride
import androidx.media3.common.Tracks
import androidx.media3.datasource.DefaultDataSource
import androidx.media3.datasource.DefaultHttpDataSource
import androidx.media3.exoplayer.ExoPlayer
import androidx.media3.exoplayer.source.DefaultMediaSourceFactory
import androidx.media3.ui.PlayerView
import com.mp240.android.smb.SmbHttpServer
import com.mp240.android.smb.SmbLog
import com.mp240.android.smb.SmbOrDefaultDataSource
import com.mp240.exercise.Program
import com.mp240.exercise.RideGate
import dev.soloton.bike.BikePaceSource
import org.videolan.libvlc.util.VLCVideoLayout
import java.io.File

/**
 * Fullscreen video, Android's counterpart of the mpv process the desktop app hands off to. Started
 * by [PlayerBridge.play]; reports progress and its end back to C++ the way MpvController does.
 *
 * In exercise mode a [RideGate] decides whether the video may play: the rider has to hold the
 * program's cadence and resistance, and the video pauses when they drop below for more than a few
 * seconds. [RideHud] shows the target, the rider's numbers and the shape of the ride.
 *
 * Playback is ExoPlayer's. When ExoPlayer can't decode a file (the tablet's Android 7 decoders
 * refuse XviD and DivX AVIs, it has no Theora at all), the same item carries on in [VlcPlayer]
 * from where it was, which decodes them in software; see [fallBackToVlc].
 *
 * Keys (a remote, a gamepad, the Qt side's key map): BACK/ESC stop; OK/ENTER/SPACE play and pause;
 * LEFT/RIGHT seek 10 s. With the simulated bike, UP/DOWN change cadence and [ ] or PAGE UP/DOWN
 * resistance.
 */
class PlayerActivity : Activity() {
    private lateinit var request: PlayerRequest
    private lateinit var exo: ExoPlayer
    /** The player in use: [exo], or the [VlcPlayer] that took over from it. */
    private lateinit var player: Player
    private var vlc: VlcPlayer? = null
    private lateinit var vlcLayout: VLCVideoLayout
    private lateinit var playerView: PlayerView
    private lateinit var hud: RideHud
    private lateinit var skipButton: TextView

    private val handler = Handler(Looper.getMainLooper())
    private var ended = false

    /** What the rider has asked for with play/pause; the gate may still hold the video. */
    private var userWantsPlay = true

    // Exercise mode.
    private var bike: BikePaceSource? = null
    private var simulated: SimulatedBike? = null
    private var gate: RideGate? = null
    private var gateItemIndex = -1
    private var gateDurationMs = Long.MIN_VALUE
    /** Set when the rider chose to watch without a bike after "bike not connected". */
    private var exerciseWaived = false
    private var lastStatus: RideGate.Status? = null

    private val exercising get() = request.exercise.enabled && !exerciseWaived

    private val tick = object : Runnable {
        override fun run() {
            updateGate()
            handler.postDelayed(this, TICK_MS)
        }
    }

    private val report = object : Runnable {
        override fun run() {
            if (!ended) {
                PlayerBridge.nativeProgress(request.session, player.currentPosition.toInt(), durationMs().toInt(), player.currentMediaItemIndex)
            }
            handler.postDelayed(this, REPORT_MS)
        }
    }

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        request = PlayerRequest(intent.getStringExtra(EXTRA_REQUEST) ?: "{}")
        PlayerBridge.current = this
        window.addFlags(WindowManager.LayoutParams.FLAG_KEEP_SCREEN_ON or WindowManager.LayoutParams.FLAG_FULLSCREEN)
        immersive()

        exo = buildPlayer()
        player = exo
        vlcLayout = VLCVideoLayout(this).apply { visibility = View.GONE }
        playerView = PlayerView(this).apply {
            player = GatedPlayer(exo)
            setShowBuffering(PlayerView.SHOW_BUFFERING_WHEN_PLAYING)
            setBackgroundColor(Color.BLACK)
            controllerShowTimeoutMs = 3_000
            keepScreenOn = true
        }
        hud = RideHud(this, loadFont(request.fontPath)).apply {
            visibility = if (request.exercise.enabled) View.VISIBLE else View.GONE
            // A tap on the "bike not connected" card is the touch way to watch without a bike.
            setOnClickListener { if (lastStatus?.shortfall == RideGate.Shortfall.NO_BIKE) waiveExercise() else playerView.showController() }
        }
        skipButton = TextView(this).apply {
            text = "SKIP ▶"
            typeface = hud.typeface
            textSize = 28f
            setTextColor(Color.WHITE)
            setBackgroundColor(0xCC0A0094.toInt())
            setPadding(36, 18, 36, 18)
            visibility = View.GONE
            setOnClickListener { PlayerBridge.nativeSkipRequested(request.session) }
        }
        val root = FrameLayout(this)
        root.setBackgroundColor(Color.BLACK)
        root.addView(vlcLayout, FrameLayout.LayoutParams(-1, -1))
        root.addView(playerView, FrameLayout.LayoutParams(-1, -1))
        root.addView(hud, FrameLayout.LayoutParams(-1, -1))
        root.addView(skipButton, FrameLayout.LayoutParams(-2, -2, Gravity.BOTTOM or Gravity.END).apply { setMargins(0, 0, 48, 160) })
        setContentView(root)

        if (request.exercise.enabled) {
            if (request.exercise.simulate) {
                // Start the stand-in just above the difficulty's base, so a test ride plays at once.
                simulated = SimulatedBike(request.exercise.difficulty.baseRpm + 5f, request.exercise.difficulty.baseResistance + 5f)
            } else {
                bike = Bike.acquire(this)
            }
        }

        if (request.urls.isEmpty()) {
            Log.w(TAG, "nothing to play")
            handler.post { finishWith(REASON_FAILED) }
            return
        }
        exo.prepare()
        applyPlayWhenReady()
        handler.post(tick)
        handler.post(report)
    }

    private fun buildPlayer(): ExoPlayer {
        val http = DefaultHttpDataSource.Factory()
            .setAllowCrossProtocolRedirects(true)
            .setDefaultRequestProperties(request.headers)
        // smb:// (the Network Shares module) streams from the share; everything else as before.
        val sources = DefaultMediaSourceFactory(SmbOrDefaultDataSource.Factory(DefaultDataSource.Factory(this, http)))
        val player = ExoPlayer.Builder(this).setMediaSourceFactory(sources).build()

        val items = request.urls.mapIndexed { i, url ->
            val b = MediaItem.Builder().setUri(toUri(url))
            // External subtitles belong to the primary item, as with mpv's --sub-file.
            if (i == 0 && request.subFiles.isNotEmpty()) b.setSubtitleConfigurations(subtitleConfigs())
            b.build()
        }
        val start = request.playlistStart.coerceIn(0, (items.size - 1).coerceAtLeast(0))
        if (items.isNotEmpty()) player.setMediaItems(items, start, request.startMs.coerceAtLeast(0))
        player.repeatMode = if (request.loop) Player.REPEAT_MODE_ALL else Player.REPEAT_MODE_OFF
        player.shuffleModeEnabled = request.shuffle
        if (request.mute) player.volume = 0f
        if (request.subTrack < 0) {
            player.trackSelectionParameters = player.trackSelectionParameters.buildUpon()
                .setTrackTypeDisabled(C.TRACK_TYPE_TEXT, true).build()
        }
        player.addListener(exoListener)
        return player
    }

    private fun subtitleConfigs(): List<MediaItem.SubtitleConfiguration> = request.subFiles.mapIndexed { i, url ->
        MediaItem.SubtitleConfiguration.Builder(toUri(url))
            .setMimeType(subtitleMime(url))
            .setLanguage(request.subLangs.getOrNull(i)?.ifEmpty { null })
            .setLabel(request.subTitles.getOrNull(i)?.ifEmpty { null })
            // mpv's subTrack 0 with external subs: the first one is on.
            .setSelectionFlags(if (i == 0 && request.subTrack == 0) C.SELECTION_FLAG_DEFAULT else 0)
            .build()
    }

    private val exoListener = object : Player.Listener {
        override fun onPlaybackStateChanged(state: Int) {
            if (state == Player.STATE_ENDED) finishWith(REASON_EOF)
        }

        override fun onPlayerError(error: PlaybackException) {
            Log.w(TAG, "playback failed: ${error.errorCodeName}", error)
            if (canFallBack(error)) {
                handler.post { fallBackToVlc("ExoPlayer: ${error.errorCodeName}: ${SmbLog.causes(error).last()}") }
            } else {
                logToShares("Playback failed: ${error.errorCodeName}: ${SmbLog.causes(error).last()}")
                finishWith(REASON_FAILED)
            }
        }

        override fun onTracksChanged(tracks: Tracks) {
            applyTrackChoice(tracks, C.TRACK_TYPE_AUDIO, request.audioTrack)
            applyTrackChoice(tracks, C.TRACK_TYPE_TEXT, request.subTrack)
            // A video file whose picture ExoPlayer can't show at all (DivX 3 in an AVI is dropped
            // without an error, leaving only the sound): let VLC play it.
            if (!tracks.isEmpty && looksLikeVideo(currentUrl()) &&
                tracks.groups.none { it.type == C.TRACK_TYPE_VIDEO && it.isSupported }
            ) {
                handler.post { fallBackToVlc("ExoPlayer found no video it can decode") }
            }
        }
    }

    private val vlcListener = object : Player.Listener {
        override fun onPlaybackStateChanged(state: Int) {
            if (state == Player.STATE_ENDED) finishWith(REASON_EOF)
        }

        override fun onPlayerError(error: PlaybackException) {
            Log.w(TAG, "VLC playback failed too: ${error.message}")
            logToShares("Playback failed in VLC too: ${currentUrl()}")
            finishWith(REASON_FAILED)
        }
    }

    // ── VLC fallback ──────────────────────────────────────────────────────────────────────────

    /**
     * Errors that mean ExoPlayer can't decode or read this format, which VLC may: decoders refusing
     * the file, an unknown or broken container. Network and HTTP errors aren't: VLC would fail too.
     */
    private fun canFallBack(error: PlaybackException): Boolean {
        if (vlc != null || request.headers.isNotEmpty()) return false
        if (error.errorCode in 4000..4999 || error.errorCode == PlaybackException.ERROR_CODE_PARSING_CONTAINER_UNSUPPORTED ||
            error.errorCode == PlaybackException.ERROR_CODE_PARSING_CONTAINER_MALFORMED
        ) {
            return true
        }
        // ExoPlayer's AVI reader crashes on some files (MJPEG): an unexpected exception, not an IO one.
        return error.errorCode == PlaybackException.ERROR_CODE_IO_UNSPECIFIED &&
            generateSequence(error as Throwable) { it.cause }.any { it is RuntimeException }
    }

    /** Carries on with the same item, from the same place, in [VlcPlayer]. */
    private fun fallBackToVlc(why: String) {
        if (ended || vlc != null) return
        val index = exo.currentMediaItemIndex
        val position = exo.currentPosition
        Log.i(TAG, "switching to VLC at item $index, ${position / 1000}s: $why")
        logToShares("ExoPlayer can't play ${currentUrl().substringAfterLast('/')} ($why); trying VLC")
        exo.removeListener(exoListener)
        exo.release()

        val items = request.urls.mapIndexed { i, url ->
            VlcPlayer.Item(
                mediaItem = MediaItem.Builder().setUri(toUri(url)).setMediaId("$i").build(),
                location = vlcLocation(url),
                subtitles = if (i == 0) request.subFiles.map(::vlcLocation) else emptyList(),
                subtitleOn = request.subTrack == 0,
            )
        }
        val v = VlcPlayer(this, vlcLayout, items, index, position, request.loop, request.mute)
        vlc = v
        player = v
        v.addListener(vlcListener)
        vlcLayout.visibility = View.VISIBLE
        // VLC draws into its own view behind the PlayerView, which keeps only its controls.
        playerView.videoSurfaceView?.visibility = View.GONE
        playerView.setShutterBackgroundColor(Color.TRANSPARENT)
        playerView.setBackgroundColor(Color.TRANSPARENT)
        playerView.player = GatedPlayer(v)
        v.prepare()
        applyPlayWhenReady()
    }

    /** Where VLC reads [url]: files as paths, `smb://` through the app's own connection. */
    private fun vlcLocation(url: String): String = if (url.startsWith("smb://")) SmbHttpServer.url(url) else url

    private fun currentUrl(): String = request.urls.getOrNull(player.currentMediaItemIndex) ?: request.urls.firstOrNull() ?: ""

    /** For files from a network share, also in the Network Shares diagnostics log. */
    private fun logToShares(message: String) {
        if (currentUrl().startsWith("smb://")) SmbLog.add(message)
    }

    private val tracksApplied = mutableSetOf<Int>()

    /** mpv's --aid/--sid: pick the [oneBased]th track of [type], once per playback. */
    private fun applyTrackChoice(tracks: Tracks, type: Int, oneBased: Int) {
        if (oneBased <= 0 || type in tracksApplied) return
        val groups = tracks.groups.filter { it.type == type }
        val group = groups.getOrNull(oneBased - 1) ?: return
        tracksApplied += type
        exo.trackSelectionParameters = exo.trackSelectionParameters.buildUpon()
            .setOverrideForType(TrackSelectionOverride(group.mediaTrackGroup, 0)).build()
    }

    // ── Exercise mode ─────────────────────────────────────────────────────────────────────────

    private fun durationMs(): Long = player.duration.let { if (it == C.TIME_UNSET) 0L else it }

    private fun updateGate() {
        if (!exercising || ended) {
            hud.visibility = View.GONE
            return
        }
        // The program fits the item playing; build it once the item's length is known (or for a
        // live stream once it is clear there is none).
        val index = player.currentMediaItemIndex
        val duration = if (player.playbackState == Player.STATE_READY || player.playbackState == Player.STATE_ENDED) durationMs() else -1L
        // A program built before the length was known (a provisional repeating one) is replaced
        // once it is. The new gate starts over, which costs nothing: a rider already at target
        // passes straight through on this same update.
        val g = gate?.takeIf { index == gateItemIndex && (duration < 0 || duration == gateDurationMs) }
            ?: RideGate(Program.build(request.exercise.workout, request.exercise.difficulty, duration.coerceAtLeast(0))).also {
                gate = it
                gateItemIndex = index
                gateDurationMs = duration
            }
        val sample = simulated?.sample() ?: bike?.let { Bike.sample(it) } ?: return
        val status = g.update(SystemClock.elapsedRealtime(), player.currentPosition, sample)
        lastStatus = status
        hud.show(status, g.program, player.currentPosition, bike?.let { Bike.absent(it) } == true, simulated != null)
        applyPlayWhenReady()
    }

    private fun waiveExercise() {
        exerciseWaived = true
        Log.i(TAG, "rider chose to watch without the bike")
        applyPlayWhenReady()
    }

    private fun applyPlayWhenReady() {
        val gateOpen = !exercising || lastStatus?.open == true
        val play = userWantsPlay && gateOpen
        if (player.playWhenReady != play) player.playWhenReady = play
    }

    /** The player the on-screen controls drive: their play/pause records what the rider wants. */
    private inner class GatedPlayer(p: Player) : ForwardingPlayer(p) {
        override fun play() {
            userWantsPlay = true
            applyPlayWhenReady()
        }

        override fun pause() {
            userWantsPlay = false
            applyPlayWhenReady()
        }

        override fun setPlayWhenReady(playWhenReady: Boolean) {
            if (playWhenReady) play() else pause()
        }
    }

    // ── Commands from C++ and keys ────────────────────────────────────────────────────────────

    fun seekTo(positionMs: Long) {
        player.seekTo(positionMs.coerceAtLeast(0))
    }

    fun showSkipPrompt(show: Boolean) {
        skipButton.visibility = if (show) View.VISIBLE else View.GONE
    }

    override fun dispatchKeyEvent(event: KeyEvent): Boolean {
        if (event.action != KeyEvent.ACTION_DOWN) return super.dispatchKeyEvent(event)
        val sim = simulated
        when (event.keyCode) {
            KeyEvent.KEYCODE_BACK, KeyEvent.KEYCODE_ESCAPE, KeyEvent.KEYCODE_BUTTON_B, KeyEvent.KEYCODE_MEDIA_STOP -> {
                finishWith(REASON_STOPPED)
                return true
            }
            KeyEvent.KEYCODE_DPAD_CENTER, KeyEvent.KEYCODE_ENTER, KeyEvent.KEYCODE_NUMPAD_ENTER, KeyEvent.KEYCODE_BUTTON_A -> {
                when {
                    skipButton.visibility == View.VISIBLE -> PlayerBridge.nativeSkipRequested(request.session)
                    lastStatus?.shortfall == RideGate.Shortfall.NO_BIKE && exercising -> waiveExercise()
                    else -> togglePlay()
                }
                return true
            }
            KeyEvent.KEYCODE_SPACE, KeyEvent.KEYCODE_MEDIA_PLAY_PAUSE, KeyEvent.KEYCODE_BUTTON_START -> {
                togglePlay()
                return true
            }
            KeyEvent.KEYCODE_DPAD_LEFT, KeyEvent.KEYCODE_MEDIA_REWIND -> {
                seekTo(player.currentPosition - SEEK_MS)
                return true
            }
            KeyEvent.KEYCODE_DPAD_RIGHT, KeyEvent.KEYCODE_MEDIA_FAST_FORWARD -> {
                seekTo(player.currentPosition + SEEK_MS)
                return true
            }
        }
        if (sim != null) {
            when (event.keyCode) {
                KeyEvent.KEYCODE_DPAD_UP -> sim.nudgeRpm(5f)
                KeyEvent.KEYCODE_DPAD_DOWN -> sim.nudgeRpm(-5f)
                KeyEvent.KEYCODE_PAGE_UP, KeyEvent.KEYCODE_RIGHT_BRACKET -> sim.nudgeResistance(5f)
                KeyEvent.KEYCODE_PAGE_DOWN, KeyEvent.KEYCODE_LEFT_BRACKET -> sim.nudgeResistance(-5f)
                else -> return super.dispatchKeyEvent(event)
            }
            updateGate()
            return true
        }
        return super.dispatchKeyEvent(event)
    }

    private fun togglePlay() {
        userWantsPlay = !userWantsPlay
        applyPlayWhenReady()
        playerView.showController()
    }

    // ── Ending ────────────────────────────────────────────────────────────────────────────────

    /** Reports the end to C++ exactly once (as MpvController's playbackEnded) and closes. */
    fun finishWith(reason: String) {
        if (ended) return
        ended = true
        val pos = if (this::player.isInitialized) player.currentPosition.toInt() else 0
        val dur = if (this::player.isInitialized) durationMs().toInt() else 0
        gate?.let { Log.i(TAG, "ride: ${it.ridingMs / 1000}s at target, ${it.heldMs / 1000}s held") }
        PlayerBridge.nativeEnded(request.session, pos, dur, reason)
        if (!isFinishing) finish()
    }

    override fun onWindowFocusChanged(hasFocus: Boolean) {
        super.onWindowFocusChanged(hasFocus)
        if (hasFocus) immersive()
    }

    override fun onStop() {
        super.onStop()
        // Home, the power button, or another app on top: treat as the rider stopping, as closing
        // mpv would. The shell gets its playbackEnded and saves the position.
        if (!isChangingConfigurations) finishWith(REASON_STOPPED)
    }

    override fun onDestroy() {
        handler.removeCallbacksAndMessages(null)
        finishWith(REASON_STOPPED)
        if (this::exo.isInitialized) exo.release()
        vlc?.release()
        if (bike != null) {
            bike = null
            Bike.release()
        }
        if (PlayerBridge.current === this) PlayerBridge.current = null
        super.onDestroy()
    }

    @Suppress("DEPRECATION")
    private fun immersive() {
        window.decorView.systemUiVisibility = (View.SYSTEM_UI_FLAG_IMMERSIVE_STICKY
            or View.SYSTEM_UI_FLAG_FULLSCREEN or View.SYSTEM_UI_FLAG_HIDE_NAVIGATION
            or View.SYSTEM_UI_FLAG_LAYOUT_STABLE or View.SYSTEM_UI_FLAG_LAYOUT_HIDE_NAVIGATION
            or View.SYSTEM_UI_FLAG_LAYOUT_FULLSCREEN)
    }

    private fun loadFont(path: String): Typeface =
        try {
            if (path.isNotEmpty() && File(path).isFile) Typeface.createFromFile(path) else Typeface.MONOSPACE
        } catch (e: RuntimeException) {
            Typeface.MONOSPACE
        }

    companion object {
        const val EXTRA_REQUEST = "com.mp240.android.REQUEST"
        const val REASON_EOF = "eof"
        const val REASON_STOPPED = "stopped"
        const val REASON_FAILED = "failed"

        private const val TAG = "240mp.player"
        private const val TICK_MS = 200L
        private const val REPORT_MS = 500L
        private const val SEEK_MS = 10_000L

        /** A path or URL from the shell (local files are plain paths, as mpv takes them). */
        fun toUri(s: String): Uri = if (s.startsWith("/")) Uri.fromFile(File(s)) else Uri.parse(s)

        private val VIDEO_EXTENSIONS = setOf(
            "avi", "divx", "xvid", "mkv", "mp4", "m4v", "mov", "wmv", "asf", "flv", "mpg", "mpeg", "ts", "m2ts", "mts",
            "vob", "webm", "ogv", "3gp",
        )

        /** Whether [url] names a video file (by its extension), so a missing picture is a failure. */
        fun looksLikeVideo(url: String): Boolean {
            val path = (if (url.startsWith("/")) url else Uri.parse(url).path ?: url).lowercase()
            return path.substringAfterLast('.', "") in VIDEO_EXTENSIONS
        }

        fun subtitleMime(url: String): String {
            val path = Uri.parse(url).path?.lowercase() ?: url.lowercase()
            return when {
                path.endsWith(".vtt") -> MimeTypes.TEXT_VTT
                path.endsWith(".ass") || path.endsWith(".ssa") -> MimeTypes.TEXT_SSA
                path.endsWith(".ttml") || path.endsWith(".dfxp") -> MimeTypes.APPLICATION_TTML
                else -> MimeTypes.APPLICATION_SUBRIP
            }
        }
    }
}

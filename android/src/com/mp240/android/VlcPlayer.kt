// SPDX-License-Identifier: GPL-3.0-only
package com.mp240.android

import android.content.Context
import android.net.Uri
import android.os.Handler
import android.os.Looper
import android.util.Log
import androidx.media3.common.C
import androidx.media3.common.MediaItem
import androidx.media3.common.PlaybackException
import androidx.media3.common.Player
import androidx.media3.common.SimpleBasePlayer
import com.google.common.util.concurrent.Futures
import com.google.common.util.concurrent.ListenableFuture
import org.videolan.libvlc.LibVLC
import org.videolan.libvlc.Media
import org.videolan.libvlc.MediaPlayer
import org.videolan.libvlc.interfaces.IMedia
import org.videolan.libvlc.util.VLCVideoLayout

/**
 * libVLC behind media3's [Player] interface: the fallback for files ExoPlayer can't decode on the
 * bike's Android 7 (XviD and DivX AVIs, Theora .ogv, MJPEG). Because it is a [Player],
 * [PlayerActivity]'s ride gate, HUD, on-screen controls and progress reports drive it exactly as
 * they drive ExoPlayer.
 *
 * Video goes to [layout] (libVLC's own view, which also carries subtitles), not to PlayerView's
 * surface. Decoding is in software: the fallback is used because the tablet's hardware decoders
 * refused the file, and the bike's CPU decodes standard-definition video easily.
 *
 * Each [Item]'s [Item.location] is something VLC can open: a file path, an http(s) URL, or the
 * loopback address [com.mp240.android.smb.SmbHttpServer] gives for an `smb://` file.
 */
class VlcPlayer(
    context: Context,
    private val layout: VLCVideoLayout,
    private val items: List<Item>,
    startIndex: Int,
    startMs: Long,
    private val loop: Boolean,
    private val muted: Boolean,
) : SimpleBasePlayer(Looper.getMainLooper()) {

    /** One playlist entry: the item ExoPlayer had, where VLC reads it, and its subtitle files. */
    class Item(val mediaItem: MediaItem, val location: String, val subtitles: List<String>, val subtitleOn: Boolean)

    private val main = Handler(Looper.getMainLooper())
    private val libVlc = LibVLC(context, arrayListOf("--no-drop-late-frames", "--no-skip-frames", "--http-reconnect"))
    private val mp = MediaPlayer(libVlc)

    private var index = startIndex.coerceIn(0, (items.size - 1).coerceAtLeast(0))
    private var pendingStartMs = startMs.coerceAtLeast(0)
    private var playWhenReady = false
    private var state = Player.STATE_IDLE
    private var lengthMs = C.TIME_UNSET
    private var lastTimeMs = startMs.coerceAtLeast(0)
    private var error: PlaybackException? = null
    private var started = false
    private var firstFrame = false
    private var released = false

    init {
        mp.attachViews(layout, null, /* enableSubtitles = */ true, /* useTextureView = */ false)
        mp.setEventListener { e -> main.post { onEvent(e) } }
        if (muted) mp.setVolume(0)
    }

    // ── State for media3 ──────────────────────────────────────────────────────────────────────

    override fun getState(): State {
        val playlist = items.mapIndexed { i, item ->
            MediaItemData.Builder("vlc-$i")
                .setMediaItem(item.mediaItem)
                .setIsSeekable(true)
                .setDurationUs(if (i == index && lengthMs > 0) lengthMs * 1000 else C.TIME_UNSET)
                .build()
        }
        val commands = Player.Commands.Builder().addAll(
            Player.COMMAND_PLAY_PAUSE, Player.COMMAND_PREPARE, Player.COMMAND_STOP, Player.COMMAND_RELEASE,
            Player.COMMAND_SEEK_TO_DEFAULT_POSITION, Player.COMMAND_SEEK_IN_CURRENT_MEDIA_ITEM,
            Player.COMMAND_SEEK_BACK, Player.COMMAND_SEEK_FORWARD, Player.COMMAND_SEEK_TO_MEDIA_ITEM,
            Player.COMMAND_SEEK_TO_NEXT_MEDIA_ITEM, Player.COMMAND_SEEK_TO_PREVIOUS_MEDIA_ITEM,
            Player.COMMAND_GET_CURRENT_MEDIA_ITEM, Player.COMMAND_GET_TIMELINE, Player.COMMAND_SET_VOLUME,
        ).build()
        val frame = firstFrame
        firstFrame = false
        return State.Builder()
            .setAvailableCommands(commands)
            .setPlayWhenReady(playWhenReady, Player.PLAY_WHEN_READY_CHANGE_REASON_USER_REQUEST)
            .setPlaylist(playlist)
            .setCurrentMediaItemIndex(index)
            .setPlaybackState(if (error != null || items.isEmpty()) Player.STATE_IDLE else state)
            .setPlayerError(error)
            .setRepeatMode(if (loop) Player.REPEAT_MODE_ALL else Player.REPEAT_MODE_OFF)
            .setContentPositionMs { position() }
            .setSeekBackIncrementMs(SEEK_MS)
            .setSeekForwardIncrementMs(SEEK_MS)
            .setVolume(if (muted) 0f else 1f)
            .setNewlyRenderedFirstFrame(frame)
            .build()
    }

    private fun position(): Long {
        if (state == Player.STATE_ENDED && lengthMs > 0) return lengthMs
        if (!started) return pendingStartMs
        val t = if (released) -1L else mp.time
        if (t >= 0) lastTimeMs = t
        return lastTimeMs
    }

    // ── Commands ──────────────────────────────────────────────────────────────────────────────

    override fun handlePrepare(): ListenableFuture<*> {
        if (items.isNotEmpty() && state == Player.STATE_IDLE && error == null) load(index, pendingStartMs)
        return Futures.immediateVoidFuture()
    }

    override fun handleSetPlayWhenReady(playWhenReady: Boolean): ListenableFuture<*> {
        this.playWhenReady = playWhenReady
        if (started) {
            if (playWhenReady && !mp.isPlaying) mp.play()
            if (!playWhenReady && mp.isPlaying) mp.pause()
        }
        return Futures.immediateVoidFuture()
    }

    override fun handleSeek(mediaItemIndex: Int, positionMs: Long, seekCommand: Int): ListenableFuture<*> {
        val target = if (positionMs == C.TIME_UNSET) 0L else positionMs.coerceAtLeast(0)
        if (mediaItemIndex != index || state == Player.STATE_ENDED || !started) {
            load(mediaItemIndex.coerceIn(0, items.size - 1), target)
        } else {
            mp.setTime(target)
            lastTimeMs = target
        }
        return Futures.immediateVoidFuture()
    }

    override fun handleSetVolume(volume: Float): ListenableFuture<*> {
        mp.setVolume((volume * 100).toInt())
        return Futures.immediateVoidFuture()
    }

    override fun handleStop(): ListenableFuture<*> {
        mp.stop()
        state = Player.STATE_IDLE
        started = false
        return Futures.immediateVoidFuture()
    }

    override fun handleRelease(): ListenableFuture<*> {
        if (!released) {
            released = true
            mp.setEventListener(null)
            mp.stop()
            mp.detachViews()
            mp.release()
            libVlc.release()
        }
        return Futures.immediateVoidFuture()
    }

    // ── libVLC ────────────────────────────────────────────────────────────────────────────────

    private fun load(i: Int, startMs: Long) {
        index = i
        val item = items[i]
        val media = if (item.location.startsWith("/")) Media(libVlc, item.location) else Media(libVlc, Uri.parse(item.location))
        media.setHWDecoderEnabled(false, false)
        if (startMs > 0) media.addOption(":start-time=${startMs / 1000.0}")
        mp.setMedia(media)
        media.release()
        item.subtitles.forEachIndexed { n, sub ->
            mp.addSlave(IMedia.Slave.Type.Subtitle, Uri.parse(sub), n == 0 && item.subtitleOn)
        }
        pendingStartMs = startMs
        lastTimeMs = startMs
        lengthMs = C.TIME_UNSET
        started = false
        state = Player.STATE_BUFFERING
        mp.play()
        Log.i(TAG, "playing item $i from ${startMs / 1000}s: ${item.location}")
        invalidateState()
    }

    private fun onEvent(e: MediaPlayer.Event) {
        if (released) return
        when (e.type) {
            MediaPlayer.Event.Playing -> {
                started = true
                state = Player.STATE_READY
                // VLC has to play to open the file; hold it if nobody wants it playing yet.
                if (!playWhenReady) mp.pause()
            }
            MediaPlayer.Event.Paused -> state = Player.STATE_READY
            MediaPlayer.Event.Buffering -> if (!started) state = Player.STATE_BUFFERING
            MediaPlayer.Event.TimeChanged -> {
                lastTimeMs = e.timeChanged
                return
            }
            MediaPlayer.Event.LengthChanged -> lengthMs = e.lengthChanged.takeIf { it > 0 } ?: C.TIME_UNSET
            MediaPlayer.Event.Vout -> if (e.voutCount > 0) firstFrame = true
            MediaPlayer.Event.EndReached -> {
                if (error != null) return
                when {
                    index + 1 < items.size -> {
                        load(index + 1, 0)
                        return
                    }
                    loop -> {
                        load(0, 0)
                        return
                    }
                    else -> state = Player.STATE_ENDED
                }
            }
            MediaPlayer.Event.EncounteredError -> {
                Log.w(TAG, "VLC couldn't play ${items[index].location}")
                error = PlaybackException("VLC couldn't play this file", null, PlaybackException.ERROR_CODE_DECODING_FAILED)
            }
            else -> return
        }
        invalidateState()
    }

    companion object {
        private const val TAG = "240mp.vlc"
        private const val SEEK_MS = 10_000L
    }
}

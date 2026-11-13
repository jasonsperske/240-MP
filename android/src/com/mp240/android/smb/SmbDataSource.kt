// SPDX-License-Identifier: GPL-3.0-only
package com.mp240.android.smb

import android.net.Uri
import androidx.media3.common.C
import androidx.media3.common.PlaybackException
import androidx.media3.datasource.BaseDataSource
import androidx.media3.datasource.DataSource
import androidx.media3.datasource.DataSourceException
import androidx.media3.datasource.DataSpec
import androidx.media3.datasource.TransferListener
import com.hierynomus.msdtyp.AccessMask
import com.hierynomus.mssmb2.SMB2CreateDisposition
import com.hierynomus.mssmb2.SMB2ShareAccess
import com.hierynomus.smbj.share.File
import java.io.IOException
import java.util.EnumSet

/**
 * Streams a file straight from the SMB share for ExoPlayer: `smb://host[:port]/share/dir/file.mkv`.
 * Nothing is copied to the tablet first, and seeking reads from wherever the player asks.
 *
 * ExoPlayer reads in small pieces; each SMB read is a network round trip, so reads go through a
 * [CHUNK]-sized read-ahead buffer.
 */
class SmbDataSource : BaseDataSource(/* isNetwork = */ true) {
    private var file: File? = null
    private var uri: Uri? = null
    private var opened = false
    private var position = 0L
    private var bytesRemaining = 0L

    private val buffer = ByteArray(CHUNK)
    private var bufferStart = 0L
    private var bufferLength = 0

    override fun open(dataSpec: DataSpec): Long {
        uri = dataSpec.uri
        transferInitializing(dataSpec)
        val location = SmbLocation.parse(dataSpec.uri)
        val size: Long
        try {
            val f = SmbConnections.withShare(location) { share ->
                share.openFile(
                    location.path,
                    EnumSet.of(AccessMask.GENERIC_READ),
                    null,
                    SMB2ShareAccess.ALL,
                    SMB2CreateDisposition.FILE_OPEN,
                    null,
                )
            }
            file = f
            size = f.fileInformation.standardInformation.endOfFile
        } catch (e: Exception) {
            throw DataSourceException(IOException(SmbConnections.describe(e), e), PlaybackException.ERROR_CODE_IO_NETWORK_CONNECTION_FAILED)
        }
        if (dataSpec.position > size) {
            throw DataSourceException(PlaybackException.ERROR_CODE_IO_READ_POSITION_OUT_OF_RANGE)
        }
        position = dataSpec.position
        bytesRemaining = if (dataSpec.length != C.LENGTH_UNSET.toLong()) dataSpec.length else size - position
        bufferLength = 0
        opened = true
        transferStarted(dataSpec)
        return bytesRemaining
    }

    override fun read(target: ByteArray, offset: Int, length: Int): Int {
        if (length == 0) return 0
        if (bytesRemaining == 0L) return C.RESULT_END_OF_INPUT
        if (position < bufferStart || position >= bufferStart + bufferLength) {
            fill()
            if (bufferLength <= 0) return C.RESULT_END_OF_INPUT
        }
        val available = (bufferStart + bufferLength - position).toInt()
        val n = minOf(length.toLong(), available.toLong(), bytesRemaining).toInt()
        System.arraycopy(buffer, (position - bufferStart).toInt(), target, offset, n)
        position += n
        bytesRemaining -= n
        bytesTransferred(n)
        return n
    }

    private fun fill() {
        val f = file ?: throw IOException("not open")
        val want = minOf(CHUNK.toLong(), bytesRemaining).toInt()
        bufferStart = position
        bufferLength = try {
            // A read may return less than asked (the server's maximum read size); that's fine.
            f.read(buffer, position, 0, want)
        } catch (e: Exception) {
            throw DataSourceException(IOException(SmbConnections.describe(e), e), PlaybackException.ERROR_CODE_IO_NETWORK_CONNECTION_FAILED)
        }
    }

    override fun getUri(): Uri? = uri

    override fun close() {
        uri = null
        bufferLength = 0
        runCatching { file?.close() }
        file = null
        if (opened) {
            opened = false
            transferEnded()
        }
    }

    companion object {
        /** Read-ahead per SMB read: 1 MiB, the largest single read SMB 2.1+ servers commonly allow. */
        const val CHUNK = 1 shl 20
    }
}

/**
 * The player's data source: `smb://` addresses go to [SmbDataSource], everything else (files,
 * HTTP for Plex, Jellyfin and Emby) to [fallback].
 */
class SmbOrDefaultDataSource(private val fallback: DataSource) : DataSource {
    private var smb: SmbDataSource? = null
    private var active: DataSource? = null
    private val listeners = mutableListOf<TransferListener>()

    override fun addTransferListener(transferListener: TransferListener) {
        listeners += transferListener
        fallback.addTransferListener(transferListener)
        smb?.addTransferListener(transferListener)
    }

    override fun open(dataSpec: DataSpec): Long {
        val source = if (dataSpec.uri.scheme == "smb") {
            smb ?: SmbDataSource().also { s -> listeners.forEach(s::addTransferListener); smb = s }
        } else {
            fallback
        }
        active = source
        return source.open(dataSpec)
    }

    override fun read(buffer: ByteArray, offset: Int, length: Int): Int =
        (active ?: throw IOException("not open")).read(buffer, offset, length)

    override fun getUri(): Uri? = active?.uri

    override fun getResponseHeaders(): Map<String, List<String>> = active?.responseHeaders ?: emptyMap()

    override fun close() {
        try {
            active?.close()
        } finally {
            active = null
        }
    }

    class Factory(private val fallback: DataSource.Factory) : DataSource.Factory {
        override fun createDataSource(): DataSource = SmbOrDefaultDataSource(fallback.createDataSource())
    }
}

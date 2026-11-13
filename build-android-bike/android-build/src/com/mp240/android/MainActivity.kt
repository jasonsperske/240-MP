// SPDX-License-Identifier: GPL-3.0-only
package com.mp240.android

import android.Manifest
import android.content.pm.PackageManager
import android.os.Build
import android.os.Bundle
import android.view.KeyEvent
import org.qtproject.qt.android.bindings.QtActivity

/**
 * The Qt activity that hosts 240-MP's QML shell on Android.
 *
 * Input: 240-MP's views handle arrow keys, Enter, Escape and Space, and on the desktop
 * InputManager turns gamepad buttons into those keys (via SDL). On Android, Qt already delivers a
 * gamepad's d-pad as arrow keys; this maps the rest the same way before Qt sees them, so a
 * Bluetooth pad or remote drives the views exactly like a desktop gamepad. Android's Back becomes
 * Escape, which is "back" everywhere in the app (Qt would otherwise close the activity on an
 * unhandled Back).
 */
class MainActivity : QtActivity() {
    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        // Local Files and Ambient Mode browse shared storage (videos copied to /sdcard).
        if (Build.VERSION.SDK_INT >= 23 &&
            checkSelfPermission(Manifest.permission.READ_EXTERNAL_STORAGE) != PackageManager.PERMISSION_GRANTED
        ) {
            requestPermissions(arrayOf(Manifest.permission.READ_EXTERNAL_STORAGE), REQUEST_STORAGE)
        }
    }

    override fun dispatchKeyEvent(event: KeyEvent): Boolean {
        val mapped = KEY_MAP[event.keyCode] ?: return super.dispatchKeyEvent(event)
        return super.dispatchKeyEvent(
            KeyEvent(
                event.downTime, event.eventTime, event.action, mapped, event.repeatCount,
                event.metaState, event.deviceId, event.scanCode, event.flags, event.source,
            ),
        )
    }

    companion object {
        private const val REQUEST_STORAGE = 240

        /** Android key → the key 240-MP's views expect (InputManager's Action → Qt key table). */
        private val KEY_MAP = mapOf(
            KeyEvent.KEYCODE_BACK to KeyEvent.KEYCODE_ESCAPE,
            KeyEvent.KEYCODE_BUTTON_B to KeyEvent.KEYCODE_ESCAPE,
            KeyEvent.KEYCODE_BUTTON_SELECT to KeyEvent.KEYCODE_ESCAPE,
            KeyEvent.KEYCODE_BUTTON_A to KeyEvent.KEYCODE_ENTER,
            KeyEvent.KEYCODE_DPAD_CENTER to KeyEvent.KEYCODE_ENTER,
            KeyEvent.KEYCODE_BUTTON_START to KeyEvent.KEYCODE_SPACE,
            KeyEvent.KEYCODE_BUTTON_L1 to KeyEvent.KEYCODE_DPAD_LEFT,
            KeyEvent.KEYCODE_BUTTON_R1 to KeyEvent.KEYCODE_DPAD_RIGHT,
        )
    }
}

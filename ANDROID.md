# 240-MP on Android: the Peloton Bike (gen 1)

240-MP runs on the original Peloton Bike's tablet (Android 7.0, API 24, 1920x1080 landscape) as a sideloaded APK. Besides playing video, it adds **exercise mode**: the video plays only while the rider holds a target cadence and resistance, and the target can follow a workout laid over the length of the video, like a spin class.

The bike's sensors are read with [soloton](https://github.com/jasonsperske/soloton)'s bike library, vendored the same way [ExerDoom](https://github.com/jasonsperske/ExerDoom) vendors it.

> **Status:** builds into an APK (arm64-v8a + armeabi-v7a for the bike, x86_64 for the emulator) and runs on an Android 7.0 (API 24) emulator shaped like the gen 1 tablet. On the emulator, the menus, touch pad, Ride Check, playback and the whole ride gate were exercised with the simulated bike: waiting to start, the 3 s grace, the hold, resuming, the 10 s ramp, and the NEXT warning. So were the no-bike path and the hand-back to the shell (the resume position comes back). On a real gen 1 bike, exercise mode works with the bike's sensors, and Network Shares signs in and browses (see [Not yet verified](#not-yet-verified) for what's left).

## How it fits together

Android follows the desktop's design: the shell browses, then hands off to a dedicated full-screen player, then resumes when the player closes. The desktop hands off to an mpv process. On Android the player is an Activity:

| Piece | Where | What it does |
|---|---|---|
| `AndroidPlayerController` | `src/player/` | Stands in for `MpvController` under the same QML name (`mpvController`) and with the same API, so every module's Player view works unchanged. `loadAndPlay` sends the request to `PlayerActivity` over JNI; progress and the end of playback come back as `positionChanged` / `playbackEnded`, as from mpv. |
| `PlayerActivity`, `RideHud` | `android/src/com/mp240/android/` | Media3 (ExoPlayer) playback, plus the exercise overlay and the ride gate. Files ExoPlayer can't decode carry on in `VlcPlayer` (libVLC); see [Formats ExoPlayer can't play](#formats-exoplayer-cant-play-the-vlc-fallback). |
| `exercise-core` | `android/exercise-core/` | Plain Kotlin, unit tested on the JVM: difficulty levels, workout programs (`Program.build`) and the gate that decides whether the video may play (`RideGate`). |
| bike library | `android/vendor/bike-core`, `android/vendor/bike` | soloton's library, vendored unchanged (`android/vendor/UPSTREAM`; refresh with `scripts/sync-bike-lib.sh`). It binds Peloton's own sensor service and reports cadence, power and resistance. |
| Exercise module | `modules/exercise/`, `src/modules/exercise/` | The **Exercise:Mode** entry in the main menu. Its Ride Check screen shows the bike's live readings, holds the settings, previews the workout, and opens the bike library's diagnostics screen. |
| `MainActivity`, `TouchPad.qml` | `android/src/...`, `views/Components/` | Input. The tablet is touch-only, so an on-screen pad taps the same keys a gamepad would (`inputManager.tapKey`). Bluetooth gamepads and remotes are mapped to the keys the views already handle. |
| `AppBundle` | `src/platform/android/` | The QML, modules and assets ship inside the APK as Qt resources and are mirrored to app storage at startup, so `appRoot` is an ordinary directory, as on the desktop. |

**Network Shares** (`modules/network_shares/`, `src/modules/network_shares/`, `android/src/com/mp240/android/smb/`) browses and plays videos straight from an SMB 2/3 share on a NAS or computer, signed in with a username and password. See [Network shares (SMB)](#network-shares-smb).

Modules that need things Android lacks declare `"platforms": ["linux", "macos"]` in their manifest and are not loaded or built there: NFC Reader (PC/SC, USB serial), Scripts (a VT), YouTube (yt-dlp), Weather (mpv for music, `QtQuick.Effects`). The exercise module declares `["android"]`.

Qt 6.4 predates `QtQuick.Effects`, so `views/Components/+android/AppBar.qml` (picked by Qt's file selector on Android) tints the icon with Qt5Compat's `ColorOverlay` instead of `MultiEffect`. Keep the two `AppBar.qml` files in step.

## Exercise mode

Turn it on and off, and pick the workout and difficulty, in **Exercise:Mode** (or **Settings → Modules → Exercise:Mode**). The settings apply to every video, whichever module plays it.

### Difficulty

The base target each workout builds on. Resistance uses the knob's 0 to 100 scale.

| Difficulty | Cadence | Resistance |
|---|---|---|
| Easy | 60 rpm | 20 |
| Moderate | 70 rpm | 30 |
| Hard | 80 rpm | 40 |
| Expert | 90 rpm | 50 |

### Workouts

Every workout is scaled to the length of the video. Videos under 3 minutes always get **Steady**. A live stream (no known length) gets a 45-minute program that repeats.

| Workout | Shape |
|---|---|
| **Steady** | The difficulty's base cadence and resistance, for the whole video. |
| **Intervals** | Warm-up, then 1-minute *pushes* (+10 rpm, +10 resistance) alternating with 1-minute *recoveries* (−10, −10), then a cool-down. |
| **Hills** | Warm-up, then steps of about 90 s that climb from 15 below to 10 above base resistance and back down, with cadence easing as the hill steepens. Long videos get several hills with recoveries between them. Then a cool-down. |
| **Spin Class** | Warm-up, then sets of about 6 minutes (flat road, climb, recovery, push, sprint at +20 rpm, recovery), with climbs and pushes building by 5 resistance a set toward the middle of the class and easing after, then a cool-down. |

Warm-up is 10% of the video (30 s to 5 min) and cool-down 8% (30 s to 4 min), both 10 to 15 below base.

### The gate

- The video waits on **PEDAL TO PLAY** until the rider first reaches the target.
- It plays while cadence **and** resistance are at or above the target.
- If either drops below, the panel turns amber and the video keeps playing for **3 seconds**: the bike reports about once a second, and resistance two samples late. After that the video pauses on **PICK IT UP!** and resumes as soon as the rider is back at target.
- When a segment raises the target, the rider gets **10 seconds** to turn the knob and spin up before the new target is enforced. A lower target applies at once. The panel shows the next segment in its last 15 seconds.
- The program runs on video time, so it stops while the video is paused. Seeking moves through the program too.
- **No bike.** If the bike isn't connected, the video holds on **WAITING FOR BIKE**, or **NO BIKE FOUND** on a device with no Peloton sensor service. Press OK, or tap the screen, to watch that video without exercise mode.

The HUD draws the workout's profile across the top of the screen, with resistance as bar height and a playhead. A panel shows the segment, its time left, and cadence and resistance against the target.

### Trying it without a bike

Turn on **Simulated Bike** in the exercise module's settings. The player then uses a stand-in bike that starts 5 above the difficulty's base: **UP/DOWN** change its cadence by 5 rpm, **PAGE UP/PAGE DOWN** (or `]` / `[`) its resistance by 5.

## Network shares (SMB)

Android 7 can't mount an SMB share without root, so the app speaks SMB itself, with [smbj](https://github.com/hierynomus/smbj) (Apache-2.0):

- **Setup.** Open **Network Shares**. Enter the server (`nas.local`, `192.168.1.20`, or `host:port` for a non-standard port), the share name, the username and the password; Domain is usually blank. Tap a field for the keyboard, or move with the pad or a remote. **Connect** signs in and saves only if that works. Later, press LEFT at the share's top folder to change any of it. **Settings → Network Shares → Forget Server** clears it.
- **Browsing.** Folders, then video and audio files. Hidden and system entries are left out. Subtitle files named after a video (`Movie.srt`, `Movie.en.srt`) aren't listed; they're loaded with it.
- **Playback** streams straight from the share, with no copy to the tablet. `smb://` addresses go through `SmbDataSource`, a seekable Media3 data source with 1 MiB read-ahead, so exercise mode, the HUD and resume all work as for any other video. Resume positions are kept per file (**Resume Playback**: Ask, Always or Never).
- **Connections.** One SMB session is kept open and shared by the browser and the player. If the NAS drops it (reboot, sleep, Wi-Fi), the next request reconnects once on its own, within about 10 s. If the server can't be reached, the folder shows why, and OK retries.
- **`.local` names.** Android 7's resolver can't look up `.local` names (`tower.local`, `nas.local`); Android only learned mDNS in Android 12. So when DNS can't find a `.local` name (or a bare name like `TOWER`, tried as `TOWER.local`), the app asks with multicast DNS itself (`MdnsResolver`). It uses a legacy unicast query to 224.0.0.251:5353 on every interface, so the answer comes straight back and no Wi-Fi multicast lock is needed. Answers are cached for 10 minutes. An IP address always works too.
- **Diagnostics.** **Diagnose** on the setup screen, or RIGHT (►) when a folder won't open, checks the settings one step at a time and shows where they fail:
  1. look up the name (DNS, then mDNS);
  2. TCP connect to the port;
  3. SMB negotiate (dialect, signing);
  4. sign in (it also flags when the server only let it in as a guest);
  5. open and list the share.

  The screen also shows the network-share log from this run of the app: lookups, connections, reconnects, and failed listings or playback, each with its exception chain. The log is held in memory (`SmbLog`, the last 400 lines) and copied to logcat under `240mp.smb`.
- **Credentials** are stored in `config.json` in the app's private storage, as Plex's and Jellyfin's tokens are.
- **SMB 2.0.2 to 3.1.1.** SMB1 isn't supported. Android's crypto has no MD4 (needed for NTLM), so smbj uses its BouncyCastle provider.

**Build notes.** smbj and its dependencies are newer than the 2022 toolchain Qt 6.4 pins. AGP 7.2's own dexer crashes on their enum classes, so `android/build.gradle` puts R8 8.2.47 ahead of AGP on the buildscript classpath. Core-library desugaring is on, because smbj refers to `java.time`, which Android 7 lacks.

**Tested** on the emulator against Samba 4.17 (Debian) on a non-standard port, which negotiated SMB 3.1.1 with signing:
- sign-in, and a wrong password;
- browsing, and the file filter;
- MKV playback with a sidecar `.srt`;
- seeking and resume;
- the server going away and coming back (the automatic reconnect, and RETRY).

**On a real gen 1 bike**, against an Unraid server on home Wi-Fi: sign-in and browsing work, with the server entered as `tower.local` (found by the mDNS fallback). Playback from the share hasn't been checked on the bike yet.

## Formats ExoPlayer can't play: the VLC fallback

The tablet's Android 7 decoders only handle MPEG-4 *Simple* Profile, and ExoPlayer has no Theora at all. So the files common in older collections don't play in ExoPlayer:

| File | In ExoPlayer |
|---|---|
| XviD or DivX 5 AVI (MPEG-4 Advanced Simple Profile) | the decoder refuses it: "PVInitVideoDecoder failed" |
| DivX 3 AVI | the video is dropped without an error, leaving only the sound |
| MJPEG AVI | ExoPlayer's AVI reader crashes |
| Theora `.ogv` | the container isn't recognised |

These now carry on in [libVLC](https://code.videolan.org/videolan/vlc-android) (LGPL-2.1+), which decodes them in software.

- **When it switches.** `PlayerActivity` switches to `VlcPlayer` at the same item and position when either of these happens:
  - ExoPlayer reports a decoder error (`4xxx`), an unsupported or malformed container, or an unexpected crash in its extractor;
  - a video file (judged by its extension) loads with no video track ExoPlayer can decode.

  Network and HTTP errors don't switch, because VLC would fail too. Nor do streams that need request headers (Plex, Jellyfin, Emby), which VLC can't send.
- **One player interface.** `VlcPlayer` is a media3 `SimpleBasePlayer`, so the ride gate, the HUD, the on-screen controls, seeking, resume and the progress reports to C++ all drive it as they drive ExoPlayer.
  - It draws into libVLC's own `VLCVideoLayout` behind the `PlayerView`, which keeps only its controls. libVLC letterboxes the picture and renders sidecar subtitles itself.
  - Decoding is in software, since the hardware decoders are what refused the file.
- **Network shares.** VLC can't use the app's SMB connection, so `SmbHttpServer` serves the file over HTTP on 127.0.0.1, with byte ranges for seeking, reading through `SmbConnections`. That keeps sign-in, `.local` names and reconnects the same in both players.
- **Logging.** The switch, and a failure in VLC too, are written to the Network Shares log (Diagnostics) for `smb://` files, and to logcat under `240mp.player` and `240mp.vlc`.

**Build notes.**
- libVLC **3.6.5** is the newest that fits Qt 6.4's toolchain: 3.7.x needs compileSdk 36 and Kotlin 2.2.
- libVLC adds about 40 MB per ABI before compression.
- It ships its own `libc++_shared.so`, and so does Qt (NDK 23, clang 12). An APK holds one per ABI, and it must be the newer, because code built against an older libc++ runs on a newer one but not the other way round:
  - **arm64-v8a and x86_64:** libVLC's copy is newer (clang 18), so `android/build.gradle` deletes Qt's from androiddeployqt's build directory.
  - **armeabi-v7a and x86:** libVLC's copy is older (clang 9), so `pickFirsts` keeps Qt's.

## Building

### Prerequisites

- **Qt 6.4.3 for Android**, the last Qt whose Android support reaches API 24 (Qt 6.5 needs API 26), with the host kit and the **qt5compat** and **qtshadertools** modules (the icon tint uses Qt5Compat, whose effects need ShaderTools). With [aqtinstall](https://github.com/miurahr/aqtinstall):
  ```bash
  aqt install-qt linux desktop 6.4.3 gcc_64 -m qt5compat qtshadertools -O ~/Qt
  for abi in android_arm64_v8a android_armv7 android_x86_64; do
      aqt install-qt linux android 6.4.3 $abi -m qt5compat qtshadertools -O ~/Qt
  done
  ```
- **JDK 17** and the **Android SDK** with `platforms;android-33`, `build-tools;33.0.2` and **NDK 23.1.7779620** (the NDK Qt 6.4 is built with). soloton's `scripts/doctor.sh --fix` sets up the JDK and SDK, then:
  ```bash
  sdkmanager "ndk;23.1.7779620" "platforms;android-33" "build-tools;33.0.2"
  ```
- **OpenSSL 1.1 built for Android.** Qt 6.4 loads it at runtime for HTTPS, and the Plex backend links it. Point `MP240_ANDROID_OPENSSL_DIR` at a directory with `include/openssl/` and `<abi>/libcrypto_1_1.so` + `<abi>/libssl_1_1.so`: the `ssl_1.1/` folder of [KDAB/android_openssl](https://github.com/KDAB/android_openssl) (the prebuilt build Qt's docs point to), or your own NDK build of OpenSSL 1.1.1. Nothing is downloaded by the build.

Qt 6.4's Android template pins **Gradle 7.4.2 and AGP 7.2.1**; `android/build.gradle` adds Kotlin 2.0.21 and Media3 1.1.1, the newest of each that work with that pair.

### Build an APK

```bash
. ~/.local/share/soloton-toolchain/env.sh          # JAVA_HOME, ANDROID_HOME
# The bike: arm64-v8a (its MT8173), plus armeabi-v7a as a fallback, in one APK.
~/Qt/6.4.3/android_arm64_v8a/bin/qt-cmake -G Ninja -B build-android-bike -S . \
    -DANDROID_SDK_ROOT=$ANDROID_HOME \
    -DANDROID_NDK_ROOT=$ANDROID_HOME/ndk/23.1.7779620 \
    -DQT_HOST_PATH=$HOME/Qt/6.4.3/gcc_64 \
    -DQT_ANDROID_ABIS="arm64-v8a;armeabi-v7a" \
    -DMP240_ANDROID_OPENSSL_DIR=/path/to/android_openssl/ssl_1.1 \
    -DCMAKE_BUILD_TYPE=Release
cmake --build build-android-bike --target apk
```

The APK is `build-android-bike/android-build/240mp.apk`, signed with the debug key, which is fine for sideloading. For soloton's gen 1 emulator (`scripts/gen1-emulator.sh` there), configure a separate build directory with the `android_x86_64` kit's `qt-cmake` and leave out `QT_ANDROID_ABIS`. Use the SDK's CMake (`$ANDROID_HOME/cmake/3.31.6/bin`, which also has `ninja`); it's closer to what Qt 6.4 was tested with than CMake 4.

For an update to install over the previous APK, raise `-DMP240_ANDROID_VERSION_CODE` and sign every build with the same key.

### Test the Kotlin side

```bash
scripts/android-kotlin-tests.sh
```

This runs the exercise-core unit tests and compiles the vendored bike library on the JVM. It needs no Qt build or device, only the Gradle wrapper from the Qt 6.4 Android kit. Outputs go to `build/android-kotlin/`: `androiddeployqt` copies `android/` whole, so nothing may be written there.

## Installing on the bike

Sideload as for soloton's apps (for example with [OpenPelo](https://github.com/doudar/Openpelo)), or over adb:

```bash
adb install -r build-android-bike/android-build/240mp.apk
```

Copy videos for **Local Files** to the tablet's shared storage (for example `/sdcard/Movies`) and point the module's media directory at them. The app asks for storage access on first launch.

### Checking the bike

Open **Exercise:Mode**. Ride Check shows the connection state and live cadence, resistance and output. If the bike never connects, choose **Bike Diagnostics** and follow soloton's [check-it-on-a-real-bike steps](android/vendor/bike/README.md#check-it-on-a-real-bike). The diagnostics screen also opens over adb:

```bash
adb shell am start -n com.mp240.app/dev.soloton.bike.BikeDiagnosticsActivity
```

## Limitations

- **Player.** mpv-only options are ignored on Android: the OSC mode, image slideshows (`imageContent`), extra mpv arguments and the transcode-offset display. Subtitle and audio cycle requests from mpv's OSC don't apply, because ExoPlayer's own controls switch tracks.
- **Modules.** NFC Reader, Scripts, YouTube and Weather aren't available on Android.
- **Network shares.** SMB2/3 only, one share at a time, and no server discovery: you type the address.
- **VLC fallback.** It plays the first audio track and turns on the first subtitle file; mpv's audio and subtitle track choices aren't passed to it. Shuffle isn't supported in it.
- **Resistance** is the bike library's spike-filtered value. soloton has not yet checked it on a real bike.

**Emulator rendering.** If the emulator falls back to software GL (its log says `Switching to software rendering`), Qt Quick draws a diagonal tear across highlighted rows and the AppBar icon is blank. Start the emulator with `-gpu host` instead; on a GPU both draw correctly.

## Not yet verified

- **Streaming from a network share on the bike:** browsing is confirmed, but not playback over the bike's Wi-Fi (watch for stutter on high-bitrate files).
- **Plex, Jellyfin and Emby streams** through ExoPlayer, including HTTPS through the bundled OpenSSL 1.1 and Plex sign-in. Only local files were played on the emulator.
- **A Bluetooth gamepad or remote** on the tablet.

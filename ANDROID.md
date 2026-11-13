# 240-MP on Android: the Peloton Bike (gen 1)

240-MP runs on the original Peloton Bike's tablet (Android 7.0, API 24, 1920x1080 landscape) as a sideloaded APK. Besides playing video, it adds **exercise mode**: the video plays only while the rider holds a target cadence and resistance, and the target can follow a workout laid over the length of the video, like a spin class.

The bike's sensors are read with [soloton](https://github.com/jasonsperske/soloton)'s bike library, vendored the same way [ExerDoom](https://github.com/jasonsperske/ExerDoom) vendors it.

> **Status:** the workout logic is unit tested (23 JVM tests). The Android Kotlin sources compile against Media3, the bike library and Qt 6.4's Java bindings. The C++ compiles with the NDK against Qt 6.4's Android headers, and the new QML passes `qmllint` and renders under Qt 6.4. The APK has not yet been built end to end, or run on an emulator or a bike (see [Not yet verified](#not-yet-verified)).

## How it fits together

Android follows the desktop's design: the shell browses, then hands off to a dedicated full-screen player, then resumes when the player closes. The desktop hands off to an mpv process. On Android the player is an Activity:

| Piece | Where | What it does |
|---|---|---|
| `AndroidPlayerController` | `src/player/` | Stands in for `MpvController` under the same QML name (`mpvController`) and with the same API, so every module's Player view works unchanged. `loadAndPlay` sends the request to `PlayerActivity` over JNI; progress and the end of playback come back as `positionChanged` / `playbackEnded`, as from mpv. |
| `PlayerActivity`, `RideHud` | `android/src/com/mp240/android/` | Media3 (ExoPlayer) playback, plus the exercise overlay and the ride gate. |
| `exercise-core` | `android/exercise-core/` | Plain Kotlin, unit tested on the JVM: difficulty levels, workout programs (`Program.build`) and the gate that decides whether the video may play (`RideGate`). |
| bike library | `android/vendor/bike-core`, `android/vendor/bike` | soloton's library, vendored unchanged (`android/vendor/UPSTREAM`; refresh with `scripts/sync-bike-lib.sh`). It binds Peloton's own sensor service and reports cadence, power and resistance. |
| Exercise module | `modules/exercise/`, `src/modules/exercise/` | The **Exercise:Mode** entry in the main menu. Its Ride Check screen shows the bike's live readings, holds the settings, previews the workout, and opens the bike library's diagnostics screen. |
| `MainActivity`, `TouchPad.qml` | `android/src/...`, `views/Components/` | Input. The tablet is touch-only, so an on-screen pad taps the same keys a gamepad would (`inputManager.tapKey`). Bluetooth gamepads and remotes are mapped to the keys the views already handle. |
| `AppBundle` | `src/platform/android/` | The QML, modules and assets ship inside the APK as Qt resources and are mirrored to app storage at startup, so `appRoot` is an ordinary directory, as on the desktop. |

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
~/Qt/6.4.3/android_arm64_v8a/bin/qt-cmake -G Ninja -B build-android -S . \
    -DANDROID_SDK_ROOT=$ANDROID_HOME \
    -DANDROID_NDK_ROOT=$ANDROID_HOME/ndk/23.1.7779620 \
    -DQT_HOST_PATH=$HOME/Qt/6.4.3/gcc_64 \
    -DMP240_ANDROID_OPENSSL_DIR=/path/to/android_openssl/ssl_1.1 \
    -DCMAKE_BUILD_TYPE=Release
cmake --build build-android --target apk
```

The APK lands in `build-android/android-build/build/outputs/apk/`. Use the `android_x86_64` kit's `qt-cmake` for soloton's gen 1 emulator (`scripts/gen1-emulator.sh` there). To build several ABIs into one APK, add `-DQT_ANDROID_BUILD_ALL_ABIS=ON` (or `-DQT_ANDROID_ABIS="arm64-v8a;armeabi-v7a"`). The bike's MT8173 is arm64-v8a.

For an update to install over the previous APK, raise `-DMP240_ANDROID_VERSION_CODE` and sign every build with the same key.

### Test the Kotlin side

```bash
scripts/android-kotlin-tests.sh
```

This runs the exercise-core unit tests and compiles the vendored bike library on the JVM. It needs no Qt build or device, only the Gradle wrapper from the Qt 6.4 Android kit. Outputs go to `build/android-kotlin/`: `androiddeployqt` copies `android/` whole, so nothing may be written there.

## Installing on the bike

Sideload as for soloton's apps (for example with [OpenPelo](https://github.com/doudar/Openpelo)), or over adb:

```bash
adb install -r build-android/android-build/build/outputs/apk/release/android-build-release-signed.apk
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
- **Resistance** is the bike library's spike-filtered value. soloton has not yet checked it on a real bike.

## Not yet verified

- An end-to-end `apk` build. The C++ was syntax-checked with the NDK against Qt 6.4's Android headers, but with the host's OpenSSL 3 headers in place of the 1.1 ones the APK links. Plex's Ed25519 code uses APIs OpenSSL 1.1.1 has, but it hasn't been compiled against 1.1.
- The app on soloton's gen 1 emulator, and on a real bike.

#!/usr/bin/env bash
# Builds and unit-tests the Android build's Kotlin libraries on the JVM, without Qt or a device:
# tests the workout programs and ride gate (exercise-core) and compiles the vendored bike library.
# (Upstream bike-core tests need Kotlin 2.4 overload resolution; run them in soloton.)
#
#   scripts/android-kotlin-tests.sh            test exercise-core, compile the bike library
#   scripts/android-kotlin-tests.sh :bike:assemble   any other Gradle task
#
# Needs JDK 17 and the Android SDK (ANDROID_HOME); uses Qt for Android's Gradle wrapper, so
# QT_ANDROID (default ~/Qt/6.4.3/android_arm64_v8a) must point at a Qt 6.4 Android kit.
set -euo pipefail
here="$(cd "$(dirname "$0")/.." && pwd)"
qt="${QT_ANDROID:-$HOME/Qt/6.4.3/android_arm64_v8a}"
gradlew="$qt/src/3rdparty/gradle/gradlew"
[ -f "$gradlew" ] || { echo "no Gradle wrapper at $gradlew (set QT_ANDROID)" >&2; exit 1; }
[ -n "${ANDROID_HOME:-}" ] || { echo "set ANDROID_HOME to the Android SDK" >&2; exit 1; }
if [ $# -eq 0 ]; then set -- :exercise-core:test :bike-core:jar :bike:assembleDebug; fi
# Outputs and Gradle's project cache stay out of android/, which androiddeployqt copies whole.
exec sh "$gradlew" -p "$here/android" --project-cache-dir "$here/build/android-kotlin/.gradle" "$@"

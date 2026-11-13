#pragma once
#include <QString>

// The app's QML, module folders and assets on Android.
//
// On the desktop, appRoot is a directory next to the binary (or inside the .app). An APK has
// no such directory, so the Android build compiles Main.qml, views/, modules/ and assets/ into
// Qt resources under ":/app" (CMakeLists.txt) and this mirrors them into the app's private
// storage at startup. appRoot then stays an ordinary directory and everything that builds
// paths from it (AppCore's module scan, QML file URLs, the player's font) works unchanged.
//
// Only files that differ are rewritten, so later launches cost a read-through, not a copy.
namespace appbundle {
// Mirrors the bundle and returns the directory to use as appRoot (empty on failure).
QString extract();
}

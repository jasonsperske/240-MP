# Android build: the gen 1 Peloton Bike's tablet (Android 7.0, API 24). See ANDROID.md.
#
# Included from CMakeLists.txt when configuring with Qt for Android 6.4 (the last Qt whose
# Android support reaches API 24). Provides OpenSSL::Crypto for the Plex backend and
# mp240_configure_android(), which bundles the QML and wires up the Gradle side in android/.

if(Qt6_VERSION VERSION_GREATER_EQUAL 6.5)
    message(WARNING "Qt ${Qt6_VERSION} for Android needs API 26 or later; the gen 1 Peloton "
                    "tablet is API 24. Build with Qt 6.4 (see ANDROID.md).")
endif()

# ── OpenSSL ───────────────────────────────────────────────────────────────────
# Qt 6.4's network backend loads OpenSSL 1.1 at runtime for HTTPS (as libssl_1_1.so /
# libcrypto_1_1.so), and the Plex backend links libcrypto for its Ed25519 device key, so the
# APK has to carry OpenSSL 1.1 built for Android. Nothing is downloaded: point
# MP240_ANDROID_OPENSSL_DIR at a directory laid out as
#     <dir>/include/openssl/*.h
#     <dir>/<abi>/libcrypto_1_1.so   <dir>/<abi>/libssl_1_1.so      (abi: arm64-v8a, x86_64, ...)
# which is the ssl_1.1/ folder of KDAB's android_openssl (the build Qt's documentation points
# to), or your own build of OpenSSL 1.1.1 with the NDK. See ANDROID.md.
set(MP240_ANDROID_OPENSSL_DIR "" CACHE PATH "OpenSSL 1.1 for Android: include/ and <abi>/lib*_1_1.so")
if(NOT MP240_ANDROID_OPENSSL_DIR)
    message(FATAL_ERROR "Set MP240_ANDROID_OPENSSL_DIR to OpenSSL 1.1 built for Android (see ANDROID.md)")
endif()
set(_mp240_ssl_lib "${MP240_ANDROID_OPENSSL_DIR}/${CMAKE_ANDROID_ARCH_ABI}")
foreach(_f "${MP240_ANDROID_OPENSSL_DIR}/include/openssl/evp.h"
           "${_mp240_ssl_lib}/libcrypto_1_1.so" "${_mp240_ssl_lib}/libssl_1_1.so")
    if(NOT EXISTS "${_f}")
        message(FATAL_ERROR "MP240_ANDROID_OPENSSL_DIR: missing ${_f}")
    endif()
endforeach()
add_library(OpenSSL::Crypto SHARED IMPORTED)
set_target_properties(OpenSSL::Crypto PROPERTIES
    IMPORTED_LOCATION "${_mp240_ssl_lib}/libcrypto_1_1.so"
    INTERFACE_INCLUDE_DIRECTORIES "${MP240_ANDROID_OPENSSL_DIR}/include")
set(MP240_ANDROID_OPENSSL_LIBS "${_mp240_ssl_lib}/libcrypto_1_1.so" "${_mp240_ssl_lib}/libssl_1_1.so")

# A multi-ABI build (QT_ANDROID_ABIS / QT_ANDROID_BUILD_ALL_ABIS) re-runs CMake once per extra
# ABI; these settings have to reach those runs too.
list(APPEND QT_ANDROID_MULTI_ABI_FORWARD_VARS MP240_ANDROID_OPENSSL_DIR MP240_ANDROID_VERSION_CODE)

# ── The app target ────────────────────────────────────────────────────────────
function(mp240_configure_android target)
    # QML, module folders and assets go into the APK as resources under :/app; at startup
    # platform/android/AppBundle.cpp mirrors them to storage and uses that as appRoot.
    # CONFIGURE_DEPENDS re-globs on each build, so new QML files are picked up.
    file(GLOB_RECURSE _bundle RELATIVE "${CMAKE_SOURCE_DIR}" CONFIGURE_DEPENDS
        "${CMAKE_SOURCE_DIR}/Main.qml"
        "${CMAKE_SOURCE_DIR}/views/*"
        "${CMAKE_SOURCE_DIR}/modules/*"
        "${CMAKE_SOURCE_DIR}/assets/*")
    # The Pi's boot splash is not needed on a tablet.
    list(FILTER _bundle EXCLUDE REGEX "boot-splash\\.tga$")
    qt_add_resources(${target} "app_bundle"
        PREFIX "/app"
        BASE "${CMAKE_SOURCE_DIR}"
        FILES ${_bundle})

    # InputManager compiles against a stand-in SDL (Android gamepads arrive as Qt key events).
    target_include_directories(${target} PRIVATE "${CMAKE_SOURCE_DIR}/src/platform/android")

    # Packaged into the APK; Qt's TLS backend finds libssl_1_1.so there at runtime.
    set_property(TARGET ${target} APPEND PROPERTY QT_ANDROID_EXTRA_LIBS ${MP240_ANDROID_OPENSSL_LIBS})

    # Version code: CI can pass -DMP240_ANDROID_VERSION_CODE (must rise with each release
    # for an update to install over the last).
    set(MP240_ANDROID_VERSION_CODE "1" CACHE STRING "Android versionCode")
    set_target_properties(${target} PROPERTIES
        QT_ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_SOURCE_DIR}/android"
        QT_ANDROID_MIN_SDK_VERSION 24
        QT_ANDROID_TARGET_SDK_VERSION 31
        QT_ANDROID_VERSION_NAME "${APP_VERSION}"
        QT_ANDROID_VERSION_CODE "${MP240_ANDROID_VERSION_CODE}"
        # Let androiddeployqt's import scanner see the QML (it is not in a QML module), so the
        # QtQuick, Qt5Compat.GraphicalEffects and other plugins it imports are packaged.
        QT_QML_ROOT_PATH "${CMAKE_SOURCE_DIR}")
endfunction()

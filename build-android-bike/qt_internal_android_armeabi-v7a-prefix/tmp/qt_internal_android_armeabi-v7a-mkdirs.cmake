# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file Copyright.txt or https://cmake.org/licensing for details.

cmake_minimum_required(VERSION ${CMAKE_VERSION}) # this file comes with cmake

# If CMAKE_DISABLE_SOURCE_CHANGES is set to true and the source directory is an
# existing directory in our source tree, calling file(MAKE_DIRECTORY) on it
# would cause a fatal error, even though it would be a no-op.
if(NOT EXISTS "/home/jason/dev/240-MP")
  file(MAKE_DIRECTORY "/home/jason/dev/240-MP")
endif()
file(MAKE_DIRECTORY
  "/home/jason/dev/240-MP/build-android-bike/android_abi_builds/armeabi-v7a"
  "/home/jason/dev/240-MP/build-android-bike/qt_internal_android_armeabi-v7a-prefix"
  "/home/jason/dev/240-MP/build-android-bike/qt_internal_android_armeabi-v7a-prefix/tmp"
  "/home/jason/dev/240-MP/build-android-bike/qt_internal_android_armeabi-v7a-prefix/src/qt_internal_android_armeabi-v7a-stamp"
  "/home/jason/dev/240-MP/build-android-bike/qt_internal_android_armeabi-v7a-prefix/src"
  "/home/jason/dev/240-MP/build-android-bike/qt_internal_android_armeabi-v7a-prefix/src/qt_internal_android_armeabi-v7a-stamp"
)

set(configSubDirs )
foreach(subDir IN LISTS configSubDirs)
    file(MAKE_DIRECTORY "/home/jason/dev/240-MP/build-android-bike/qt_internal_android_armeabi-v7a-prefix/src/qt_internal_android_armeabi-v7a-stamp/${subDir}")
endforeach()
if(cfgdir)
  file(MAKE_DIRECTORY "/home/jason/dev/240-MP/build-android-bike/qt_internal_android_armeabi-v7a-prefix/src/qt_internal_android_armeabi-v7a-stamp${cfgdir}") # cfgdir has leading slash
endif()

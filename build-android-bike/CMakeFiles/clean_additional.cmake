# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Release")
  file(REMOVE_RECURSE
  "240mp_autogen"
  "CMakeFiles/240mp_autogen.dir/AutogenUsed.txt"
  "CMakeFiles/240mp_autogen.dir/ParseCache.txt"
  )
endif()

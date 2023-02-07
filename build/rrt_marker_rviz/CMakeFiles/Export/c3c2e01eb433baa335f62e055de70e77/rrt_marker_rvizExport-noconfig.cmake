#----------------------------------------------------------------
# Generated CMake target import file.
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "rrt_marker_rviz::rrt_marker_rviz" for configuration ""
set_property(TARGET rrt_marker_rviz::rrt_marker_rviz APPEND PROPERTY IMPORTED_CONFIGURATIONS NOCONFIG)
set_target_properties(rrt_marker_rviz::rrt_marker_rviz PROPERTIES
  IMPORTED_LOCATION_NOCONFIG "${_IMPORT_PREFIX}/lib/rrt_marker_rviz/librrt_marker_rviz.so"
  IMPORTED_SONAME_NOCONFIG "librrt_marker_rviz.so"
  )

list(APPEND _cmake_import_check_targets rrt_marker_rviz::rrt_marker_rviz )
list(APPEND _cmake_import_check_files_for_rrt_marker_rviz::rrt_marker_rviz "${_IMPORT_PREFIX}/lib/rrt_marker_rviz/librrt_marker_rviz.so" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)

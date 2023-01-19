cmake_minimum_required(VERSION 3.8)
project(example_pkg_c)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(std_msgs REQUIRED)
find_package(visualization_msgs REQUIRED)
find_package(OpenCV REQUIRED)

add_library(example_pkg_c SHARED
            include/example_pkg_c/rrt_marker.hpp
            src/rrt_marker.cpp
            src/rrt_display.cpp
) 
ament_target_dependencies(example_pkg_c rclcpp std_msgs visualization_msgs OpenCV)

add_executable(rrt_display src/rrt_display.cpp)
target_link_libraries(rrt_display example_pkg_c)

target_include_directories(example_pkg_c PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
        $<INSTALL_INTERFACE:include>
        )

ament_export_targets(example_pkg_c HAS_LIBRARY_TARGET)
ament_export_dependencies(rclcpp std_msgs visualization_msgs OpenCV)

install(
        DIRECTORY include/
        DESTINATION include
)

install(TARGETS example_pkg_c 
        EXPORT example_pkg_c 
        DESTINATION lib/${PROJECT_NAME})

ament_package()

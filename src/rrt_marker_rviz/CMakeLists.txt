cmake_minimum_required(VERSION 3.8)
project(rrt_marker_rviz)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# find dependencies
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(std_msgs REQUIRED)
find_package(visualization_msgs REQUIRED)
find_package(OpenCV REQUIRED)

add_library(rrt_marker_rviz SHARED
            include/rrt_marker_rviz/rrt_marker.hpp
            src/rrt_marker.cpp
            src/rrt_display.cpp
) 
ament_target_dependencies(rrt_marker_rviz rclcpp std_msgs visualization_msgs OpenCV)

add_executable(rrt_display src/rrt_display.cpp)
target_link_libraries(rrt_display rrt_marker_rviz)

target_include_directories(rrt_marker_rviz PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
        $<INSTALL_INTERFACE:include>
        )

ament_export_targets(rrt_marker_rviz HAS_LIBRARY_TARGET)
ament_export_dependencies(rclcpp std_msgs visualization_msgs OpenCV)

install(
        DIRECTORY include/
        DESTINATION include
)

install(TARGETS rrt_marker_rviz 
        DESTINATION lib/${PROJECT_NAME}
        EXPORT rrt_marker_rviz )

ament_package()

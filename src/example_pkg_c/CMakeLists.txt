cmake_minimum_required(VERSION 3.8)
project(example_pkg_c)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(std_msgs REQUIRED)
find_package(visualization_msgs REQUIRED)

add_executable(ros2_example src/marker.cpp)
ament_target_dependencies(ros2_example rclcpp std_msgs visualization_msgs)

install(TARGETS ros2_example DESTINATION lib/${PROJECT_NAME})

ament_package()

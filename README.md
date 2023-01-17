# Display path in rviz2 using Marker in ros2

using "vsiualization_msgs/msg/marker.hpp"

cd ~/ros2_ws/

colcon build

source install/setup.bash

ros2 run example_pkg_c ros2_example

ros2 run rviz2 rviz2

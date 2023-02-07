# Display path in rviz2 using Marker in ros2

Using ros2 Marker to display path trajectory in rviz2 ("vsiualization_msgs/msg/marker.hpp")

### Installation Process
```
cd ~/ros2_ws/
colcon build
source install/setup.bash
```
### Execution process 
First Ternimal
```
./build/rrt_marker_rviz/rrt_display
```
Second Terminal
```
ros2 run rviz2 rviz2
```
Then subscribe the Marker topic in rviz2

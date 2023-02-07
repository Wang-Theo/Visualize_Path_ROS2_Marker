#include <iostream>
#include <vector>
#include "rrt_marker_rviz/rrt_marker.hpp"
using namespace std;

int main(int argc, char * argv[])
{
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<DisplayRRT>());
  rclcpp::shutdown();
  return 0;
}
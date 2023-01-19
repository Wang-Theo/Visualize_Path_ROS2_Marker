#include <iostream>
#include <vector>
#include "example_pkg_c/rrt_marker.hpp"
using namespace std;

int main(int argc, char * argv[])
{
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<DisplayRRT>());
  rclcpp::shutdown();
  return 0;
}
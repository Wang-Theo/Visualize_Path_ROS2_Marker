#include "rclcpp/rclcpp.hpp"
#include <visualization_msgs/msg/marker_array.hpp>
#include <unistd.h>
using namespace std::chrono_literals;

int main(int argc, char * argv[])
{
    rclcpp::init(argc, argv);
    auto node = rclcpp::Node::make_shared("test_rviz");

    auto pub = node->create_publisher<visualization_msgs::msg::Marker>("test_marker", rclcpp::QoS(1));
    while (!pub->get_subscription_count()) {
        sleep(1);
        std::cout << "sleep" << std::endl;
    }
    std::cout << "pub ->" << std::endl;
    visualization_msgs::msg::Marker marker;
    marker.header.stamp.sec = 0;
    marker.header.stamp.nanosec = 0;
    marker.header.frame_id="world";
    marker.ns = "while_line";
    marker.id = 0;
    marker.type = visualization_msgs::msg::Marker::LINE_LIST;
    marker.action = 0;
    marker.pose = geometry_msgs::msg::Pose();
    marker.scale.set__x(0.08);
    marker.color.a = 1.0;
    marker.color.b = 1.0;
    marker.color.g = 1.0;
    marker.color.r = 1.0;
    auto point1 = geometry_msgs::msg::Point();
    point1.x = 1.0;
    point1.y = 1.0;
    point1.z = 0.0;
    auto point2 = geometry_msgs::msg::Point();
    point2.x = 2.0;
    point2.y = 2.0;
    point2.z = 0.0;
    marker.points.push_back(point1);
    marker.points.push_back(point2);
    pub->publish(marker);
    rclcpp::spin(node);
    rclcpp::shutdown();
    return 0;
}
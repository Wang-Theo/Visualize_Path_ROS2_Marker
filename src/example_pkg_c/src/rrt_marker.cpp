#include <chrono>
#include <memory>
#include <cmath>
#include <unistd.h>

#include "rclcpp/rclcpp.hpp"
#include "rclcpp/rate.hpp"
#include "rclcpp/time.hpp"
#include "std_msgs/msg/string.hpp"
#include <visualization_msgs/msg/marker.hpp>

using namespace std::chrono_literals;

class DisplayRRT : public rclcpp::Node
{
  public:
    DisplayRRT()
    : Node("rrt_display"), count_(0)
    {
      publisher_ = this->create_publisher<visualization_msgs::msg::Marker>(
        "visualization_marker",rclcpp::QoS(1));

      timer_ = this->create_wall_timer(
      500ms, std::bind(&DisplayRRT::timer_callback, this));
    }
    
    float f = 0.0;

  private:
    void timer_callback()
    {
        while (!publisher_ ->get_subscription_count()) {
            sleep(1);
            std::cout << "sleep" << std::endl;
        }
        std::cout << "pub ->" << std::endl;

        while (rclcpp::ok()){

            visualization_msgs::msg::Marker points, line_strip, line_list;
            
            points.header.frame_id = line_strip.header.frame_id = line_list.header.frame_id = "map";
            points.header.stamp = line_strip.header.stamp = line_list.header.stamp = rclcpp::Clock(RCL_ROS_TIME).now();
            points.ns = line_strip.ns = line_list.ns = "points_and_lines";
            points.action = line_strip.action = line_list.action = visualization_msgs::msg::Marker::ADD;
            points.pose.orientation.w = line_strip.pose.orientation.w = line_list.pose.orientation.w = 1.0;

            points.id = 0;
            line_strip.id = 1;
            line_list.id = 2; 

            points.type = visualization_msgs::msg::Marker::POINTS;
            line_strip.type = visualization_msgs::msg::Marker::LINE_STRIP;
            line_list.type = visualization_msgs::msg::Marker::LINE_LIST;

            // POINTS markers use x and y scale for width/height respectively
            points.scale.x = 0.2;
            points.scale.y = 0.2;

            // LINE_STRIP/LINE_LIST markers use only the x component of scale, for the line width
            line_strip.scale.x = 0.1;
            line_list.scale.x = 0.1;

            // Points are green
            points.color.g = 1.0f;
            points.color.a = 1.0;
                
            // Line strip is blue
            line_strip.color.b = 1.0;
            line_strip.color.a = 1.0;

            // Line list is red
            line_list.color.r = 1.0;
            line_list.color.a = 1.0;

            // Create the vertices for the points and lines
            for (uint32_t i = 0; i < 100; ++i)
            {
                float y = 5 * sin(f + i / 100.0f * 2 * M_PI);
                float z = 5 * cos(f + i / 100.0f * 2 * M_PI);

                geometry_msgs::msg::Point p;
                p.x = (int32_t)i - 50;
                p.y = y;
                p.z = z;

                points.points.push_back(p);
                line_strip.points.push_back(p);

                // The line list needs two points for each line
                line_list.points.push_back(p);
                p.z += 1.0;
                line_list.points.push_back(p);
            }
        
            publisher_->publish(points); 
            publisher_->publish(line_strip);
            publisher_->publish(line_list);

            f += 0.04;
            sleep(1);
        }
        rclcpp::TimerBase::SharedPtr timer_;
        rclcpp::Publisher<std_msgs::msg::String>::SharedPtr publisher_;
        size_t count_;
    }
    rclcpp::TimerBase::SharedPtr timer_;
    rclcpp::Publisher<visualization_msgs::msg::Marker>::SharedPtr publisher_;
    size_t count_;
};

int main(int argc, char * argv[])
{
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<DisplayRRT>());
  rclcpp::shutdown();
  return 0;
}
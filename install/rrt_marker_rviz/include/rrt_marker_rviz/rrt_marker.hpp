#ifndef _RRT_H
#define _RRT_H

#include <chrono>
#include <memory>
#include <unistd.h>

#include <iostream>
#include <vector>
#include <cmath>
#include <random>

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

  private:
    void timer_callback();
    rclcpp::TimerBase::SharedPtr timer_;
    rclcpp::Publisher<visualization_msgs::msg::Marker>::SharedPtr publisher_;
    size_t count_;
};
#endif
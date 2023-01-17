#include <chrono>
#include <memory>

#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"
#include <visualization_msgs/msg/marker.hpp>

using namespace std::chrono_literals;

class HelloPublisher : public rclcpp::Node{
    public:
        HelloPublisher() : Node("hello_publisher"), count_(0){
            publisher_ = this->create_publisher<std_msgs::msg::String>("topic",10);
            timer_ = this->create_wall_timer(
            500ms, std::bind(&HelloPublisher::timer_callback, this));

        }
    private:
        void timer_callback(){
            auto message = std_msgs::msg::String();
            message.data = "Hello" + std::to_string(count_++);
            RCLCPP_INFO(this->get_logger(), "Pubulishing: %s", message.data.c_str());
            publisher_->publish(message); 
        }
        rclcpp::TimerBase::SharedPtr timer_;
        rclcpp::Publisher<std_msgs::msg::String>::SharedPtr publisher_;
        size_t count_; 
};

int main(int argc, char* argv[]){
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<HelloPublisher>());
    rclcpp::shutdown();
    return 0;
}
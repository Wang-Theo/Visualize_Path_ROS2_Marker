#include "rrt_marker_rviz/rrt_marker.hpp"

void DisplayRRT::timer_callback()
{
        while (!publisher_ ->get_subscription_count()) {
            sleep(1);
            std::cout << "sleep" << std::endl;
        }
        std::cout << "pub ->" << std::endl;

        double coor[5][5];
        double x1=coor[0][0];
        double y1=coor[0][1];
        double x2=coor[1][0];
        double y2=coor[1][1];

        while(rclcpp::ok()){
            // edge.edge.push_back(point);

            visualization_msgs::msg::Marker points, line_strip;
            
            points.header.frame_id = line_strip.header.frame_id = "map";
            points.header.stamp = line_strip.header.stamp = rclcpp::Clock(RCL_ROS_TIME).now();
            points.ns = line_strip.ns = "points_and_lines";
            points.action = line_strip.action = visualization_msgs::msg::Marker::ADD;
            points.pose.orientation.w = line_strip.pose.orientation.w = 1.0;

            points.id = 0;
            line_strip.id = 1;

            points.type = visualization_msgs::msg::Marker::POINTS;
            line_strip.type = visualization_msgs::msg::Marker::LINE_STRIP;

            // POINTS markers use x and y scale for width/height respectively
            points.scale.x = 0.2;
            points.scale.y = 0.2;

            // LINE_STRIP/LINE_LIST markers use only the x component of scale, for the line width
            line_strip.scale.x = 0.1;

            // Points are green
            points.color.g = 1.0f;
            points.color.a = 1.0;
                
            // Line strip is blue
            line_strip.color.b = 1.0;
            line_strip.color.a = 1.0;
            for (uint32_t i = 0; i < 10; ++i){
                // Create the vertices for the points and lines
                geometry_msgs::msg::Point p;
                x1=i;
                y1=i;
                x2=i+1;
                y2=i+1;
                // edge point1
                p.x = x1;
                p.y = y1;
                points.points.push_back(p);
                line_strip.points.push_back(p);
                // edge point2
                p.x = x2;
                p.y = y2;
                points.points.push_back(p);
                line_strip.points.push_back(p);
            }
        
            publisher_->publish(points); 
            publisher_->publish(line_strip);
            sleep(0.1);
        }
        rclcpp::TimerBase::SharedPtr timer_;
        rclcpp::Publisher<std_msgs::msg::String>::SharedPtr publisher_;
}
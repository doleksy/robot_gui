#include "robot_gui/teleoperation.h"

#include "robot_gui/cvui.h"

#include <iostream>


namespace
{
    const std::string   twist_topic_name      { "/cmd_vel" };
    const float         linear_velocity_step  { 0.1f };
    const float         angular_velocity_step { 0.1f };
}


Teleoperation::Teleoperation(ros::NodeHandle &nh)
    : twist_pub_{ nh.advertise<geometry_msgs::Twist>(twist_topic_name, 10) }
{
    std::cout << "... Robot Teleoperation Buttons constructed\n";
}

void Teleoperation::renderButtons()
{
    // Teleoperation Section - Containing Row
    cvui::beginRow(-1, -1, 0);
        // Teleoperation Section - Containing Column
        cvui::beginColumn(-1, -1, 5);
            cvui::beginRow(-1, -1, 5);
                cvui::rect(100, 50, 0x313431);
                if (cvui::button(100, 50, "Forward")) {
                    twist_msg_.linear.x += linear_velocity_step;
                }
                cvui::rect(100, 50, 0x313431);
            cvui::endRow();
            cvui::beginRow(-1, -1, 5);
                if (cvui::button(100, 50, "Left")) {
                    twist_msg_.angular.z += angular_velocity_step;
                }
                if (cvui::button(100, 50, "Stop")) {
                    twist_msg_.linear.x = 0;
                    twist_msg_.angular.z = 0;
                }
                if (cvui::button(100, 50, "Right")) {
                    twist_msg_.angular.z -= angular_velocity_step;
                }
            cvui::endRow();
            cvui::beginRow(-1, -1, 5);
                cvui::rect(100, 50, 0x313431);
                if (cvui::button(100, 50, "Backward")) {
                    twist_msg_.linear.x -= linear_velocity_step;
                }
                cvui::rect(100, 50, 0x313431);
            cvui::endRow();
        cvui::endColumn();
    cvui::endRow();

    twist_pub_.publish(twist_msg_);
}

#include "robot_gui/velocities.h"

#include "robot_gui/cvui.h"

#include <iostream>


namespace
{
    const std::string twist_topic_name{ "/cmd_vel" };
}

CurrentVelocities::CurrentVelocities(ros::NodeHandle &nh)
    : twist_sub_{ nh.subscribe<geometry_msgs::Twist>(twist_topic_name, 2, &CurrentVelocities::msgCallback, this) }
{
    std::cout << "... Robot Current Velocity constructed\n";
}

void CurrentVelocities::renderWindows()
{
    // Current Velocity Section - Containing Row
    cvui::beginRow(-1, -1, 0);
        // Current Velocity Section - Containing Column
        cvui::beginColumn(-1, -1, 5);
            cvui::beginRow(-1, -1, 4);
                auto * const rowBlock = &cvui::internal::topBlock(); 
                const auto * const winRect = &rowBlock->rect;
                cvui::window(153, 40, "Linear velocity:");
                cvui::printf(rowBlock->where, winRect->x + 60, winRect->y + 25, 0.4, 0xff0000, "%0.2f m/sec", twist_msg_.linear.x);

                cvui::window(153, 40, "Angular velocity:");
                cvui::printf(rowBlock->where, winRect->x + 153+4+60, winRect->y + 25, 0.4, 0xff0000, "%0.2f m/sec", twist_msg_.angular.z);
            cvui::endRow();
        cvui::endColumn();
    cvui::endRow();
}

void CurrentVelocities::msgCallback(const geometry_msgs::TwistConstPtr &msg)
{
    twist_msg_ = *msg;
    ROS_DEBUG("Twist: Linear x: %0.2f, angular z: %0.2f", msg->linear.x, msg->angular.z);
}

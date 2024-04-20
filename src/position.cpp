#include "robot_gui/position.h"

#include "robot_gui/cvui.h"


namespace
{
    const std::string odom_topic_name{ "/odom" };
}


OdometryPosition::OdometryPosition(ros::NodeHandle &nh)
    : odom_sub_{ nh.subscribe<nav_msgs::Odometry>(odom_topic_name, 2, &OdometryPosition::odomCallback, this) }
{
    std::cout << "... Robot Position (Odometry based) constructed\n";
}

void OdometryPosition::renderWindows()
{
    // Robot Position Section - Containing Row
    cvui::beginRow(-1, -1, 0);
        // Robot Position Section - Containing Column
        cvui::beginColumn(-1, -1, 5);
            cvui::text("Estimated robot position based off of odometry");
            cvui::beginRow(-1, -1, 5);
                auto * const rowBlock = &cvui::internal::topBlock(); 
                const auto * const winRect = &rowBlock->rect;
                cvui::window(100, 100, "X");
                cvui::printf(rowBlock->where, winRect->x + 5, winRect->y + 48, 0.70, 0xCECECE, "%+05.2f", odom_position_.x);

                cvui::window(100, 100, "Y");
                cvui::printf(rowBlock->where, winRect->x + 100+5+5, winRect->y + 48, 0.70, 0xCECECE, "%+05.2f", odom_position_.y);

                cvui::window(100, 100, "Z");
                cvui::printf(rowBlock->where, winRect->x + 200+10+5, winRect->y + 48, 0.70, 0xCECECE, "%+05.2f", odom_position_.z);
            cvui::endRow();
        cvui::endColumn();
    cvui::endRow();
}

void OdometryPosition::odomCallback(const nav_msgs::OdometryConstPtr &msg)
{
    odom_position_ = msg->pose.pose.position;
    ROS_DEBUG("Odom: position [x, y, z]: [%0.2f, %0.2f, %0.2f]", odom_position_.x, odom_position_.y, odom_position_.z);
}

#pragma once

#include "ros/node_handle.h"
#include "ros/subscriber.h"

#include "nav_msgs/Odometry.h"


class OdometryPosition
{
public:
    OdometryPosition() = delete;
    OdometryPosition(ros::NodeHandle &nh);

    void renderWindows();

private:
    void odomCallback(const nav_msgs::OdometryConstPtr &msg);

private:
    geometry_msgs::Point    odom_position_{};
    ros::Subscriber         odom_sub_;

};

#pragma once

#include "ros/node_handle.h"
#include "ros/subscriber.h"

#include "geometry_msgs/Twist.h"


class CurrentVelocities
{
public:
    CurrentVelocities() = delete;
    CurrentVelocities(ros::NodeHandle &nh);

    void renderWindows();

private:
  void msgCallback(const geometry_msgs::TwistConstPtr &msg);

private:
    geometry_msgs::Twist    twist_msg_{};
    ros::Subscriber         twist_sub_;

};

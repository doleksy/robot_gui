#pragma once

#include "ros/node_handle.h"
#include "ros/publisher.h"

#include <geometry_msgs/Twist.h>


class Teleoperation
{
public:
    Teleoperation() = delete;
    Teleoperation(ros::NodeHandle &nh);

    void renderButtons();

private:
    geometry_msgs::Twist    twist_msg_{};
    ros::Publisher          twist_pub_;
    
};

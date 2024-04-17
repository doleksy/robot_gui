#pragma once

#include "ros/node_handle.h"


class RobotGui
{
public:
    RobotGui(ros::NodeHandle &nh);

    void run();

private:
    const std::string WINDOW_NAME = "ROS Robot GUI";

};
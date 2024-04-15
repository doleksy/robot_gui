#pragma once

#include "ros/node_handle.h"


class RobotGui
{
public:
    RobotGui(ros::NodeHandle &nh);

    void run();

};
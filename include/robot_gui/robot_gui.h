#pragma once

#include "ros/node_handle.h"

#include "robot_gui/teleoperation.h"


class RobotGui
{
public:
    RobotGui(ros::NodeHandle &nh);

    void run();

private:
    Teleoperation teleoperation_;

};
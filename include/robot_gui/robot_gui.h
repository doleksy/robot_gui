#pragma once

#include "ros/node_handle.h"

#include "teleoperation.h"
#include "velocities.h"


class RobotGui
{
public:
    RobotGui(ros::NodeHandle &nh);

    void run();

private:
    CurrentVelocities velocities_;
    Teleoperation teleoperation_;

};
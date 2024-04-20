#pragma once

#include "ros/node_handle.h"

#include "distance.h"
#include "info_area.h"
#include "position.h"
#include "teleoperation.h"
#include "velocities.h"


class RobotGui
{
public:
    RobotGui(ros::NodeHandle &nh);

    void run();

private:
    CurrentVelocities   velocities_;
    DistanceTraveled    distance_;
    GeneralInfoArea     infoArea_;
    OdometryPosition    position_;
    Teleoperation       teleoperation_;

};
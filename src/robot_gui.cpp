#include "robot_gui/robot_gui.h"
#include "ros/node_handle.h"

// debug
#include <iostream>

RobotGui::RobotGui(ros::NodeHandle &nh)
{
    std::cout << "RobotGui constructed\n";
}

void RobotGui::run()
{
    std::cout << "RobotGui::run()\n";
}

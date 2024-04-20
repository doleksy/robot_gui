#pragma once

#include "ros/node_handle.h"
#include "ros/subscriber.h"

#include "robotinfo_msgs/RobotInfo10Fields.h"


class GeneralInfoArea
{
public:
    GeneralInfoArea() = delete;
    GeneralInfoArea(ros::NodeHandle &nh);

    void renderArea();

private:
    void infoCallback(const robotinfo_msgs::RobotInfo10FieldsConstPtr &msg);

private:
    robotinfo_msgs::RobotInfo10Fields   robot_info_{};
    ros::Subscriber                     info_sub_;

};

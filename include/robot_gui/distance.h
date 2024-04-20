#pragma once

#include "ros/node_handle.h"
#include "ros/service_client.h"

#include "std_srvs/Trigger.h"

#include <string>


class DistanceTraveled
{
public:
    DistanceTraveled() = delete;
    DistanceTraveled(ros::NodeHandle &nh);

    void render();

private:
    ros::ServiceClient  srv_client_;
    std_srvs::Trigger   srv_trigger_req_{};

    std::string         last_distance_msg_{ "XXXXXX" };

};

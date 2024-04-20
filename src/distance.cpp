#include "robot_gui/distance.h"

#include "robot_gui/cvui.h"


namespace
{
    const std::string service_name{ "/get_distance" };
}


DistanceTraveled::DistanceTraveled(ros::NodeHandle &nh)
    : srv_client_{ nh.serviceClient<std_srvs::Trigger>(service_name) }
{
    std::cout << "... Robot Distance Traveled Service constructed\n";
}

void DistanceTraveled::render()
{
    // Distance Traveled Service Section - Containing Row
    cvui::beginRow(-1, -1, 0);
        // Distance Traveled Service - Containing Column
        cvui::beginColumn(-1, -1, 5);
            cvui::text("Distance traveled:");
            cvui::beginRow(-1, -1, 5);
                auto * const rowBlock = &cvui::internal::topBlock(); 
                const auto * const winRect = &rowBlock->rect;

                // Call the distance service
                if (cvui::button(100, 100, "Call")) {
                    // Send the request and wait for a response
                    if (srv_client_.call(srv_trigger_req_)) {
                        ROS_DEBUG("Response message: %s", srv_trigger_req_.response.message.c_str());

                        last_distance_msg_ = srv_trigger_req_.response.message;
                    }
                    else {
                        last_distance_msg_ = "XXXXXX";
                    }
                }

                cvui::window(205, 100, "Distance in meters:");
                cvui::printf(rowBlock->where, winRect->x + 100+5+21, winRect->y + 48, 1.0, 0xCECECE, "%s", last_distance_msg_.c_str());
            cvui::endRow();
        cvui::endColumn();
    cvui::endRow();
}

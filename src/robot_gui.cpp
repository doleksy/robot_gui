
#include <opencv2/opencv.hpp>
#define CVUI_IMPLEMENTATION
#include "robot_gui/cvui.h"

#include "robot_gui/robot_gui.h"

#include "robot_gui/distance.h"
#include "robot_gui/info_area.h"
#include "robot_gui/position.h"

#include <iostream>


namespace
{
    const std::string WINDOW_NAME = "ROS Robot GUI";
}


RobotGui::RobotGui(ros::NodeHandle &nh)
    : teleoperation_(nh)
    , velocities_(nh)
{
    std::cout << "RobotGui constructed\n";
}

void RobotGui::run()
{
    cv::Mat frame = cv::Mat(cv::Size(350, 700), CV_8UC3);

    DistanceTraveled distance;
    GeneralInfoArea infoArea;
    OdometryPosition position;

    // Init a OpenCV window and tell cvui to use it
    cv::namedWindow(WINDOW_NAME);
    cvui::init(WINDOW_NAME);

    while (ros::ok())
    {
        frame = cv::Scalar(49, 52, 49);

        // Create the main columnn
        cvui::beginColumn(frame, 20, 20, -1, -1, 5);
            teleoperation_.renderButtons();
            velocities_.renderWindows();
            cvui::rect(310, 5, 0x819E5C);
            cvui::space(1);
            position.renderWindows();
            cvui::rect(310, 5, 0x819E5C);
            cvui::space(1);
            distance.render();
            cvui::rect(310, 5, 0x819E5C);
            cvui::space(1);
            infoArea.renderArea();
        cvui::endColumn();

        // Show everything on the screen
	    cvui::imshow(WINDOW_NAME, frame);

        if (cv::waitKey(20) == 27) {
            break;
        }

        ros::spinOnce();
    }
}


#include <opencv2/opencv.hpp>
#define CVUI_IMPLEMENTATION
#include "robot_gui/cvui.h"

#include "robot_gui/robot_gui.h"
#include "robot_gui/teleoperation.h"
#include "robot_gui/velocities.h"

// debug
#include <iostream>


RobotGui::RobotGui(ros::NodeHandle &nh)
{
    std::cout << "RobotGui constructed\n";
}

void RobotGui::run()
{
    cv::Mat frame = cv::Mat(cv::Size(400, 800), CV_8UC3);

    CurrentVelocities velocities;
    Teleoperation teleoperation;

    // Init a OpenCV window and tell cvui to use it
    cv::namedWindow(WINDOW_NAME);
    cvui::init(WINDOW_NAME);

    while(true) {
        frame = cv::Scalar(49, 52, 49);

        // Create the main columnn
        cvui::beginColumn(frame, 20, 20, -1, -1, 5);
            teleoperation.renderButtons();
            velocities.renderWindows();
        cvui::endColumn();

        // Show everything on the screen
	    cvui::imshow(WINDOW_NAME, frame);

        if (cv::waitKey(20) == 27) {
            break;
        }
    }
}

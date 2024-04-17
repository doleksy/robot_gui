
#include <opencv2/opencv.hpp>
#define CVUI_IMPLEMENTATION
#include "robot_gui/cvui.h"

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
    cv::Mat frame = cv::Mat(cv::Size(400, 800), CV_8UC3);

    // Init a OpenCV window and tell cvui to use it
    cv::namedWindow(WINDOW_NAME);
    cvui::init(WINDOW_NAME);

    while(true) {
        frame = cv::Scalar(49, 52, 49);

        // Create the main columnn
        cvui::beginColumn(frame, 20, 20, -1, -1, 5);
            cvui::text("Main Column");
            cvui::beginRow(-1, -1, 5);
                cvui::rect(100, 50, 0xff0000);
                cvui::button(100, 50, "Forward");
                cvui::rect(100, 50, 0xff0000);
            cvui::endRow();
            cvui::beginRow(-1, -1, 5);
                cvui::button(100, 50, "Left");
                cvui::button(100, 50, "Stop");
                cvui::button(100, 50, "Right");
            cvui::endRow();
            cvui::beginRow(-1, -1, 5);
                cvui::rect(100, 50, 0xff0000);
                cvui::button(100, 50, "Reverse");
                cvui::rect(100, 50, 0xff0000);
            cvui::endRow();
        cvui::endColumn();

        // Show everything on the screen
	    cvui::imshow(WINDOW_NAME, frame);

        if (cv::waitKey(20) == 27) {
            break;
        }
    }
}

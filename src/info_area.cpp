#include "robot_gui/info_area.h"

#include "robot_gui/cvui.h"


namespace
{
    const std::string info_topic_name{ "/robot_info" };
}


GeneralInfoArea::GeneralInfoArea(ros::NodeHandle &nh)
    : info_sub_{ nh.subscribe<robotinfo_msgs::RobotInfo10Fields>(info_topic_name, 2, &GeneralInfoArea::infoCallback, this) }
{
    std::cout << "... Robot General Information Area constructed\n";
}

void GeneralInfoArea::renderArea()
{
    constexpr const int xOffset{ 5 };

    // General Info Area Section - Containing Row
    cvui::beginRow(-1, -1, 0);
        // General Info Area - Containing Column
        cvui::beginColumn(-1, -1, 5);
            auto * const rowBlock = &cvui::internal::topBlock(); 
            const auto * const winRect = &rowBlock->rect;
            cvui::window(310, 220, "Info:");
            cvui::printf(rowBlock->where, winRect->x + xOffset, winRect->y + 24, "%s", robot_info_.data_field_01.c_str());
            cvui::printf(rowBlock->where, winRect->x + xOffset, winRect->y + 44, "%s", robot_info_.data_field_02.c_str());
            cvui::printf(rowBlock->where, winRect->x + xOffset, winRect->y + 64, "%s", robot_info_.data_field_03.c_str());
            cvui::printf(rowBlock->where, winRect->x + xOffset, winRect->y + 84, "%s", robot_info_.data_field_04.c_str());
            cvui::printf(rowBlock->where, winRect->x + xOffset, winRect->y + 104, "%s", robot_info_.data_field_05.c_str());
            cvui::printf(rowBlock->where, winRect->x + xOffset, winRect->y + 124, "%s", robot_info_.data_field_06.c_str());
            cvui::printf(rowBlock->where, winRect->x + xOffset, winRect->y + 144, "%s", robot_info_.data_field_07.c_str());
            cvui::printf(rowBlock->where, winRect->x + xOffset, winRect->y + 164, "%s", robot_info_.data_field_08.c_str());
            cvui::printf(rowBlock->where, winRect->x + xOffset, winRect->y + 184, "%s", robot_info_.data_field_09.c_str());
            cvui::printf(rowBlock->where, winRect->x + xOffset, winRect->y + 204, "%s", robot_info_.data_field_10.c_str());
        cvui::endColumn();
    cvui::endRow();
}

void GeneralInfoArea::infoCallback(const robotinfo_msgs::RobotInfo10FieldsConstPtr &msg)
{
    robot_info_ = *msg;
    ROS_DEBUG("Robot Info: data01: %s, data02: %s", robot_info_.data_field_01.c_str(), robot_info_.data_field_02.c_str());
}

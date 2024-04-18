#include "robot_gui/teleoperation.h"

#include "robot_gui/cvui.h"


void Teleoperation::renderTeleoperation()
{
    // Teleoperation Section - Containing Row
    cvui::beginRow(-1, -1, 0);
        // Teleoperation Section - Containing Column
        cvui::beginColumn(-1, -1, 5);
            cvui::beginRow(-1, -1, 5);
                cvui::rect(100, 50, 0x313431);
                cvui::button(100, 50, "Forward");
                cvui::rect(100, 50, 0x313431);
            cvui::endRow();
            cvui::beginRow(-1, -1, 5);
                cvui::button(100, 50, "Left");
                cvui::button(100, 50, "Stop");
                cvui::button(100, 50, "Right");
            cvui::endRow();
            cvui::beginRow(-1, -1, 5);
                cvui::rect(100, 50, 0x313431);
                cvui::button(100, 50, "Reverse");
                cvui::rect(100, 50, 0x313431);
            cvui::endRow();
            cvui::space(5);
            cvui::beginRow(-1, -1, 4);
                auto * const rowBlock = &cvui::internal::topBlock(); 
                const auto * const winRect = &rowBlock->rect;
                cvui::window(153, 40, "Linear velocity:");
                // Replace with printf once we hook up the actual controls
                cvui::text(rowBlock->where, winRect->x + 60, winRect->y + 25, "0.00 m/sec", 0.4, 0xff0000);
                cvui::window(153, 40, "Angular velocity:");
                // Replace with printf once we hook up the actual controls
                cvui::text(rowBlock->where, winRect->x + 153+4+60, winRect->y + 25, "0.00 m/sec", 0.4, 0xff0000);
            cvui::endRow();
        cvui::endColumn();
    cvui::endRow();
}

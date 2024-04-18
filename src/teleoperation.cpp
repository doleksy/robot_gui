#include "robot_gui/teleoperation.h"

#include "robot_gui/cvui.h"


void Teleoperation::renderButtons()
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
        cvui::endColumn();
    cvui::endRow();
}

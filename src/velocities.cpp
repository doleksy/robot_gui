#include "robot_gui/velocities.h"

#include "robot_gui/cvui.h"


void CurrentVelocities::renderWindows()
{
    // Current Velocity Section - Containing Row
    cvui::beginRow(-1, -1, 0);
        // Current Velocity Section - Containing Column
        cvui::beginColumn(-1, -1, 5);
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

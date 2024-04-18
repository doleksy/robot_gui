#include "robot_gui/position.h"

#include "robot_gui/cvui.h"


void OdometryPosition::renderWindows()
{
    // Robot Position Section - Containing Row
    cvui::beginRow(-1, -1, 0);
        // Robot Position Section - Containing Column
        cvui::beginColumn(-1, -1, 5);
            cvui::text("Estimated robot position based off of odometry");
            cvui::beginRow(-1, -1, 5);
                auto * const rowBlock = &cvui::internal::topBlock(); 
                const auto * const winRect = &rowBlock->rect;
                cvui::window(100, 100, "X");
                // Replace with printf once we hook up the actual controls
                cvui::text(rowBlock->where, winRect->x + 21, winRect->y + 48, "065", 1.0);
                cvui::window(100, 100, "Y");
                // Replace with printf once we hook up the actual controls
                cvui::text(rowBlock->where, winRect->x + 100+5+21, winRect->y + 48, "268", 1.0);
                cvui::window(100, 100, "Z");
                // Replace with printf once we hook up the actual controls
                cvui::text(rowBlock->where, winRect->x + 200+10+21, winRect->y + 48, "359", 1.0);
            cvui::endRow();
        cvui::endColumn();
    cvui::endRow();
}

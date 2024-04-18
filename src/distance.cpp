#include "robot_gui/distance.h"
#include "robot_gui/cvui.h"


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
                cvui::button(100, 100, "Call");
                cvui::window(205, 100, "Distance in meters:");
                // Replace with printf once we hook up the actual controls
                cvui::text(rowBlock->where, winRect->x + 100+5+21, winRect->y + 48, "00124689", 1.0);
            cvui::endRow();
        cvui::endColumn();
    cvui::endRow();
}

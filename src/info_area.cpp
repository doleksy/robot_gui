#include "robot_gui/info_area.h"

#include "robot_gui/cvui.h"


void GeneralInfoArea::renderArea()
{
    constexpr const int xOffset{ 5 };

    // General Info Area Section - Containing Row
    cvui::beginRow(-1, -1, 0);
        // General Info Area - Containing Column
        cvui::beginColumn(-1, -1, 5);
            auto * const rowBlock = &cvui::internal::topBlock(); 
            const auto * const winRect = &rowBlock->rect;
            cvui::window(310, 140, "Info:");
            // Replace with printf once we hook up the actual controls
            cvui::text(rowBlock->where, winRect->x + xOffset, winRect->y + 24, "0.00 Info 1");
            // Replace with printf once we hook up the actual controls
            cvui::text(rowBlock->where, winRect->x + xOffset, winRect->y + 44, "255.00 Info 2");
            // Replace with printf once we hook up the actual controls
            cvui::text(rowBlock->where, winRect->x + xOffset, winRect->y + 64, "255.00 Info 3");
            // Replace with printf once we hook up the actual controls
            cvui::text(rowBlock->where, winRect->x + xOffset, winRect->y + 84, "255.00 Info 4");
            // Replace with printf once we hook up the actual controls
            cvui::text(rowBlock->where, winRect->x + xOffset, winRect->y + 104, "255.00 Info 5");
            // Replace with printf once we hook up the actual controls
            cvui::text(rowBlock->where, winRect->x + xOffset, winRect->y + 124, "255.00 Info 6");
        cvui::endColumn();
    cvui::endRow();
}

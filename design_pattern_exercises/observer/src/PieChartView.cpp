#include "PieChartView.h"
#include <iostream>

namespace PieChartView
{
    int PieChartView::getId() const noexcept
    {
        return 2;
    }

    void PieChartView::update()
    {
        std::cout << "Update of PieChartView." << std::endl;
    }
}
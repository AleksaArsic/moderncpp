#include "BarChartView.h"
#include <iostream>

namespace BarChartView
{
    int BarChartView::getId() const noexcept
    {
        return 3;
    }

    void BarChartView::update()
    {
        std::cout << "Update of BarChartView." << std::endl;
    }
}
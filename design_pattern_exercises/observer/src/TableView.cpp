#include "TableView.h"
#include <iostream>

namespace TableView
{
    int TableView::getId() const noexcept
    {
        return 1;
    }

    void TableView::update()
    {
        std::cout << "Update of TableView." << std::endl;
    }
}
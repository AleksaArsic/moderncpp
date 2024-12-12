#include "SpreadsheetModel.h"
#include <iostream>

namespace SpreadsheetModel
{
    void SpreadsheetModel::changeCellValue(std::string_view column, const int row, const double value)
    {
        // ... Other non-implemented functionality
        std::cout << "Chaning cell value at column = " << column
                  << ", row = " << row << ". New value is " << value << std::endl;

        notifyAllObservers();
        // ... Other non-implemented functionality
    }
}
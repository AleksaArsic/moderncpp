#pragma once
#include <string_view>
#include "Subject.h"

namespace SpreadsheetModel
{
    class SpreadsheetModel : public Subject::Subject
    {
        public:
            // ... Other non-implemented functionality
            void changeCellValue(std::string_view column, const int row, const double value);
            // ... Other non-implemented functionality
    };   
}
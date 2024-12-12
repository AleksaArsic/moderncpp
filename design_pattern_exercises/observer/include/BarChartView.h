#pragma once
#include "SpreadsheetModel.h"

namespace BarChartView
{
    class BarChartView : public Observer::Observer
    {
        public:
            explicit BarChartView(SpreadsheetModel::SpreadsheetModel& model) : model { model }
            { }

            virtual int getId() const noexcept override;
            virtual void update() override;
            
        private:
            SpreadsheetModel::SpreadsheetModel& model;
    };
}
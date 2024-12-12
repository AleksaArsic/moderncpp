#pragma once
#include "SpreadsheetModel.h"

namespace PieChartView
{
    class PieChartView : public Observer::Observer
    {
        public:
            explicit PieChartView(SpreadsheetModel::SpreadsheetModel& model) : model { model }
            { }

            virtual int getId() const noexcept override;
            virtual void update() override;
            
        private:
            SpreadsheetModel::SpreadsheetModel& model;
    };
}
#pragma once
#include "SpreadsheetModel.h"

namespace TableView
{
    class TableView : public Observer::Observer
    {
        public:
            explicit TableView(SpreadsheetModel::SpreadsheetModel& model) : model { model }
            { }

            virtual int getId() const noexcept override;
            virtual void update() override;

        private:
            SpreadsheetModel::SpreadsheetModel& model;
    };
}
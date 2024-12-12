#include <iostream>
#include <memory>
#include "SpreadSheetModel.h"
#include "TableView.h"
#include "PieChartView.h"
#include "BarChartView.h"

int main()
{
    // Construt the model
    SpreadsheetModel::SpreadsheetModel model;

    // Construct views
    TableView::TableView tableView{ model };
    PieChartView::PieChartView pieChartView{ model };
    BarChartView::BarChartView barChartView{ model };
    
    std::shared_ptr<PieChartView::PieChartView> pieChartViewPtr = std::make_shared<PieChartView::PieChartView>(pieChartView);
    // Add observers to the model
    model.addObserver(std::make_shared<TableView::TableView>(tableView));
    //model.addObserver(pieChartViewPtr);
    model.addObserver(std::make_shared<PieChartView::PieChartView>(pieChartView));

    // Change the value of "A1" to 3.3
    model.changeCellValue("A", 1, 3.3);

    // Add another observer to the model
    model.addObserver(std::make_shared<BarChartView::BarChartView>(barChartView));

    // Remove one of the observers
    //model.removeObserver(pieChartViewPtr);
    model.removeObserver(std::make_shared<PieChartView::PieChartView>(pieChartView));

    // Change the value of "B2" to 6.6
    model.changeCellValue("B", 2, 6.6);

    return 0;
}
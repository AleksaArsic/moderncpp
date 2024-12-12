#include <iostream>
#include <memory>
#include "Point.h"
#include "DrawingProcessor.h"
#include "DrawCircleCommand.h"
#include "DrawRectangleCommand.h"
#include "CommandProcessor.h"
#include "UndoCommand.h"
#include "CompositeCommand.h"

int main()
{
    DrawingProcessor::DrawingProcessor drawingProcessor;
    CommandProcessor::CommandProcessor commandProcessor;

    double x = 0.0;
    double y = 0.0;
    double radius = 1.0;

    // Draw 10 circles
    for (int i = 0; i < 10; ++i)
    {
        Point::Point centerPoint{ x++, y++ };
        DrawCircleCommand::DrawCircleCommand drawCircleCommand{ drawingProcessor, centerPoint, radius++ };
        
        commandProcessor.execute(std::make_shared<DrawCircleCommand::DrawCircleCommand>(drawCircleCommand));
    }

    double width = 1.0;
    double height = 2.0; 

    for (int i = 0; i < 5; ++i)
    {
        Point::Point topLeftPoint{ x++, y++ };
        DrawRectangleCommand::DrawRectangleCommand drawRectangleCommand{ drawingProcessor, topLeftPoint, width++, height++ };

        commandProcessor.execute(std::make_shared<DrawRectangleCommand::DrawRectangleCommand>(drawRectangleCommand));
    }

    // Undo last three commands
    std::cout << "Execute CommandProcessor::CommandProcessor.undoLastCommand(): " << std::endl;
    for (int i = 0; i < 3; ++i)
    {
        commandProcessor.undoLastCommand();
    }

    // Use UndoCommand::UndoCommand to undo commands from CommandProcessor::CommandProcessor
    UndoCommand::UndoCommand undoCommand(commandProcessor);

    // Execute UndoCommand::UndoCommand to undo last two commands from CommandProcessor:CommandProcessor
    std::cout << "Execute UndoCommand::UndoCommand.execute():" << std::endl;

    undoCommand.execute();
    undoCommand.execute();

    // Use CompositeCommand to add new commands and execute them
    x = 0.0;
    y = 0.0;
    width = 3.0;
    height = 1.0;
    Point::Point rectangleTopLeftPoint{ x, y };
    DrawRectangleCommand::DrawRectangleCommand drawRectangleCommand{ drawingProcessor, rectangleTopLeftPoint, width, height };

    x = 5.0;
    y = 12.0;
    radius = 6.0;
    Point::Point circleCenterPoint{ x, y };
    DrawCircleCommand::DrawCircleCommand drawCircleCommand{ drawingProcessor, circleCenterPoint, radius };

    CompositeCommand::CompositeCommand compositeCommand;

    compositeCommand.addCommand(std::make_shared<DrawRectangleCommand::DrawRectangleCommand>(drawRectangleCommand));
    compositeCommand.addCommand(std::make_shared<DrawCircleCommand::DrawCircleCommand>(drawCircleCommand));

    // Execute composite commands
    compositeCommand.execute();

    // Undo composite commands in reverse order.
    compositeCommand.undo();

    return 0;
}
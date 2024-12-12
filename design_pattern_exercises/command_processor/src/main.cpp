#include <iostream>
#include <memory>
#include "Point.h"
#include "DrawingProcessor.h"
#include "DrawCircleCommand.h"
#include "CommandProcessor.h"
#include "UndoCommand.h"

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

    return 0;
}
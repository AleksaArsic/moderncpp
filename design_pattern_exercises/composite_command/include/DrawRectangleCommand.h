#pragma once
#include "Command.h"
#include "DrawingProcessor.h"
#include "Point.h"

namespace DrawRectangleCommand
{
    class DrawRectangleCommand : public Command::UndoableCommand
    {
        public:
            DrawRectangleCommand() = delete;

            DrawRectangleCommand(DrawingProcessor::DrawingProcessor& reciever, Point::Point topLeftPoint, double width, double height) :
                reciever { reciever }, topLeftPoint { topLeftPoint }
            {
                dimensions.width = width;
                dimensions.height = height;
            }

            virtual void execute() override;
            virtual void undo() override;
        private:
            struct Dimension
            {
                double width;
                double height;
            };

            DrawingProcessor::DrawingProcessor& reciever;
            Point::Point topLeftPoint;
            Dimension dimensions { 0.0, 0.0 };
    };
}
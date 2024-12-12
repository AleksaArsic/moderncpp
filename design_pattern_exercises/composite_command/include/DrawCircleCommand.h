#pragma once 
#include "Command.h"
#include "Point.h"
#include "DrawingProcessor.h"

namespace DrawCircleCommand
{
    class DrawCircleCommand : public Command::UndoableCommand
    {
        public:
            DrawCircleCommand() = delete;

            DrawCircleCommand(DrawingProcessor::DrawingProcessor& reciever, const Point::Point& centerPoint, const double radius) noexcept :
                reciever { reciever }, centerPoint { centerPoint }, radius { radius }
            { }

            virtual void execute() override;
            virtual void undo() override;

        private:
            DrawingProcessor::DrawingProcessor& reciever;
            Point::Point centerPoint;
            double radius;
    };
}
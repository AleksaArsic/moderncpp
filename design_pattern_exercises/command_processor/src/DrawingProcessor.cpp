#include "DrawingProcessor.h"
#include <iostream>

namespace DrawingProcessor
{
    void DrawingProcessor::drawCircle(const Point::Point& centerPoint, const double radius)
    {
        // Instructions to draw a circle on the screen ...
        std::cout << "Drawing the Circle at the centerPoint (" << centerPoint.getX() 
                  << ", " << centerPoint.getY() << ")." << std::endl;
    }

    void DrawingProcessor::eraseCricle(const Point::Point& centerPoint, const double radius)
    {
        // Instructions to erase a circle from the screen ...
        std::cout << "Erasing the Circle from the centerPoint (" << centerPoint.getX() 
            << ", " << centerPoint.getY() << ")." << std::endl;
    }
}
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
        std::cout << "Erasing the Circle at the centerPoint (" << centerPoint.getX() 
                  << ", " << centerPoint.getY() << ")." << std::endl;
    }

    void DrawingProcessor::drawRectangle(const Point::Point& topLeftPoint, const double width, const double height)
    {
        // Instructions to draw a rectangle on the screen ...
        std::cout << "Drawing the Rectangle at the top left point (" << topLeftPoint.getX() 
                  << ", " << topLeftPoint.getY() << "), with width = " << width << " and height = " << height
                  << "." << std::endl;
    }

    void DrawingProcessor::eraseRectangle(const Point::Point& topLeftPoint, const double width, const double height)
    {
        // Instructions to erase a rectangle from the screen ...
        std::cout << "Erasing the Rectangle at the top left point (" << topLeftPoint.getX() 
                  << ", " << topLeftPoint.getY() << "), with width = " << width << " and height = " << height 
                  << "." << std::endl;
    }
}
#pragma once
#include "Point.h"

namespace DrawingProcessor
{
    class DrawingProcessor
    {
        public:
            // ... Other non-implemented functionality 

            void drawCircle(const Point::Point& centerPoint, const double radius);
            void eraseCricle(const Point::Point& centerPoint, const double radius);

            void drawRectangle(const Point::Point& topLeftPoint, const double width, const double height);
            void eraseRectangle(const Point::Point& topLeftPoint, const double width, const double height);
            
            // ... Other non-implemented functionality 
        private:
            // ... Other non-implemented functionality 
    };
}
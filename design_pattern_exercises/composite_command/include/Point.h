#pragma once

namespace Point
{
    class Point
    {
        public:
            Point() : x { 0 }, y { 0 }
            { }

            Point(const double x, const double y) : x { x }, y { y }
            { }

            void setX(const double x) noexcept;
            void setY(const double y) noexcept;
            void setXY(const double x, const double y) noexcept;

            double getX() const noexcept;
            double getY() const noexcept;
        private:
            double x;
            double y;
    };
}
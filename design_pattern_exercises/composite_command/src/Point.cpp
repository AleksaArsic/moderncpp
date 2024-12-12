#include "Point.h"

namespace Point
{
    void Point::setX(const double x) noexcept
    {
        this->x = x;
    }

    void Point::setY(const double y) noexcept
    {
        this->y = y;
    }

    void Point::setXY(const double x, const double y) noexcept
    {
        this->x = x;
        this->y = y;
    }

    double Point::getX() const noexcept
    {
        return this->x;
    }

    double Point::getY() const noexcept
    {
        return this->y;
    }

}
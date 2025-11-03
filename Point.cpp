#include "Point.hpp"

Point::Point(int x_, int y_): x{x_}, y{y_} {}            // Constructor initializes the point with given grid coordinates

int Point::getX() const {                                // Returns the X coordinate of the point
    return x;
}

int Point::getY() const {                                // Returns the Y coordinate of the point
    return y;
}
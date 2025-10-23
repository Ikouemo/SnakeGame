#include "Point.hpp"

Point::Point(int x_, int y_): x{x_}, y{y_} {}

int Point::getX() const {
    return x;
}

int Point::getY() const {
    return y;
}
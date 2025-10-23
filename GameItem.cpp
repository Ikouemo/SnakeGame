#include "GameItem.hpp"


GameItem::GameItem(int x, int y): position(x, y) {
    
}

Point& GameItem::getPosition() {
    return position;
}

const Point& GameItem::getPosition() const {
    return position;
}
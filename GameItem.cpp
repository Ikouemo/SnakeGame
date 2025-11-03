#include "GameItem.hpp"


// Constructor initializes the internal position with given coordinates
GameItem::GameItem(int x, int y): position(x, y) {
    
}

// Returns a non-const reference to the position, allowing modification of the object's coordinates
Point& GameItem::getPosition() {
    return position;
}
// Returns a const reference to the position, used when the object should not be modified
const Point& GameItem::getPosition() const {
    return position;
}
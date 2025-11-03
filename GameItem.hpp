#pragma once

#include "Point.hpp"
#include<SFML/Graphics.hpp>

class GameItem {

private:
    Point position;                                                       // Position of the item in grid coordinates (x, y)

public:
    GameItem(int x, int y);                                               // Constructor initializes position
    Point& getPosition();                                                 // Getter for position (non-const version, allows modification)
    const Point& getPosition() const;                                     // Getter for position (const version, read-only
    virtual void paintGame(sf::RenderWindow& window) = 0;                 // Abstract function for rendering the item, each derived class must implement its own drawing behavior
    virtual ~GameItem() = default;                                        // Virtual destructor for safe polymorphic deletion

};
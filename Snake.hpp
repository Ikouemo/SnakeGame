#pragma once
#include "Point.hpp"
#include "GameItem.hpp"

#include<vector>
#include<memory>

class Snake {

public:
    Snake(int x, int y, int length);                           // Constructor: initializes a snake at (x, y) with a specific starting length
    Snake(int x, int y);                                       // Constructor: initializes a snake at (x, y) with a default length
    enum class Direction{ RIGHT, DOWN, LEFT, UP};              // Enum representing possible movement directions of the snake
    void setNextDirection(Direction direction);                // Stores the direction that should be applied in the next step
    void step();                                               // Moves the snake one step in its current direction
    void grow(int amount);                                     // Makes the snake longer by a given number of segments
    bool collidesWith(const GameItem& item) const;             // Collision check with another GameItem (e.g., walls, apple)
    bool collidesWith(int x, int y) const;                     // Collision check with a specific grid coordinate
    bool collidesWithSelf() const;                             // Checks if the snake hits its own body
    void paintGame(sf::RenderWindow& window);                  // // Draws the snake on the SFML window             

private:
    Direction nextDirection;                                   // Direction the snake is going to change to in the next movement
    Direction lastDirection;                                   // The last applied direction (prevents immediate 180° turns)
    std::vector<std::unique_ptr<Point>> points;


};
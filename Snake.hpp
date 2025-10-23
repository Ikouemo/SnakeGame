#pragma once
#include "Point.hpp"
#include "GameItem.hpp"

#include<vector>
#include<memory>

class Snake {

public:
    Snake(int x, int y, int length);
    Snake(int x, int y);
    enum class Direction{ RIGHT, DOWN, LEFT, UP};
    void setNextDirection(Direction direction);
    void step();
    void grow(int amount);
    bool collidesWith(const GameItem& item) const;
    bool collidesWith(int x, int y) const;
    bool collidesWithSelf() const;
    void paintGame(sf::RenderWindow& window);

private:
    Direction nextDirection;
    Direction lastDirection;
    std::vector<std::unique_ptr<Point>> points;


};
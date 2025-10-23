#pragma once

#include "Point.hpp"
#include<SFML/Graphics.hpp>

class GameItem {

private:
    Point position;

public:
    GameItem(int x, int y);
    Point& getPosition(); // für nicht-const Objekte
    const Point& getPosition() const; // für const Objekte
    virtual void paintGame(sf::RenderWindow& window) = 0;
    virtual ~GameItem() = default;

};
#pragma once

#include "GameItem.hpp"

class Brick: public GameItem {

public:
    Brick(int x, int y);
    void paintGame(sf::RenderWindow& window) override;


};
#pragma once

#include "GameItem.hpp"

class Apple: public GameItem {

private:
    static int  nextValue;
    const int VALUE;

public:
    Apple(int x, int y);
    void paintGame(sf::RenderWindow& window) override;
    int getValue() const;


};
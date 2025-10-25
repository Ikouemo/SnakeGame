#pragma once

#include "GameItem.hpp"

class Apple: public GameItem {

private:

    const int VALUE;
    static int  nextValue;
    

public:
    Apple(int x, int y);
    void paintGame(sf::RenderWindow& window) override;
    int getValue() const;


};
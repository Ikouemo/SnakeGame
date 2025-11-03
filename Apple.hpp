// Represents an apple that can be collected by the snake.
// Apples give the player points and are drawn on the game board.

#pragma once

#include "GameItem.hpp"

class Apple: public GameItem {

private:

    const int VALUE;                                                      // Points awarded when this apple is eaten. VALUE is constant per apple instance.
    static int  nextValue;                                                // Static counter used to vary the value for each new apple, if desired.
    

public:
    Apple(int x, int y);                                                  // Constructor to create an apple at the given grid position.
    void paintGame(sf::RenderWindow& window) override;
    int getValue() const;                                                 // Returns the point value of the apple.


};
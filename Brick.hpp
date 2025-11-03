//The first class derived from GameItem should be Brick. 
// Objects of this class should be used to define a wall to prevent the snake from leaving the playing field.

#pragma once

#include "GameItem.hpp"

class Brick: public GameItem {                                    

public:
    Brick(int x, int y);                                         // Constructor sets the brick's world grid position
    void paintGame(sf::RenderWindow& window) override;           // Renders the brick on the screen
 

};
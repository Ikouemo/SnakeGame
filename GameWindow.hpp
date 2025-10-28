#pragma once

#include<SFML/Graphics.hpp>

class GameWindow {

public:
    void start();
    
    virtual void paintGame(sf::RenderWindow& window) = 0;
    virtual bool updateGame(double time) = 0;
    virtual void handleInput(sf::Keyboard::Key keyCode) = 0;

    virtual ~GameWindow() = default;

};


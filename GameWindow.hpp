#ifndef GAMEWINDOW_HPP
#define GAMEWINDOW_HPP

#include <SFML/Graphics.hpp>

class GameWindow {
protected:
    sf::RenderWindow* window = nullptr;

    virtual void handleInput(sf::Keyboard::Key keyCode) = 0;
    virtual bool updateGame(double delta) = 0;
    virtual void paintGame(sf::RenderWindow& window) = 0;
    virtual void reset() = 0;  // Wird von abgeleiteten Klassen implementiert

public:
    virtual ~GameWindow() {
        if (window) {
            delete window;
        }
    }

    void start();
    void resetGame();  // Wird in GameWindow implementiert
};

#endif
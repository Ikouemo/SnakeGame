
// Abstract base class for a game window and game loop handling.

#pragma once

#include <SFML/Graphics.hpp> 

class GameWindow {
protected:
    sf::RenderWindow* window = nullptr;                        // Pointer to the SFML Renderwindow

    virtual void handleInput(sf::Keyboard::Key keyCode) = 0;   // handle keyboard input
    virtual bool updateGame(double delta) = 0;                 // Update game logic
    virtual void paintGame(sf::RenderWindow& window) = 0;      // Draw the game objects
    virtual void reset() = 0;                                  // Reset the game state

public:

    // Virtual destructor cleans up RenderWindow if allocated
    virtual ~GameWindow() {
        if (window) {
            delete window;
        }
    }

    void start();                                               // Starts the main game loop 
    void resetGame();                                          // Restarts the game state
};

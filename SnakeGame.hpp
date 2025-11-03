/**
 * Main class of the game ‘Snake’.
 *
 * This class manages:
 *  - Game logic (collisions, apple, score)
 *  - Player input
 *  - Rendering of game objects
 *
 * It derives from GameWindow and overrides the virtual methods required there
 * for game behaviour.
 */

#pragma once

#include "GameWindow.hpp"
#include "Snake.hpp"
#include "Brick.hpp"
#include "Apple.hpp"

#include<vector>
#include<string>
#include<memory>
#include<chrono>
#include<vector>
#include<SFML/Graphics.hpp>

class SnakeGame: public GameWindow {

public:

   static constexpr int SQUARE_SIZE = 16;                 // Stores the edge length of a grid square in pixels
   static constexpr int GROW_AMOUNT = 5;                  // Number of squares by which the snake should grow per apple
    
    SnakeGame();
    void paintGame(sf::RenderWindow& window) override;     // Draws all game elements (wall, apple, snake, UI)
    bool updateGame(double time) override;                 // Updates the game depending on the elapsed time
    void handleInput(sf::Keyboard::Key keyCode) override;  // Controls direction changes and restart
    void showDialog (const std::string& message);          // Displays an information/score message at the top of the window.
    

private:
    int width {};
    int height {};
    int score {0};                                          // Current score
    std::chrono::steady_clock::time_point lastSnakeUpdate;  // Time stamp for movement
    bool checkCollisions();                                 // Checks for self-collisions, wall collisions, and apple contact
    void createNewApple();                                  // Places a new apple in a random location
    std::unique_ptr<Snake> snake;
    std::unique_ptr<Apple> apple;
    std::vector<std::unique_ptr<Brick>> wall;
    sf::RenderWindow window;
    sf::Text dialogText;                                    // UI text above the game field
    sf::Font font;                                          // font for UI
    bool gameOver {false};                                  // Check the game state

    void reset() override;                                  // Completely resets the game

};
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

   static constexpr int SQUARE_SIZE = 16;  // öffentlich & statisch → überall zugreifbar
   static constexpr int GROW_AMOUNT = 5;
    
    SnakeGame();
    void paintGame(sf::RenderWindow& window) override;
    void updateGame(double time) override;
    void handleInput(sf::Keyboard::Key keyCode) override;
    void showDialog (const std::string& message);
    

private:
    int width {};
    int height {};
    int score {0};
    std::chrono::steady_clock::time_point lastSnakeUpdate;
    bool checkCollisions();
    void createNewApple();
    std::unique_ptr<Snake> snake;
    std::unique_ptr<Apple> apple;
    std::vector<std::unique_ptr<Brick>> wall;
    sf::RenderWindow window;
    sf::Text dialogText;
    sf::Font font;
};
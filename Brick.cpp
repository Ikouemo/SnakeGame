#include "Brick.hpp"
#include "SnakeGame.hpp"


Brick::Brick(int x, int y): GameItem(x, y) {                         

}

void Brick::paintGame(sf::RenderWindow& window) {
    sf::RectangleShape rect(sf::Vector2f(SnakeGame::SQUARE_SIZE, SnakeGame::SQUARE_SIZE));
    rect.setFillColor(sf::Color::Red);
    auto pos = getPosition();
    sf::Vector2f pixelPos(
        static_cast<float>(pos.getX() * SnakeGame::SQUARE_SIZE), 
        static_cast<float>(pos.getY() * SnakeGame::SQUARE_SIZE)
    );

    rect.setPosition(pixelPos);
    
    window.draw(rect);

    
}
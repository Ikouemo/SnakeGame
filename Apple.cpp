#include "Apple.hpp"
#include "SnakeGame.hpp"

int Apple::nextValue = 1;

Apple::Apple(int x, int y): GameItem(x, y), VALUE{nextValue++} {
    
}

int Apple::getValue() const {
    return VALUE;
}

void Apple::paintGame(sf::RenderWindow& window) {
    
    sf::CircleShape circle(SnakeGame::SQUARE_SIZE / 2.0f);
    circle.setFillColor(sf::Color::Green);

    sf::Vector2f pos(
        static_cast<float>(getPosition().getX() * SnakeGame::SQUARE_SIZE), 
        static_cast<float>(getPosition().getY() * SnakeGame::SQUARE_SIZE)
    );

    circle.setPosition(pos);
    window.draw(circle);

    
}

#include "Apple.hpp"
#include "SnakeGame.hpp"

// Initialize static value counter for apples.
int Apple::nextValue = 1;                                                            

// Constructor:
// Creates an apple at the given grid position and assigns a point value.
// VALUE increases with each newly created apple (1, 2, 3, ...)
Apple::Apple(int x, int y): GameItem(x, y), VALUE{nextValue++} {
    
}

// Returns the score value of this apple.
int Apple::getValue() const {
    return VALUE;
}

// Draws the apple as a green circle at its grid position.
void Apple::paintGame(sf::RenderWindow& window) {
    
    // The circle radius is half of the square size so it fits perfectly in the grid
    sf::CircleShape circle(SnakeGame::SQUARE_SIZE / 2.0f);
    circle.setFillColor(sf::Color::Green);

    // Convert grid coordinates to pixel coordinates
    sf::Vector2f pos(
        static_cast<float>(getPosition().getX() * SnakeGame::SQUARE_SIZE), 
        static_cast<float>(getPosition().getY() * SnakeGame::SQUARE_SIZE)
    );

    circle.setPosition(pos);
    window.draw(circle);

    
}

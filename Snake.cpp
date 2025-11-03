#include "Snake.hpp"
#include "SnakeGame.hpp"

#include<iostream>
#include<stdexcept>
#include<SFML/Graphics.hpp>


Snake::Snake(int x, int y, int length) {
     // Validate length input
     if(length <= 0 ) {
          throw std::invalid_argument("Ungültiges Argument");                                                       // Throws exception for invalid length
     }
     points.resize(length);                                                                                         // Allocate memory for snake body segment
     points.at(0) = std::make_unique<Point>(x, y);                                                                  // Create the head of snake at given position


}
Snake::Snake(int x, int y): Snake(x, y, 5) {

     std::cout << "Snake mit Standardlänge 5 erzeugt." << std::endl;                                                 // Default snake length set to 5

}

void Snake::paintGame(sf::RenderWindow& window) {
     for(int i = 0; i < points.size(); i++){                                                                         // Draw each body segment on the screen
          if(points.at(i) != nullptr){
               sf::RectangleShape rect(sf::Vector2f(SnakeGame::SQUARE_SIZE, SnakeGame::SQUARE_SIZE));                // Create a visual square for each segment
               rect.setFillColor(sf::Color::Blue);
               sf::Vector2f pos(
                    static_cast<float>(points.at(i)->getX() * SnakeGame::SQUARE_SIZE),                               // Convert grid coordinates to screen space
                    static_cast<float>(points.at(i)->getY() * SnakeGame::SQUARE_SIZE)
               );
               rect.setPosition(pos);
               window.draw(rect);

          }
     }

}

void Snake::setNextDirection(Direction direction) {
     nextDirection = direction;                                                                                      // Store input direction for the next move

}

void Snake::step() {
     if(points.empty())                                                                                              // If snake has no segments -> nothing to do
          return;

     
     Point head = *points.front();                                                                                  // Copy current head position
     
     int newX = head.getX();
     int newY = head.getY();

     switch (nextDirection)                                                                                        // Update based on direction while preventing opposite turn
     {
          case Direction::UP:
               if(lastDirection != Direction::DOWN)
                    newY--;
                break;
          case Direction::DOWN:
               if(lastDirection != Direction::UP)
                     newY++;
               break;
          case Direction::LEFT:
               if(lastDirection != Direction::RIGHT)
                    newX--;
               break;
          case Direction::RIGHT:
               if(lastDirection != Direction::LEFT)
                    newX++;
               break;
          default:
               break;
     }

     points.insert(points.begin(), std::make_unique<Point>(newX, newY));                                           // Insert new head at front 
     points.pop_back();                                                                                            // remove last segment 
     lastDirection = nextDirection;                                                                                // Update direction lock

}

bool Snake::collidesWith(const GameItem& item) const {

     // Check collision with a GameItem by using its coordinates
     const Point& pos = item.getPosition();
     return collidesWith(pos.getX(), pos.getY());

}

bool Snake::collidesWith(int x, int y) const{

     // Loop through all snake segments, check if any matches coordinates
     for(const auto& p: points){
          if(p && p->getX() == x && p->getY() == y) {
               return true;
          }
     }
     return false;

}

bool Snake::collidesWithSelf() const {

     // Snake must be at least 2 segments long to collide with itself
     if(points.size() < 2)
          return false;
     
     // Compare head to rest of body
     const auto& h = points.front();
     for(size_t i = 1; i < points.size(); i++) {
          if(points.at(i) && h->getX() == points.at(i)->getX() && h->getY() == points.at(i)->getY())
               return true;
     }

     return false;

}

void Snake::grow(int amount) {

     // Validate grow amount
     if(amount < 0 || amount < SnakeGame::GROW_AMOUNT)
          throw std::invalid_argument("amount muss >= GROW_AMOUNT und nicht negativ sein.");
     
     // Copy current tail location to grow additional segments
     auto& tail = points.back();
     int tailX = tail->getX();
     int tailY = tail->getY();

     for(int i = 0; i < amount; i++) {
          points.push_back(std::make_unique<Point>(tailX, tailY));
     }

}
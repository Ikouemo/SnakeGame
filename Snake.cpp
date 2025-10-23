#include "Snake.hpp"
#include "SnakeGame.hpp"

#include<iostream>
#include<stdexcept>
#include<SFML/Graphics.hpp>


Snake::Snake(int x, int y, int length) {
     if(length <= 0 ) {
          throw std::invalid_argument("Ungültiges Argument");
     }
     points.resize(length);
     points.at(0) = std::make_unique<Point>(x, y);


}
Snake::Snake(int x, int y): Snake(x, y, 5) {

     std::cout << "Snake mit Standardlänge 5 erzeugt." << std::endl;

}

void Snake::paintGame(sf::RenderWindow& window) {
     for(int i = 0; i < points.size(); i++){
          if(points.at(i) != nullptr){
               sf::RectangleShape rect(sf::Vector2f(SnakeGame::SQUARE_SIZE, SnakeGame::SQUARE_SIZE));
               rect.setFillColor(sf::Color::Blue);
               sf::Vector2f pos(
                    static_cast<float>(points.at(i)->getX() * SnakeGame::SQUARE_SIZE), 
                    static_cast<float>(points.at(i)->getY() * SnakeGame::SQUARE_SIZE)
               );
               rect.setPosition(pos);
               window.draw(rect);

          }
     }

}

void Snake::setNextDirection(Direction direction) {
     nextDirection = direction;

}

void Snake::step() {
     if(points.empty())
          return;

     // Kopfposition holen
     Point head = *points.front();
     
     int newX = head.getX();
     int newY = head.getY();

     switch (nextDirection)
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

     points.insert(points.begin(), std::make_unique<Point>(newX, newY));
     points.pop_back();
     lastDirection = nextDirection;

}

bool Snake::collidesWith(const GameItem& item) const {
     const Point& pos = item.getPosition();
     return collidesWith(pos.getX(), pos.getY());

}

bool Snake::collidesWith(int x, int y) const{
     for(const auto& p: points){
          if(p && p->getX() == x && p->getY() == y) {
               return true;
          }
     }
     return false;

}

bool Snake::collidesWithSelf() const {
     if(points.size() < 2)
          return false;
     
     const auto& h = points.front();

     for(size_t i = 1; i < points.size(); i++) {
          if(points.at(i) && h->getX() == points.at(i)->getX() && h->getY() == points.at(i)->getY())
               return true;
     }

     return false;

}

void Snake::grow(int amount) {
     if(amount < 0 || amount < SnakeGame::GROW_AMOUNT)
          throw std::invalid_argument("amount muss >= GROW_AMOUNT und nicht negativ sein.");
     
     auto& tail = points.back();
     int tailX = tail->getX();
     int tailY = tail->getY();

     for(int i = 0; i < amount; i++) {
          points.push_back(std::make_unique<Point>(tailX, tailY));
     }

}
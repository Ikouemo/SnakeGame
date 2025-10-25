#include "SnakeGame.hpp"
#include<iostream>
#include<string>
#include<memory>
#include<chrono>
#include<random>
#include<SFML/Graphics.hpp>

constexpr auto STEP_TIME = 100;
constexpr int WINDOW_WIDHT = 800;
constexpr int WINDOW_HEIGHT = 600;


SnakeGame::SnakeGame(): dialogText(font, "") {

    width = WINDOW_WIDHT / SQUARE_SIZE;
    height = WINDOW_HEIGHT / SQUARE_SIZE;

    snake = std::make_unique<Snake>(width / 2, height / 2);

    lastSnakeUpdate = std::chrono::steady_clock::now();

    wall.reserve((width + height) * 2);

    for(int x = 0; x < width; x++) {
        wall.push_back(std::make_unique<Brick>(x, 0));  // obere Wand
         wall.push_back(std::make_unique<Brick>(x, height - 1));; // untere Wand
    }


    for(int y = 1; y < height - 1; y++) {
        wall.push_back(std::make_unique<Brick>(0, y));;  // linke Wand
        wall.push_back(std::make_unique<Brick>(width - 1, y));; // recte Wand
    }
    createNewApple();
    
    if(!font.openFromFile("arial.ttf")){
        std::cerr << " Failed to load font!" << std::endl;
        exit(1);
    }

        // Font setzen
    dialogText.setCharacterSize(24);
    dialogText.setFillColor(sf::Color::White);
    //dialogText.setPosition(100.f, 100.f); // Position im Fenster
 
}

void SnakeGame::paintGame(sf::RenderWindow& window) {

    // Wand zeichnen
    for (auto& b : wall) {
        b->paintGame(window);
    }

    // Apple zeichnen
    if(apple)
        apple->paintGame(window);

    // snake zeichnen
    snake->paintGame(window);

    // dialog zeichnen
    window.draw(dialogText);
}

void SnakeGame::updateGame( double time ) {
    using namespace std::chrono;
    auto now = steady_clock::now();
    auto elapsed = duration_cast<milliseconds> (now - lastSnakeUpdate).count();

    if(elapsed < STEP_TIME) return; // noch kein Schritt fällig

    int steps = elapsed / STEP_TIME; // wie viele ganze Schritte ausführen

    for(int i = 0; i < steps; i++) {

        snake->step();
        lastSnakeUpdate += milliseconds(STEP_TIME);
        //checkCollisions();
    }
    
}

void SnakeGame::handleInput(sf::Keyboard::Key keyCode) {
    switch (keyCode)
    {
        case sf::Keyboard::Key::Up:
            snake->setNextDirection(Snake::Direction::UP);
            snake->step();
            break;
        case sf::Keyboard::Key::Down:
            snake->setNextDirection(Snake::Direction::DOWN);
            snake->step();
            break;
        case sf::Keyboard::Key::Right:
            snake->setNextDirection(Snake::Direction::RIGHT);
            snake->step();
            break;
        case sf::Keyboard::Key::Left:
            snake->setNextDirection(Snake::Direction::LEFT);
            snake->step();
            break;
        case sf::Keyboard::Key::Unknown:
            std::cerr << "Direction undefined. " << std::endl;        
        default:
            break;
   } 
    
}

bool SnakeGame::checkCollisions() {
    for(auto& w: wall) {
        if(snake->collidesWith(*w)){
            showDialog(" You died!\nScore: " + std::to_string(score));
            window.close();
            return true;
            
        }
    }
    if(snake->collidesWithSelf()) {
        showDialog(" Self collision\nScore: " + std::to_string(score));
        window.close();
        return true;
        
    }

    if(snake->collidesWith(apple->getPosition().getX(), apple->getPosition().getY())) {
        snake->grow(GROW_AMOUNT);
        score = score + apple->getValue();
        showDialog(" Your Score is: " + std::to_string(score));
        createNewApple();
    }
    return false;

}

void SnakeGame::showDialog(const std::string& message){
    dialogText.setString(message);

}

void SnakeGame::createNewApple() {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<>distX(1, width - 2);
    std::uniform_int_distribution<>distY(1, height - 2);

    int x, y;

    do {
         x = distX(gen);
         y = distY(gen);

    } while (snake->collidesWith(x, y));
   
    apple = std::make_unique<Apple>(x, y);


}
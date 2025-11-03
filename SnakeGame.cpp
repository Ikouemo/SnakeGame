#include "SnakeGame.hpp"
#include<iostream>
#include<string>
#include<memory>
#include<chrono>
#include<random>
#include<SFML/Graphics.hpp>

constexpr auto STEP_TIME = 100;                                     // Specifies the time between two steps in milliseconds
constexpr int WINDOW_WIDHT = 800;
constexpr int WINDOW_HEIGHT = 600;


SnakeGame::SnakeGame(): dialogText(font, "") {

    width = WINDOW_WIDHT / SQUARE_SIZE;
    height = WINDOW_HEIGHT / SQUARE_SIZE;

    snake = std::make_unique<Snake>(width / 2, height / 2);        // Creaate a snake in the center

    lastSnakeUpdate = std::chrono::steady_clock::now();            // initialize timing

    wall.reserve((width + height) * 2);                            // reserve memory for border walls

    // Create top and bottom wall
    for(int x = 0; x < width; x++) {
        wall.push_back(std::make_unique<Brick>(x, 0));             // Top wall
         wall.push_back(std::make_unique<Brick>(x, height - 1));   // Bottom wall
    }

    // Create left and right wall
    for(int y = 1; y < height - 1; y++) {
        wall.push_back(std::make_unique<Brick>(0, y));;             // Left wall
        wall.push_back(std::make_unique<Brick>(width - 1, y));;     // Right wall
    }
    createNewApple();                                               // place first apple

    // Load font UI
    if(!font.openFromFile("arial.ttf")){
        std::cerr << " Failed to load font!" << std::endl;
        exit(1);
    }

    // Configure UI text
    dialogText.setCharacterSize(15);
    dialogText.setFillColor(sf::Color::White);
    
 
}

void SnakeGame::paintGame(sf::RenderWindow& window) {

    // Draw wall
    for (auto& b : wall) {
        b->paintGame(window);
    }

    // Draw apple if exists
    if(apple)
        apple->paintGame(window);

    // Draw snake body
    snake->paintGame(window);

    // Draw score / message text
    window.draw(dialogText);

}

bool SnakeGame::updateGame( double time ) {

    if(gameOver)
        return true;                                                  // Game is frozen but window still runs

    using namespace std::chrono;
    auto now = steady_clock::now();
    auto elapsed = duration_cast<milliseconds> (now - lastSnakeUpdate).count();

    // Not time to move yet -> skip frame
    if(elapsed < STEP_TIME) 
        return true;                  

    int steps = elapsed / STEP_TIME;                                  // how many whole steps to take

    for(int i = 0; i < steps; i++) {

        snake->step();                                                // Move the snake one tile
        lastSnakeUpdate += milliseconds(STEP_TIME);
        if(checkCollisions())
            return false;                                             // Dead -> tells GameWindow loop to stop updating
    }

    return true;                                                      // Game continues
    
}

void SnakeGame::handleInput(sf::Keyboard::Key keyCode) {

    if(gameOver) {
        if (keyCode == sf::Keyboard::Key::R) {
            resetGame();                                              // Full restart the game through base class logic
            return;
        }
        return;
    }

    // Change direction based on pressed key and move immediately
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

// Check against wall collision
bool SnakeGame::checkCollisions() {
    for(auto& w: wall) {
        if(snake->collidesWith(*w)){
            showDialog(" You died!\nScore: " + std::to_string(score));
            gameOver = true;
            return true;
            
        }
    }

    // Check snake hitting itself
    if(snake->collidesWithSelf()) {
        showDialog(" Self collision\nScore: " + std::to_string(score));
        gameOver = true;
        return true;
        
    }

    if(snake->collidesWith(apple->getPosition().getX(), apple->getPosition().getY())) {
        snake->grow(GROW_AMOUNT);                                                           // Increase snake length
        score = score + apple->getValue();                                                  // Update score
        showDialog(" Your Score is: " + std::to_string(score));
        createNewApple();                                                                   // Create new apple
    }
    return false;

}

void SnakeGame::showDialog(const std::string& message){
    dialogText.setString(message);
    dialogText.setPosition({10.0f, 10.0f});


}

void SnakeGame::createNewApple() {

    // Random number generator for apple placement
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<>distX(1, width - 2);
    std::uniform_int_distribution<>distY(1, height - 2);

    int x, y;

    // Ensure apple does not spawn inside snake
    do {
         x = distX(gen);
         y = distY(gen);

    } while (snake->collidesWith(x, y));
   
    apple = std::make_unique<Apple>(x, y);


}
void SnakeGame::reset() {
    
    snake = std::make_unique<Snake>(width / 2, height / 2);                                      // Recreate snake in the center 

    gameOver = false;                                                                            // Reset game state

    score = 0;                                                                                   // Reset score

    lastSnakeUpdate = std::chrono::steady_clock::now();                                          // Reset movement timer

    createNewApple();                                                                            // New apple

    dialogText.setString("");                                                                    // Remove old message
}
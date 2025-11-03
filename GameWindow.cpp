#include "GameWindow.hpp"
#include <SFML/Graphics.hpp>
#include <chrono>

void GameWindow::resetGame() {
    // Close window if available
    if (window && window->isOpen()) {
        window->close();
        delete window;
        window = nullptr;
    }

    // Create a new window
    window = new sf::RenderWindow(sf::VideoMode(sf::Vector2u(800, 600)), "Snake");

    // Reset the game state
    reset();
}

void GameWindow::start() {
    // Create a window if is not yet created
    if (!window) {
        window = new sf::RenderWindow(sf::VideoMode(sf::Vector2u(800, 600)), "Snake");
    }

    auto last = std::chrono::steady_clock::now();

    // Main game loop
    while(window->isOpen()) {
        // Process events
        while(auto eventOpt = window->pollEvent()) {
            const sf::Event& event = *eventOpt;
            if(event.is<sf::Event::Closed>())
                window->close();
            else if (event.is<sf::Event::KeyPressed>()) {
                auto keyEvent = event.getIf<sf::Event::KeyPressed>();
                if(keyEvent)
                    handleInput(keyEvent->code);
            }
        }

        // Measure Time since last frame
        auto now = std::chrono::steady_clock::now();
        double delta = std::chrono::duration<double, std::milli>(now - last).count();
        last = now;

        // Update the game
        bool hasCollision = updateGame(delta);
        if(hasCollision) {
            handleInput(sf::Keyboard::Key::Unknown);
        }

        // Render everything
        window->clear();
        paintGame(*window);
        window->display();
    }
}
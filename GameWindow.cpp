#include "GameWindow.hpp"


#include<SFML/Graphics.hpp>
#include<chrono>

void GameWindow::start() {
    
    // Fenster erstellen
    sf::RenderWindow window(sf::VideoMode(sf::Vector2u(800, 600)), "Snake");
    auto last = std::chrono::steady_clock::now();

    // Spiel loop
    while(window.isOpen()) {
        // Process events
        while(auto eventOpt = window.pollEvent()) {
            const sf::Event& event = *eventOpt;
            if(event.is<sf::Event::Closed>())
                window.close();
            else if (event.is<sf::Event::KeyPressed>()) {
                // zugriff auf keyEvent
                auto keyEvent = event.getIf<sf::Event::KeyPressed>();
                if(keyEvent)
                    handleInput(keyEvent->code);
            }
                
        }
        
        // Zeitdifferenz berechnen
        auto now = std::chrono::steady_clock::now();
        double delta = std::chrono::duration<double, std::milli>(now - last).count();
        last = now;

        // Spiel aktualisieren
        updateGame(delta);
        

         // Rendern
        window.clear();
        paintGame(window);
        window.display();
    }

}

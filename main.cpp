#include <iostream>
#include <SFML/Graphics.hpp>
#include <optional>
#include "obstacle.hpp"

int main() {
    sf::RenderWindow window(sf::VideoMode(800, 600), "Flap");
    window.setFramerateLimit(60);
    window.setVerticalSyncEnabled(false);

    obstacle obs= obstacle(window.getSize());

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear(sf::Color::Black);
        obs.draw(window); 
        window.display();
        obs.move(); 
    }

    return 0;
}
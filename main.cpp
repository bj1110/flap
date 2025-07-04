#include <iostream>
#include <SFML/Graphics.hpp>
#include <optional>
#include "obstacle.hpp"
#include <memory>
#include "player.hpp"

int main() {
    sf::RenderWindow window(sf::VideoMode(800, 600), "Flap");
    window.setFramerateLimit(60);
    window.setVerticalSyncEnabled(false);

    std::unique_ptr<obstacle> obs= std::make_unique<obstacle>(window.getSize()); 
    player player(window.getSize()); 

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
            if(event.type ==sf::Event::KeyPressed){
                player.move(event); 
            }
        }

        window.clear(sf::Color::Black);
        if(obs){
            if(!obs->isOutOfBounds()){
                obs->draw(window); 
                obs->move();
            } else{
                obs.reset();
            }
            player.draw(window); 
            window.display();
        }
         
    }

    return 0;
}
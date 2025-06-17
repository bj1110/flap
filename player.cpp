#include "player.hpp"
#include <iostream>

player::player(sf::Vector2u windowSize): m_height(windowSize.x/2), m_x_pos(30)
{
    
}

void player::draw(sf::RenderWindow& window){
    this->fall(); 
    sf::CircleShape circle;
    circle.setRadius(m_size);
    circle.setFillColor(m_player_color);
    // circle.setOutlineThickness();
    circle.setPosition(m_x_pos, m_height);

    window.draw(circle);
}

void player::move(sf::Event e)
{
    if (e.key.code =sf::Keyboard::Space){
        m_height -=40; 
    }
}

void player::fall()
{
    m_height +=1; 
}

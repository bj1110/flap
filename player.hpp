#ifndef PLAYER_H
#define PLAYER_H


#include <SFML/Graphics.hpp>


class player{

private:
    float m_height;
    float m_x_pos;
    float m_size = 5; 
    sf::Color m_player_color= sf::Color::Blue;

public:
    player(sf::Vector2u windowSize);

    void draw(sf::RenderWindow& window);

};





#endif
#ifndef OBSTACLE_H
#define OBSTACLE_H


#include <SFML/Graphics.hpp>

class obstacle {
private:
    float m_height = 0; 
    float m_pos_x = 0; 
    float m_gap = 60; 
    float m_thickness= 10; 
    sf::Color m_color= sf::Color::Green; 

public: 
    obstacle(float h, float x);
    obstacle(sf::Vector2u winSize);
    obstacle(float h);
    obstacle(); 
    ~obstacle(); 

    void move(); 
    void draw(sf::RenderWindow& window); 

    float getGapWidth();
    bool isOutOfBounds(); 
    float getPosX();
};



#endif
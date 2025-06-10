#ifndef OBSTACLE_H
#define OBSTACLE_H


#include <SFML/Graphics.hpp>

class obstacle {
private:
    float height = 0; 
    float pos_x = 0; 
    float gap = 60; 
    float thickness= 10; 
    sf::Color color= sf::Color::Green; 

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
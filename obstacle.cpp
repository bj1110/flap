#include "obstacle.hpp"

#include <experimental/random>
#include <iostream>

obstacle::obstacle(float h, float x): m_height{h}, m_pos_x{x}
{
}

obstacle::obstacle(sf::Vector2u winSize)
{
    int randomheight= std::experimental::randint(10, (int) winSize.y -10 );
    m_height= (float) randomheight;
    m_pos_x = (float) winSize.x;
}

obstacle::obstacle(float h): m_height{h}, m_pos_x{0}
{
}

obstacle::obstacle(): m_height{0}, m_pos_x{0}
{
}

obstacle::~obstacle()
{
    // std::cout<< "deleted instance" <<std::endl; 
    // std::cout <<"xpos: "<< pos_x << std::endl; 
}

void obstacle::move()
{
    // std::cout<< "vor diesem Zug ist pox_x: "<<pos_x <<std::endl; 
    m_pos_x -= 1;
    // std::cout<< "nach diesem Zug ist pox_x: "<<pos_x <<std::endl; 
}

void obstacle::draw(sf::RenderWindow& window)
{
    sf::RectangleShape upper, lower;
    upper.setSize({m_thickness,m_height - (m_gap/2)});
    upper.setPosition({m_pos_x-m_thickness, 0});
    upper.setFillColor(m_color);

    lower.setSize({m_thickness, window.getSize().y - m_height - (m_gap/2)});
    lower.setPosition({m_pos_x-m_thickness, m_height+(m_gap/2)});
    lower.setFillColor(m_color);
    
    window.draw(upper); 
    window.draw(lower); 
}

float obstacle::getGapWidth()
{
    return m_gap;
}

bool obstacle::isOutOfBounds()
{
    if(m_pos_x<0){
        return true;
    }
    return false;
}

float obstacle::getPosX()
{
    return m_pos_x;
}

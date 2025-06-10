#include "obstacle.hpp"

#include <experimental/random>
#include <iostream>

obstacle::obstacle(float h, float x): height{h}, pos_x{x}
{
}

obstacle::obstacle(sf::Vector2u winSize)
{
    int randomheight= std::experimental::randint(10, (int) winSize.y -10 );
    height= (float) randomheight;
    pos_x = (float) winSize.x;
}

obstacle::obstacle(float h): height{h}, pos_x{0}
{
}

obstacle::obstacle(): height{0}, pos_x{0}
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
    pos_x -= 1;
    // std::cout<< "nach diesem Zug ist pox_x: "<<pos_x <<std::endl; 
}

void obstacle::draw(sf::RenderWindow& window)
{
    sf::RectangleShape upper, lower;
    upper.setSize({thickness,height - (gap/2)});
    upper.setPosition({pos_x-thickness, 0});
    upper.setFillColor(color);

    lower.setSize({thickness, window.getSize().y - height - (gap/2)});
    lower.setPosition({pos_x-thickness, height+(gap/2)});
    lower.setFillColor(color);
    
    window.draw(upper); 
    window.draw(lower); 
}

float obstacle::getGapWidth()
{
    return gap;
}

bool obstacle::isOutOfBounds()
{
    if(pos_x<0){
        return true;
    }
    return false;
}

float obstacle::getPosX()
{
    return pos_x;
}

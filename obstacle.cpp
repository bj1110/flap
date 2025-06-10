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

void obstacle::move()
{
    pos_x -= 1;
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

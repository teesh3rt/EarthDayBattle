#pragma once
#include "fighter.hpp"
#include <SFML/System.hpp>

class FighterBox
{
private:
    Fighter &fighter;
    sf::Vector2f position;

public:
    FighterBox(Fighter &fighter);
    virtual ~FighterBox() = default;

    sf::Vector2f &get_position();
    void set_position(sf::Vector2f new_position);

    void set_fighter(Fighter &value);

    void draw(sf::RenderWindow &window);
};
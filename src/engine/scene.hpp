#pragma once
#include <SFML/Graphics.hpp>

class Scene
{
public:
    Scene();

    void draw(sf::RenderWindow &target);
    void update(float dt);
};
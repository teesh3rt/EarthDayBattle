#pragma once
#include <SFML/Graphics.hpp>

class Scene
{
public:
    Scene();
    virtual ~Scene() = default;

    virtual void draw(sf::RenderWindow &target) = 0;
    virtual void update(float dt) = 0;
};
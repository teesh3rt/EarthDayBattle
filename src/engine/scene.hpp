#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>

class Scene
{
public:
    Scene();
    virtual ~Scene() = default;

    virtual void draw(sf::RenderWindow &target) = 0;
    virtual void update(float dt) = 0;
    virtual void on_key_pressed(sf::Keyboard::Scancode code);
};
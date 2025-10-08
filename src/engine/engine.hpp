#pragma once

#include <string>
#include <SFML/Graphics.hpp>
#include "scene_manager.hpp"

class Engine
{
public:
    sf::RenderWindow window;
    SceneManager scene_manager;

    Engine(unsigned int width, unsigned int height, std::string title);
    void run();

private:
    float deltaTime;
    float previousTime;

    void update(float deltaTime);
    void draw();
};
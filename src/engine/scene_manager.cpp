#include "scene_manager.hpp"
#include <spdlog/spdlog.h>

SceneManager::SceneManager() : current()
{
}

SceneManager::SceneManager(Scene starter)
    : current(starter)
{
}

Scene SceneManager::get_current_scene()
{
    return current;
}

void SceneManager::set_scene(Scene scene)
{
    current = scene;
}

void SceneManager::draw(sf::RenderWindow &window)
{
    current.draw(window);
}

void SceneManager::update(float dt)
{
    current.update(dt);
}
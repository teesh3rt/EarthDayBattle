#include "scene_manager.hpp"
#include <spdlog/spdlog.h>

SceneManager::SceneManager() : current()
{
    spdlog::debug("Created a SceneManager with the default scene!");
    spdlog::debug("    This is probably not something you want to do.");
    spdlog::debug("    Please check about perhaps adding a starter scene.");
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
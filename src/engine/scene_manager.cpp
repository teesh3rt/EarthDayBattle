#include "scene_manager.hpp"
#include <spdlog/spdlog.h>

SceneManager::SceneManager() : current(nullptr)
{
    spdlog::trace("SceneManager created with no initial scene.");
}

SceneManager::SceneManager(std::unique_ptr<Scene> starter)
    : current(std::move(starter))
{
    spdlog::trace("SceneManager created with initial scene.");
}

void SceneManager::set_scene(std::unique_ptr<Scene> scene)
{
    spdlog::debug("Switching scene...");
    current = std::move(scene);
}

Scene &SceneManager::get_current_scene()
{
    if (!current)
    {
        spdlog::error("No scene set! Returning reference to null object (this will crash).");
        throw std::runtime_error("No scene set in SceneManager.");
    }
    return *current;
}

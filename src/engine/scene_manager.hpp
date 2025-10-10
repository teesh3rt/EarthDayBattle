#pragma once
#include "scene.hpp"
#include <memory>

class SceneManager
{
private:
    std::unique_ptr<Scene> current;

public:
    SceneManager();
    SceneManager(std::unique_ptr<Scene> starter);

    void set_scene(std::unique_ptr<Scene> scene);
    Scene &get_current_scene();
};

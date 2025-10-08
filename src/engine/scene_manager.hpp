#pragma once
#include "scene.hpp"

class SceneManager
{
private:
    Scene current;

public:
    SceneManager();
    SceneManager(Scene starter);

    void set_scene(Scene scene);
    Scene get_current_scene();
};
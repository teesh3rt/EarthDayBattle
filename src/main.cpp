#include <fmt/format.h>
#include <spdlog/spdlog.h>
#include "engine/engine.hpp"
#include "buildtime.hpp"
#include "fight_scene.hpp"

int main()
{
    spdlog::set_level(spdlog::level::trace);
    std::string windowTitle = fmt::format("EarthDayBattle ({})", GIT_HASH);

    Engine engine(800, 600, windowTitle);
    FightScene scene;
    engine.scene_manager.set_scene(scene);
    engine.run();
}
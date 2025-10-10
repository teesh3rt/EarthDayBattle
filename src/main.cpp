#include <fmt/format.h>
#include <spdlog/spdlog.h>
#include "engine/engine.hpp"
#include "buildtime.hpp"
#include "fight_scene.hpp"

int main()
{
    spdlog::set_level(spdlog::level::trace);
    std::string windowTitle = fmt::format("EarthDayBattle ({})", GIT_HASH);

    Engine engine(1920, 1080, windowTitle);
    engine.scene_manager.set_scene(std::make_unique<FightScene>());
    engine.run();
}
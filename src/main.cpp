#include <fmt/format.h>
#include <spdlog/spdlog.h>
#include "engine/engine.hpp"
#include "buildtime.hpp"

int main()
{
    spdlog::set_level(spdlog::level::trace);
    std::string windowTitle = fmt::format("EarthDayBattle ({})", GIT_HASH);

    Engine engine(800, 600, windowTitle);
    engine.run();
}
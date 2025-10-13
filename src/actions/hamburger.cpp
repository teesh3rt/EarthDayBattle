#include "hamburger.hpp"
#include "fighter.hpp"
#include <spdlog/spdlog.h>

Hamburger::Hamburger()
{
    name = "Hamburger";
    description = "Heals 30 HP (single use)";

    used = false;
}

void Hamburger::affect(Fighter &affected)
{
    if (used)
        return;
    used = true;
    affected.heal(30);
}
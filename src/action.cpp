#include "action.hpp"
#include <spdlog/spdlog.h>

Action::Action()
{
    spdlog::warn("You are constructing an empty action, which you probably shouldn't do!");
    spdlog::debug("    Actions are meant to be inherited into their own classes instead of");
    spdlog::debug("    using them like this. You should probably inherit Action into some");
    spdlog::debug("    other class and make your action that way.");
}

void Action::affect(Fighter &affected)
{
    spdlog::warn("You are affectinge with an empty action, which does nothing!");
    spdlog::debug("    You also probably shouldn't do it, as it quite literally changes");
    spdlog::debug("    nothing about the fighter.");
}
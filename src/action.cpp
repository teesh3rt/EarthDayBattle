#include "action.hpp"
#include <spdlog/spdlog.h>

/*
    An empty action is just a noop.
    If you're gonna make an action, PLEASE inherit with public.
*/

Action::Action()
    : name("EMPTY ACTION, PLEASE CHANGE"),
      description("DONT USE THIS ACTION")
{
}

void Action::affect(Fighter &affected)
{
}
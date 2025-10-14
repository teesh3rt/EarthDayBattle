#include "pollute.hpp"
#include "fighter.hpp"

Pollute::Pollute()
{
    name = "Pollute";
    description = "Heal 20 HP";
}

void Pollute::affect(Fighter &affected)
{
    affected.heal(20);
}

#include "heavyattack.hpp"
#include "fighter.hpp"

HeavyAttack::HeavyAttack()
{
    name = "Heavy attack";
    description = "Deal some good damage on the enemy, single use";

    used = false;
}

void HeavyAttack::affect(Fighter &affected)
{
    if (used)
        return;
    used = true;
    affected.deal(100);
}

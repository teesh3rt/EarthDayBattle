#include "poison.hpp"
#include "fighter.hpp"

Poison::Poison()
{
    name = "Poison";
    description = "Take MP, cannot be reused";

    used = false;
}

void Poison::affect(Fighter &affected)
{
    if (used)
        return;
    used = true;

    affected.deplete_mp(40);
}

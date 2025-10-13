#include "cocacola.hpp"
#include "fighter.hpp"

CocaCola::CocaCola()
{
    name = "Coca Cola";
    description = "Gives 20 MP (single use)";

    used = false;
}

void CocaCola::affect(Fighter &affected)
{
    if (used)
        return;
    affected.restore_mp(20);
    used = true;
}
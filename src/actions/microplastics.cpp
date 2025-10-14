#include "microplastics.hpp"
#include "fighter.hpp"

Microplastics::Microplastics()
{
    name = "Microplastics";
    description = "Damage Michael, Increases each use";

    use_count = 0;
}

void Microplastics::affect(Fighter &affected)
{
    use_count++;
    affected.deal(10 * use_count);
}

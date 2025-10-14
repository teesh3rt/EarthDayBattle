#include "backonmyfeet.hpp"
#include "fighter.hpp"

BackOnMyFeet::BackOnMyFeet()
{
    name = "Back on my feet";
    description = "Quick recovery";
}

void BackOnMyFeet::affect(Fighter &affected)
{
    affected.restore_mp(40);
    affected.heal(20);
}
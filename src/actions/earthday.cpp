#include "earthday.hpp"
#include "fighter.hpp"

EarthDay::EarthDay()
{
    name = "Earth Day";
    description = "We must work hard to recover";

    use_count = 0;
}

void EarthDay::affect(Fighter &affected)
{
    use_count++;
    if (use_count >= 3)
    {
        affected.deal(200);
    }
}

#include "yellowbin.hpp"
#include "fighter.hpp"
#include <spdlog/spdlog.h>

YellowBin::YellowBin()
{
    name = "The Yellow Bin";
    description = "Clean up the trash, 60 HP, 10 MP";
}

void YellowBin::affect(Fighter &affected)
{
    affected.deal(60);
    affected.deplete_mp(10);
}
#pragma once

#include "action.hpp"

class YellowBin : public Action
{
public:
    YellowBin();

    void affect(Fighter &affected) override;
};
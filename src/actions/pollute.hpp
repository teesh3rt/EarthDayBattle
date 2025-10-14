#pragma once

#include "action.hpp"

class Pollute : public Action
{
public:
    Pollute();

    void affect(Fighter &affected) override;
};

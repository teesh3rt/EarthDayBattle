#pragma once

#include "action.hpp"

class Microplastics : public Action
{
private:
    int use_count;

public:
    Microplastics();

    void affect(Fighter &affected) override;
};

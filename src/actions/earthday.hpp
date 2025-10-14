#pragma once

#include "action.hpp"

class EarthDay : public Action
{
private:
    int use_count;

public:
    EarthDay();

    void affect(Fighter &affected) override;
};

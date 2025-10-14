#pragma once

#include "action.hpp"

class Poison : public Action
{
private:
    bool used;

public:
    Poison();

    void affect(Fighter &affected) override;
};

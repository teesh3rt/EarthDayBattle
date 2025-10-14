#pragma once

#include "action.hpp"

class HeavyAttack : public Action
{
private:
    bool used;

public:
    HeavyAttack();

    void affect(Fighter &affected) override;
};

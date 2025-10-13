#pragma once

#include "action.hpp"

class Hamburger : public Action
{
private:
    bool used;

public:
    Hamburger();

    void affect(Fighter &affected) override;
};
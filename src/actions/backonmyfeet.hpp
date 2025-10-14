#pragma once

#include "action.hpp"

class BackOnMyFeet : public Action
{
public:
    BackOnMyFeet();

    void affect(Fighter &affected) override;
};
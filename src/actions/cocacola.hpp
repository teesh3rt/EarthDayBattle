#pragma once

#include "action.hpp"

class CocaCola : public Action
{
private:
    bool used;

public:
    CocaCola();

    void affect(Fighter &affected) override;
};
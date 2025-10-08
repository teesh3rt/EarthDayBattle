#pragma once

#include <string>

// Oh, round and round we go!
// Actual declaration: `fighter.hpp`
class Fighter;

// No, not a lawsuit.
// Not that kind of class action.
class Action
{
public:
    std::string name;
    std::string description;

    Action();

    void affect(Fighter &affected);
};
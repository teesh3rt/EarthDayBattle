#include "fighter.hpp"
#include <string>

Fighter::Fighter(int health, std::string name)
    : health(health),
      name(name),
      abilities({}),
      items({})
{
}

Fighter::Fighter(int health, std::string name, std::vector<Action> abilities)
    : health(health),
      name(name),
      abilities(abilities),
      items({})
{
}

Fighter::Fighter(int health, std::string name, std::vector<Action> abilities, std::vector<Action> items)
    : health(health),
      name(name),
      abilities(abilities),
      items(items)
{
}

int Fighter::heal(int amount)
{
    health += amount;
    return health;
}

int Fighter::deal(int amount)
{
    health -= amount;
    return health;
}

void Fighter::use_item(int idx)
{
    if (idx >= 0 && idx < static_cast<int>(items.size()))
        items[idx].affect(*this);
}

void Fighter::use_ability(int idx)
{
    if (idx >= 0 && idx < static_cast<int>(abilities.size()))
        abilities[idx].affect(*this);
}
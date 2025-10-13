#include "fighter.hpp"
#include <string>

Fighter::Fighter(int health, std::string name)
    : health(health),
      max_health(health),
      name(name),
      abilities({}),
      items({}),
      magic(100),
      max_magic(100)
{
}

Fighter::Fighter(int health, std::string name, std::vector<std::shared_ptr<Action>> abilities)
    : health(health),
      max_health(health),
      name(name),
      abilities(abilities),
      items({}),
      magic(100),
      max_magic(100)
{
}

Fighter::Fighter(int health, std::string name, std::vector<std::shared_ptr<Action>> abilities, std::vector<std::shared_ptr<Action>> items)
    : health(health),
      max_health(health),
      name(name),
      abilities(abilities),
      items(items),
      magic(100),
      max_magic(100)
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
        items[idx]->affect(*this);
}

void Fighter::use_ability(int idx)
{
    if (idx >= 0 && idx < static_cast<int>(abilities.size()))
        abilities[idx]->affect(*this);
}

void Fighter::use_ability_on(Fighter &other, int idx)
{
    if (idx >= 0 && idx < static_cast<int>(abilities.size()))
        abilities[idx]->affect(other);
}

int Fighter::restore_mp(int amount)
{
    magic += amount;
    return magic;
}

int Fighter::deplete_mp(int amount)
{
    magic -= amount;
    return magic;
}

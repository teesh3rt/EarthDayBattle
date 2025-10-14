#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <string>
#include <vector>
#include "action.hpp"

/*
    An example of a fighter in our case:

    Name: Michael
    Health: 100
    Items: ["Sandwich", "The Infinity Gauntlet", "Gun"] // Who the fuck gave that to michael
    Abilities: ["Take out the trash", "All out of bubblegum"]
*/

class Fighter
{
public:
    int health;
    int max_health;
    int magic;
    int max_magic;
    std::string name;

    // I know it's odd to think of items as actions, but think about it...
    //
    // Items and abilities are really one and the same: things that affect a
    // fighter! DRY code, here we come!
    std::vector<std::shared_ptr<Action>> items;
    std::vector<std::shared_ptr<Action>> abilities;

    Fighter(int health, std::string name);
    Fighter(int health, std::string name, std::vector<std::shared_ptr<Action>> abilities);
    Fighter(int health, std::string name, std::vector<std::shared_ptr<Action>> abilities, std::vector<std::shared_ptr<Action>> items);

    int deal(int amount);
    int heal(int amount);

    int restore_mp(int amount);
    int deplete_mp(int amount);

    // These methods are virtually identical, just
    // using a different array
    void use_item(int index);
    void use_ability(int index);

    void use_ability_on(Fighter &other, int index);

    void make_move(Fighter &opposing);
};
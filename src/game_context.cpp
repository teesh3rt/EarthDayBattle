#include "game_context.hpp"

#include "actions/hamburger.hpp"
#include "actions/cocacola.hpp"
#include "actions/yellowbin.hpp"
#include "actions/backonmyfeet.hpp"
#include "actions/heavyattack.hpp"
#include "actions/earthday.hpp"
#include "actions/poison.hpp"
#include "actions/pollute.hpp"
#include "actions/microplastics.hpp"

GameContext::GameContext()
    : michael(100, "Michael"),
      monster(300, "Trash Monster")
{
  michael.items.push_back(std::make_shared<Hamburger>());
  michael.items.push_back(std::make_shared<CocaCola>());

  michael.abilities.push_back(std::make_shared<YellowBin>());
  michael.abilities.push_back(std::make_shared<BackOnMyFeet>());
  michael.abilities.push_back(std::make_shared<HeavyAttack>());
  michael.abilities.push_back(std::make_shared<EarthDay>());

  monster.abilities.push_back(std::make_shared<Poison>());
  monster.abilities.push_back(std::make_shared<Pollute>());
  monster.abilities.push_back(std::make_shared<Microplastics>());
}
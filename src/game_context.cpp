#include "game_context.hpp"

#include "actions/hamburger.hpp"
#include "actions/cocacola.hpp"

GameContext::GameContext()
    : michael(100, "Michael"),
      monster(300, "Trash Monster")
{
  michael.items.push_back(std::make_shared<Hamburger>());
  michael.items.push_back(std::make_shared<CocaCola>());
}
#include "fight_scene.hpp"

FightScene::FightScene()
    : context(),
      music("./assets/music/battle.ogg")
{
    music.play();
}

void FightScene::draw(sf::RenderWindow &target)
{
}

void FightScene::update(float dt) {}
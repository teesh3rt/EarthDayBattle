#include "fight_scene.hpp"
#include <spdlog/spdlog.h>

FightScene::FightScene()
    : context(),
      music("./assets/music/battle.ogg"),
      japanbg_tex("./assets/sprites/japanbg.png")
{
}

void FightScene::draw(sf::RenderWindow &target)
{
    sf::Sprite japanbg(japanbg_tex);
    target.draw(japanbg);
}

void FightScene::update(float dt)
{
    if (music.getStatus() != sf::SoundStream::Status::Playing)
    {
        music.play();
    }
}
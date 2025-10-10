#include "fight_scene.hpp"
#include <spdlog/spdlog.h>

FightScene::FightScene()
    : context(),
      assets(),
      battle_music("./assets/music/battle.ogg")
{
}

void FightScene::draw(sf::RenderWindow &target)
{
    sf::Sprite japanbg(assets.japanbg);
    target.draw(japanbg);

    sf::Sprite michael(assets.michael);
    michael.setScale({-1.f, 1.f});
    michael.setPosition({300, 540 - static_cast<float>(assets.michael.getSize().x) / 2});
    target.draw(michael);

    sf::Sprite monster(assets.monster);
    monster.setPosition({1920 - static_cast<float>(assets.monster.getSize().x) - 50,
                         550 - static_cast<float>(assets.monster.getSize().x) / 2});
    target.draw(monster);
}

void FightScene::update(float dt)
{
    if (battle_music.getStatus() != sf::SoundStream::Status::Playing)
    {
        battle_music.play();
    }
}
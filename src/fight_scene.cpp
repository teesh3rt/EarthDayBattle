#include "fight_scene.hpp"
#include <spdlog/spdlog.h>
#include <SFML/System.hpp>

FightScene::FightScene()
    : context(),
      assets(),
      battle_music("./assets/music/battle.ogg"),
      action_option({"Fight", "Ability", "Item"}),
      interact_with(InteractWith::ACTION_OPTION)
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

    action_option.draw(target);
}

void FightScene::update(float dt)
{
    if (battle_music.getStatus() != sf::SoundStream::Status::Playing)
    {
        battle_music.play();
    }
}

void FightScene::on_key_pressed(sf::Keyboard::Scancode code)
{
    if (interact_with == InteractWith::ACTION_OPTION)
    {
        if (code == sf::Keyboard::Scancode::Right)
        {
            action_option.go_right();
        }

        if (code == sf::Keyboard::Scancode::Left)
        {
            action_option.go_left();
        }

        if (code == sf::Keyboard::Scancode::Enter)
        {
            spdlog::debug("Selected option: {}", action_option.get_current_selection());
        }
    }
}
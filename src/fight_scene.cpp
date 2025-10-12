#include "fight_scene.hpp"
#include <spdlog/spdlog.h>
#include <SFML/System.hpp>

FightScene::FightScene()
    : context(),
      assets(),
      battle_music("./assets/music/battle.ogg"),
      action_option({"Fight", "Ability", "Item"}),
      ability_option({"Recovery", "Throw Out", "Sword Attack"}),
      item_option({"Hamburger", "Coca-Cola"}),
      interact_with(InteractWith::ACTION_OPTION)
{
    ability_option.set_position({0, 100});
    item_option.set_position({0, 100});
}

void FightScene::draw(sf::RenderWindow &target)
{
    sf::Sprite japanbg(assets.japanbg);
    target.draw(japanbg);

    sf::Sprite michael(assets.michael);
    michael.setScale({-1.f, 1.f});
    michael.setPosition({300, 650});
    target.draw(michael);

    sf::Sprite monster(assets.monster);
    monster.setPosition({1920 - static_cast<float>(assets.monster.getSize().x) - 50,
                         500});
    target.draw(monster);

    if (interact_with == InteractWith::ABILITY_OPTION)
    {
        ability_option.draw(target);
    }

    if (interact_with == InteractWith::ITEM_OPTION)
    {
        item_option.draw(target);
    }

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
            if (action_option.get_current_selection() == "Ability")
            {
                interact_with = InteractWith::ABILITY_OPTION;
            }

            if (action_option.get_current_selection() == "Item")
            {
                interact_with = InteractWith::ITEM_OPTION;
            }
        }
    }

    if (interact_with == InteractWith::ABILITY_OPTION)
    {
        if (code == sf::Keyboard::Scancode::Up)
        {
            ability_option.go_up();
        }

        if (code == sf::Keyboard::Scancode::Down)
        {
            ability_option.go_down();
        }

        if (code == sf::Keyboard::Scancode::Escape)
        {
            interact_with = InteractWith::ACTION_OPTION;
        }
    }

    if (interact_with == InteractWith::ITEM_OPTION)
    {
        if (code == sf::Keyboard::Scancode::Up)
        {
            item_option.go_up();
        }

        if (code == sf::Keyboard::Scancode::Down)
        {
            item_option.go_down();
        }

        if (code == sf::Keyboard::Scancode::Escape)
        {
            interact_with = InteractWith::ACTION_OPTION;
        }
    }
}
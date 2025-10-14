#include "fight_scene.hpp"
#include <spdlog/spdlog.h>
#include <SFML/System.hpp>

FightScene::FightScene()
    : context(),
      assets(),
      battle_music("./assets/music/battle.ogg"),
      end_music("./assets/music/end.ogg"),
      action_option({"Fight", "Ability", "Item"}),
      ability_option({}),
      item_option({}),
      interact_with(InteractWith::ACTION_OPTION),
      michael_fighterbox(context.michael),
      monster_fighterbox(context.monster),
      dead(false),
      win(false)
{
    item_option.set_options({});
    for (int i = 0; i < context.michael.items.size(); i++)
    {
        item_option.add_option(context.michael.items[i]->name);
    }

    ability_option.set_options({});
    for (int i = 0; i < context.michael.abilities.size(); i++)
    {
        ability_option.add_option(context.michael.abilities[i]->name);
    }

    ability_option.set_position({0, 100});
    item_option.set_position({0, 100});
}

void FightScene::draw(sf::RenderWindow &target)
{
    if (dead)
    {
        draw_dead(target);
    }
    else if (win)
    {
        draw_win(target);
    }
    else
    {
        draw_game(target);
    }
}

void FightScene::draw_win(sf::RenderWindow &target)
{
    sf::Font font("./assets/fonts/osrs.ttf");

    sf::Text you_died(font);
    you_died.setString("Michael won!");
    you_died.setCharacterSize(100);
    you_died.setPosition({100, 100});
    you_died.setFillColor(sf::Color::Green);
    target.draw(you_died);

    sf::Text restart_to_continue(font);
    restart_to_continue.setString("We have to remember: battling pollution isnt and will never be\nas easy as this. If we as a human race wish to succeed in saving our\nplanet, everyone must take part. You can make a difference, we all can.\nYou are the future, and the future starts with you.\n\nRemember, treat this planet like we have no others, because we have no others.\n\nGame made by [Ilay Levy].\nSprites made by [Michael Rivkin].\nMusic made by [The Block Tales Sound Team].\nFont is [OldSchool RuneScape].\n\nYou may now quit the game.");
    restart_to_continue.setCharacterSize(50);
    restart_to_continue.setPosition({100, 250});
    restart_to_continue.setFillColor(sf::Color::White);
    target.draw(restart_to_continue);
}

void FightScene::draw_dead(sf::RenderWindow &target)
{
    sf::Font font("./assets/fonts/osrs.ttf");

    sf::Text you_died(font);
    you_died.setString("Michael died.");
    you_died.setCharacterSize(100);
    you_died.setPosition({100, 100});
    you_died.setFillColor(sf::Color::Red);
    target.draw(you_died);

    sf::Text restart_to_continue(font);
    restart_to_continue.setString("Restart the game to continue.");
    restart_to_continue.setCharacterSize(50);
    restart_to_continue.setPosition({100, 250});
    restart_to_continue.setFillColor(sf::Color::White);
    target.draw(restart_to_continue);
}

void FightScene::draw_game(sf::RenderWindow &target)
{
    sf::Sprite japanbg(assets.japanbg);
    target.draw(japanbg);

    sf::Sprite michael(assets.michael);
    michael.setScale({-1.f, 1.f});
    michael.setPosition({300, 650});
    target.draw(michael);

    michael_fighterbox.set_position({30.f, 450.f});
    michael_fighterbox.draw(target);

    monster_fighterbox.set_position({static_cast<float>(target.getSize().x - 430.f), 300.f});
    monster_fighterbox.draw(target);

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
    if (battle_music.getStatus() != sf::SoundStream::Status::Playing && !dead && !win)
    {
        battle_music.play();
    }

    if (context.michael.health <= 0 && !dead)
    {
        battle_music.stop();
        end_music.play();
        dead = true;
    }

    if (context.monster.health <= 0 && !dead && !win)
    {
        battle_music.stop();
        end_music.play();
        win = true;
    }

    if (context.michael.magic <= 0)
    {
        context.michael.magic = 0;
    }

    if (context.monster.magic <= 0)
    {
        context.monster.magic = 0;
    }
}

void FightScene::on_key_pressed(sf::Keyboard::Scancode code)
{
    if (dead || win)
        return;

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
            if (action_option.get_current_selection() == "Fight")
            {
                context.monster.deal(20);
                context.monster.make_move(context.michael);
                interact_with = InteractWith::ACTION_OPTION;
            }

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

    else if (interact_with == InteractWith::ABILITY_OPTION)
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

        if (code == sf::Keyboard::Scancode::Enter)
        {
            if (context.michael.magic <= 0)
            {
                interact_with = InteractWith::ACTION_OPTION;
                return;
            }

            // The Yellow Bin
            if (ability_option.index == 0)
            {
                context.michael.use_ability_on(context.monster, 0);
            }

            // Back on my feet
            if (ability_option.index == 1)
            {
                context.michael.use_ability(1);
            }

            // Heavy attack
            if (ability_option.index == 2)
            {
                context.michael.use_ability_on(context.monster, 2);
            }

            // Earth Day
            if (ability_option.index == 3)
            {
                context.michael.use_ability_on(context.monster, 3);
            }

            context.michael.deplete_mp(20);
            context.monster.make_move(context.michael);
            interact_with = InteractWith::ACTION_OPTION;
        }
    }

    else if (interact_with == InteractWith::ITEM_OPTION)
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

        if (code == sf::Keyboard::Scancode::Enter)
        {
            context.michael.use_item(item_option.index);
            context.monster.make_move(context.michael);
            interact_with = InteractWith::ACTION_OPTION;
        }
    }
}
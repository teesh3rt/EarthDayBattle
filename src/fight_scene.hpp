#pragma once
#include <SFML/Audio.hpp>
#include "engine/scene.hpp"
#include "game_context.hpp"
#include "asset_store.hpp"
#include "ui/hselectbox.hpp"
#include "ui/vselectbox.hpp"

enum InteractWith
{
    ACTION_OPTION,
    ABILITY_OPTION,
    ITEM_OPTION,
};

class FightScene : public Scene
{
private:
    AssetStore assets;
    sf::Music battle_music;

    HSelectBox action_option;
    VSelectBox ability_option;
    VSelectBox item_option;

    InteractWith interact_with;

public:
    GameContext context;

    FightScene();
    void draw(sf::RenderWindow &target) override;
    void update(float dt) override;
    void on_key_pressed(sf::Keyboard::Scancode code) override;
};
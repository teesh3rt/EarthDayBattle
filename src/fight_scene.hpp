#pragma once
#include <SFML/Audio.hpp>
#include "engine/scene.hpp"
#include "game_context.hpp"
#include "asset_store.hpp"
#include "ui/hselectbox.hpp"

class FightScene : public Scene
{
private:
    AssetStore assets;
    sf::Music battle_music;
    HSelectBox action_option;

public:
    GameContext context;

    FightScene();
    void draw(sf::RenderWindow &target) override;
    void update(float dt) override;
};
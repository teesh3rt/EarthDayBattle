#pragma once
#include <SFML/Audio.hpp>
#include "engine/scene.hpp"
#include "game_context.hpp"
#include "asset_store.hpp"

class FightScene : public Scene
{
private:
    AssetStore assets;
    sf::Music battle_music;

public:
    GameContext context;

    FightScene();
    void draw(sf::RenderWindow &target) override;
    void update(float dt) override;
};
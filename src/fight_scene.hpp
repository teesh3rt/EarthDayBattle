#pragma once
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include "engine/scene.hpp"
#include "game_context.hpp"

class FightScene : public Scene
{
private:
    sf::Music music;
    sf::Texture japanbg_tex;

public:
    GameContext context;

    FightScene();
    void draw(sf::RenderWindow &target) override;
    void update(float dt) override;
};
#pragma once
#include <SFML/Audio.hpp>
#include "engine/scene.hpp"
#include "game_context.hpp"

class FightScene : public Scene
{
private:
    sf::Music music;

public:
    GameContext context;

    FightScene();
    void draw(sf::RenderWindow &target);
    void update(float dt);
};
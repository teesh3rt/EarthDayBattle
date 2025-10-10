#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

class AssetStore
{
public:
    sf::Texture michael;
    sf::Texture japanbg;
    sf::Texture monster;

    sf::Music battle;

    AssetStore();
    ~AssetStore() = default;
};
#include "fighterbox.hpp"
#include <fmt/core.h>

FighterBox::FighterBox(Fighter &fighter)
    : fighter(fighter)
{
}

sf::Vector2f &FighterBox::get_position()
{
    return position;
}

void FighterBox::set_position(sf::Vector2f new_position)
{
    position = new_position;
}

void FighterBox::draw(sf::RenderWindow &window)
{
    sf::RectangleShape rect({300.f, 155.f});
    rect.setOutlineThickness(5.f);
    rect.setOutlineColor(sf::Color(38, 104, 171));
    rect.setFillColor(sf::Color(52, 143, 235));
    rect.setPosition(position);
    window.draw(rect);

    sf::Font font("./assets/fonts/osrs.ttf");

    sf::Text name_text(font);
    name_text.setString(fighter.name);
    name_text.setPosition({10.f + position.x, 10.f + position.y});
    name_text.setFillColor(sf::Color::White);
    name_text.setCharacterSize(40);
    window.draw(name_text);

    sf::Text hp_text(font);
    hp_text.setString(fmt::format("{}/{} HP", fighter.health, fighter.max_health));
    hp_text.setPosition({10.f + position.x, 80.f + position.y});
    hp_text.setFillColor(sf::Color::White);
    window.draw(hp_text);

    sf::Text mp_text(font);
    mp_text.setString(fmt::format("{}/{} MP", fighter.magic, fighter.max_magic));
    mp_text.setPosition({10.f + position.x, 110.f + position.y});
    mp_text.setFillColor(sf::Color::White);
    window.draw(mp_text);
}

void FighterBox::set_fighter(Fighter &value)
{
    fighter = value;
}
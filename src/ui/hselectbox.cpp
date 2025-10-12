#include "hselectbox.hpp"

HSelectBox::HSelectBox()
    : position({0, 0}),
      index(0),
      options({})
{
}

HSelectBox::HSelectBox(std::vector<std::string> opts)
    : position({0, 0}),
      index(0),
      options(opts)
{
}

void HSelectBox::set_position(sf::Vector2f new_position)
{
    position = new_position;
}

sf::Vector2f &HSelectBox::get_position()
{
    return position;
}

std::string HSelectBox::get_current_selection()
{
    return options[index];
}

void HSelectBox::go_left()
{
    index--;
    if (index == -1)
    {
        index = options.size() - 1;
    }
}

void HSelectBox::go_right()
{
    index++;
    if (index == options.size())
    {
        index = 0;
    }
}

void HSelectBox::draw(sf::RenderWindow &window)
{
    sf::RectangleShape rect({static_cast<float>(window.getSize().x), 100});
    rect.setOutlineThickness(5.f);
    rect.setOutlineColor(sf::Color(38, 104, 171));
    rect.setFillColor(sf::Color(52, 143, 235));
    rect.setPosition(position);
    window.draw(rect);

    sf::Font font("./assets/fonts/osrs.ttf");
    float x_offset = 50.f;

    for (int option_index = 0; option_index < options.size(); option_index++)
    {
        sf::Text option(font);
        option.setString(options[option_index]);
        option.setCharacterSize(40);
        option.setFillColor(sf::Color::White);
        if (option_index == index)
        {
            option.setFillColor(sf::Color(255, 208, 0));
        }
        option.setStyle(sf::Text::Bold);
        option.setPosition({x_offset + position.x, 25 + position.y});

        window.draw(option);

        x_offset += option.getLocalBounds().size.x + 50.f;
    }
}
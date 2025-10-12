#include "vselectbox.hpp"

VSelectBox::VSelectBox()
    : position({0, 0}),
      index(0),
      options({})
{
}

VSelectBox::VSelectBox(std::vector<std::string> opts)
    : position({0, 0}),
      index(0),
      options(opts)
{
}

void VSelectBox::set_position(sf::Vector2f new_position)
{
    position = new_position;
}

sf::Vector2f &VSelectBox::get_position()
{
    return position;
}

std::string VSelectBox::get_current_selection()
{
    return options[index];
}

void VSelectBox::go_up()
{
    index--;
    if (index == -1)
    {
        index = options.size() - 1;
    }
}

void VSelectBox::go_down()
{
    index++;
    if (index == options.size())
    {
        index = 0;
    }
}

// This function is so fucking janky... too bad!
void VSelectBox::draw(sf::RenderWindow &window)
{
    sf::RectangleShape rect({0, 0});
    rect.setOutlineThickness(5.f);
    rect.setOutlineColor(sf::Color(38, 104, 171));
    rect.setFillColor(sf::Color(52, 143, 235));
    rect.setPosition(position);

    sf::Font font("./assets/fonts/osrs.ttf");
    float y_offset = 50.f;
    for (int option_index = 0; option_index < options.size(); option_index++)
    {
        sf::Text option(font);
        option.setString(options[option_index]);
        option.setCharacterSize(40);
        option.setStyle(sf::Text::Bold);

        window.draw(option);

        y_offset += option.getLocalBounds().size.y + 50.f;
    }
    rect.setSize({350, y_offset + 50});
    window.draw(rect);

    y_offset = 50.f;

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
        option.setPosition({50 + position.x, y_offset + position.y});

        window.draw(option);

        y_offset += option.getLocalBounds().size.y + 50.f;
    }
}
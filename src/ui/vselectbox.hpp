#pragma once

#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <string>
#include <vector>

class VSelectBox
{
private:
    sf::Vector2f position;

public:
    int index;
    std::vector<std::string> options;

    VSelectBox();
    VSelectBox(std::vector<std::string> opts);
    virtual ~VSelectBox() = default;

    sf::Vector2f &get_position();
    void set_position(sf::Vector2f new_position);

    std::string get_current_selection();

    void draw(sf::RenderWindow &window);
    void go_up();
    void go_down();
};
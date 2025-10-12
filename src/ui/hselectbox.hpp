#pragma once

#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <string>
#include <vector>

class HSelectBox
{
private:
    sf::Vector2f position;

public:
    int index;
    std::vector<std::string> options;

    HSelectBox();
    HSelectBox(std::vector<std::string> opts);
    virtual ~HSelectBox() = default;

    sf::Vector2f &get_position();
    void set_position(sf::Vector2f new_position);

    std::string get_current_selection();

    void set_options(std::vector<std::string> opts);

    void draw(sf::RenderWindow &window);
    void go_left();
    void go_right();
};
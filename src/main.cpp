#include <SFML/Graphics.hpp>
#include <format>

#ifndef GIT_HASH
#define GIT_HASH "UNKNOWN"
#endif // GIT_HASH

int main()
{
    std::string windowTitle = std::format("EarthDayBattle ({})", GIT_HASH);
    sf::RenderWindow window(sf::VideoMode({800, 600}), windowTitle);

    while (window.isOpen())
    {
        while (const std::optional event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
                window.close();
        }

        window.clear();
        window.display();
    }
}
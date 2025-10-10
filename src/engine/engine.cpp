#include "engine.hpp"
#include <SFML/System.hpp>
#include <spdlog/spdlog.h>

Engine::Engine(unsigned int width, unsigned int height, std::string title)
    : window(sf::VideoMode({width, height}), title),
      previousTime(0.f),
      deltaTime(0.f),
      scene_manager()
{
    spdlog::info("Engine instance created!");
    spdlog::debug("    Resolution: {}x{}", width, height);
    spdlog::debug("    Window title: {}", title);
}

void Engine::run()
{
    sf::Clock clock;

    spdlog::debug("Run called, starting event loop!");

    while (window.isOpen())
    {
        deltaTime = clock.restart().asSeconds();

        while (const std::optional event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
            {
                spdlog::debug("Close event received!");
                spdlog::debug("    Closing event loop...");
                spdlog::debug("    Making sure destructuring happens...");
                window.close();
            }
        }

        update(deltaTime);

        draw();
    }
}

void Engine::update(float deltaTime)
{
    scene_manager.get_current_scene().update(deltaTime);
}

void Engine::draw()
{
    window.clear(sf::Color::Black);

    scene_manager.get_current_scene().draw(window);

    window.display();
}

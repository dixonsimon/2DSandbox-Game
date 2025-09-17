#include "Game.h"
#include <SFML/Graphics.hpp>

Game::Game()
    // In SFML 3, VideoMode constructor now takes a sf::Vector2u
    : mWindow(sf::VideoMode({ 1280, 720 }), "2D Sandbox Game", sf::Style::Close | sf::Style::Titlebar)
    , mWorld(50, 50)
    , mPlayer(mWorld)
{
    // Set the player's initial position
    mPlayer.setPosition(100.f, 100.f);
}

void Game::run()
{
    sf::Clock clock;
    sf::Time timeSinceLastUpdate = sf::Time::Zero;

    while (mWindow.isOpen())
    {
        timeSinceLastUpdate += clock.restart();
        while (timeSinceLastUpdate > TimePerFrame)
        {
            timeSinceLastUpdate -= TimePerFrame;
            processEvents();
            update(TimePerFrame);
        }
        render();
    }
}

void Game::processEvents()
{
    // SFML 3 uses a new event loop style with helper methods
    while (const auto event = mWindow.pollEvent())
    {
        // Check for the window closed event using the is() helper
        if (event->is<sf::Event::Closed>())
        {
            mWindow.close();
        }

        // Check for mouse button presses using the getIf() helper
        if (const auto* mousePressed = event->getIf<sf::Event::MouseButtonPressed>())
        {
            // In SFML 3, mouse buttons are in a sub-enum sf::Mouse::Button
            if (mousePressed->button == sf::Mouse::Button::Left)
            {
                sf::Vector2i mousePos = sf::Mouse::getPosition(mWindow);
                mWorld.setTile(mousePos.x, mousePos.y, Tile::Type::Stone);
            }
            else if (mousePressed->button == sf::Mouse::Button::Right)
            {
                sf::Vector2i mousePos = sf::Mouse::getPosition(mWindow);
                mWorld.setTile(mousePos.x, mousePos.y, Tile::Type::Air);
            }
        }
    }
}

void Game::update(sf::Time deltaTime)
{
    mPlayer.update(deltaTime);
}

void Game::render()
{
    mWindow.clear();
    mWorld.draw(mWindow);
    mPlayer.draw(mWindow);
    mWindow.display();
}


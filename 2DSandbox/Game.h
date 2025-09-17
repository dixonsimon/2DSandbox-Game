#ifndef GAME_H
#define GAME_H

#include <SFML/Graphics.hpp>
#include "World.h"
#include "Player.h"

class Game {
public:
    Game();
    void run();

private:
    void processEvents();
    void update(sf::Time deltaTime);
    void render();

    sf::RenderWindow mWindow;
    World mWorld;
    Player mPlayer;

    const sf::Time TimePerFrame = sf::seconds(1.f / 60.f);
};

#endif // GAME_H

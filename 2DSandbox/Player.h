#ifndef PLAYER_H
#define PLAYER_H

#include <SFML/Graphics.hpp>

class World; // Forward declaration

class Player {
public:
    Player(World& world);
    void update(sf::Time deltaTime);
    void draw(sf::RenderWindow& window);
    void setPosition(float x, float y);
    // This declaration was missing
    sf::Vector2f getPosition() const;

private:
    sf::RectangleShape mShape;
    sf::Vector2f mVelocity;
    World& mWorld;
    bool mIsJumping;
};

#endif // PLAYER_H


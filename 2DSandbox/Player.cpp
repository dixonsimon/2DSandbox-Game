#include "Player.h"
#include "World.h"
#include "Tile.h"

Player::Player(World& world)
    : mWorld(world), mVelocity(0, 0), mIsJumping(false)
{
    mShape.setSize({ static_cast<float>(Tile::TILE_SIZE), static_cast<float>(Tile::TILE_SIZE * 2) });
    mShape.setFillColor(sf::Color::Blue);
    // In SFML 3, setPosition now takes a single sf::Vector2f argument
    mShape.setPosition({ 100.f, 100.f });
}

void Player::update(sf::Time deltaTime)
{
    float speed = 200.f;
    mVelocity.x = 0;

    // In SFML 3, Keyboard keys are in a sub-enum sf::Keyboard::Key
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A)) {
        mVelocity.x -= speed;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D)) {
        mVelocity.x += speed;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Space) && !mIsJumping) {
        mVelocity.y = -500.f;
        mIsJumping = true;
    }

    mVelocity.y += 1000.f * deltaTime.asSeconds(); // Gravity

    sf::Vector2f pos = mShape.getPosition();
    sf::Vector2f size = mShape.getSize();
    pos += mVelocity * deltaTime.asSeconds();

    int tileX = static_cast<int>((pos.x + size.x / 2) / Tile::TILE_SIZE);
    int tileY = static_cast<int>((pos.y + size.y) / Tile::TILE_SIZE);

    if (mWorld.getTile(tileX, tileY) != Tile::Type::Air) {
        pos.y = static_cast<float>(tileY * Tile::TILE_SIZE) - size.y;
        mVelocity.y = 0;
        mIsJumping = false;
    }

    // In SFML 3, setPosition now takes a single sf::Vector2f argument
    mShape.setPosition(pos);
}

void Player::draw(sf::RenderWindow& window)
{
    window.draw(mShape);
}

void Player::setPosition(float x, float y)
{
    // In SFML 3, setPosition now takes a single sf::Vector2f argument
    mShape.setPosition({ x, y });
}

sf::Vector2f Player::getPosition() const
{
    return mShape.getPosition();
}


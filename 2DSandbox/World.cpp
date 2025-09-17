#include "World.h"
#include "Tile.h"
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/RectangleShape.hpp>

World::World(int width, int height)
    : mWidth(width), mHeight(height)
{
    mTiles.resize(width * height, Tile::Type::Air);
    for (int x = 0; x < width; ++x) {
        // Use the tile-based coordinates for setting initial world state
        setTile(x * Tile::TILE_SIZE, (height - 1) * Tile::TILE_SIZE, Tile::Type::Grass);
        setTile(x * Tile::TILE_SIZE, (height - 2) * Tile::TILE_SIZE, Tile::Type::Dirt);
        setTile(x * Tile::TILE_SIZE, (height - 3) * Tile::TILE_SIZE, Tile::Type::Dirt);
    }
    mTileShape.setSize({ static_cast<float>(Tile::TILE_SIZE), static_cast<float>(Tile::TILE_SIZE) });
}

Tile::Type World::getTile(int x, int y) const
{
    if (x < 0 || x >= mWidth || y < 0 || y >= mHeight) {
        return Tile::Type::Air;
    }
    return mTiles[y * mWidth + x];
}

void World::setTile(int pixelX, int pixelY, Tile::Type type)
{
    // Convert pixel coordinates to tile coordinates
    int tileX = pixelX / Tile::TILE_SIZE;
    int tileY = pixelY / Tile::TILE_SIZE;

    if (tileX < 0 || tileX >= mWidth || tileY < 0 || tileY >= mHeight) {
        return;
    }
    mTiles[tileY * mWidth + tileX] = type;
}

void World::draw(sf::RenderWindow& window)
{
    for (int y = 0; y < mHeight; ++y) {
        for (int x = 0; x < mWidth; ++x) {
            Tile::Type tile = getTile(x, y);
            if (tile != Tile::Type::Air) {
                switch (tile) {
                case Tile::Type::Grass: mTileShape.setFillColor(sf::Color::Green); break;
                case Tile::Type::Dirt: mTileShape.setFillColor(sf::Color(139, 69, 19)); break;
                case Tile::Type::Stone: mTileShape.setFillColor(sf::Color(128, 128, 128)); break;
                default: break;
                }
                // In SFML 3, setPosition now takes a single sf::Vector2f argument
                mTileShape.setPosition({ static_cast<float>(x * Tile::TILE_SIZE), static_cast<float>(y * Tile::TILE_SIZE) });
                window.draw(mTileShape);
            }
        }
    }
}


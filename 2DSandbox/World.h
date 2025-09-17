#ifndef WORLD_H
#define WORLD_H

#include <SFML/Graphics.hpp>
#include <vector>
#include "Tile.h"

class World {
public:
    World(int width, int height);
    Tile::Type getTile(int x, int y) const;
    void setTile(int pixelX, int pixelY, Tile::Type type);
    void draw(sf::RenderWindow& window);

private:
    int mWidth;
    int mHeight;
    // This declaration was missing
    std::vector<Tile::Type> mTiles;
    sf::RectangleShape mTileShape;
};

#endif // WORLD_H


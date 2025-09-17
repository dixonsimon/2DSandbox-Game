#ifndef TILE_H
#define TILE_H

namespace Tile {
    // Defines the size of each tile in pixels
    const int TILE_SIZE = 32;

    // Enumerates the different types of tiles available
    enum class Type {
        Air,
        Dirt,
        Grass,
        Stone
    };
}

#endif // TILE_H

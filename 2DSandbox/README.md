# 2D Sandbox Game in C++

![SFML Logo](https://www.sfml-dev.org/images/sfml-logo-big.png)

A simple 2D sandbox game built from scratch using C++ and the [SFML](https://www.sfml-dev.org/) library. This project serves as a foundational example of a 2D game engine, featuring a main game loop, player physics, and dynamic world interaction.

## Features
-   **Player Controller:** Move left, right, and jump with basic physics.
-   **Gravity Simulation:** The player is affected by gravity and will fall if not on a solid block.
-   **Dynamic World:** The world is made of tiles that can be added or removed at runtime.
-   **Tile Interaction:**
    -   Destroy existing tiles (dirt/grass) with a left-click.
    -   Place new dirt tiles with a right-click.
-   **Simple Camera:** The view is currently static, focused on the player's starting area.

## Controls
| Key             | Action              |
| --------------- | ------------------- |
| **A / D** | Move Left / Right   |
| **Spacebar** | Jump                |
| **Left Click** | Destroy Tile        |
| **Right Click** | Place Dirt Tile     |
| **Escape** | Close the Game      |

## Built With
* **C++ 20** - Core programming language.
* **SFML 3.0.1** - Simple and Fast Multimedia Library for handling windowing, graphics, and input.
* **CMake** - Cross-platform build system.

## Getting Started

Follow these instructions to get a local copy up and running for development and testing.

### Prerequisites
Before you begin, ensure you have the following installed:
* A C++ compiler that supports C++17 or newer (e.g., GCC/MinGW, Clang, MSVC).
* [CMake](https://cmake.org/download/) (version 3.10 or higher).
* [SFML 3.0.1 SDK](https://www.sfml-dev.org/download/sfml/3.0.1/) downloaded and extracted. Make sure to download the version that matches your compiler (e.g., MinGW or Visual Studio).

### Installation & Building
1.  **Clone the repository:**
    ```sh
    git clone [https://github.com/your-username/2dsandbox-game.git](https://github.com/your-username/2dsandbox-game.git)
    cd 2dsandbox-game
    ```

2.  **Configure the project with CMake:**
    Run the following command from the root of the project directory. Make sure to replace `C:/path/to/SFML-3.0.1` with the actual path where you extracted the SFML SDK.

    ```sh
    # This creates a 'build' directory and generates the build files inside it
    cmake -S . -B build -DSFML_DIR=C:/path/to/SFML-3.0.1/lib/cmake/SFML
    ```

3.  **Build the project:**
    Now, compile the source code using CMake's build command.

    ```sh
    cmake --build build
    ```

4.  **Run the game:**
    * The executable (`2DSandbox.exe`) will be located in the `build` directory.
    * **Important:** Before running, you must copy the SFML DLL files (e.g., `sfml-graphics-d-3.dll`, `sfml-window-d-3.dll`, etc.) from the SFML `bin` directory into your `build` directory alongside the executable.

## Project Structure
The codebase is organized into several classes to separate concerns:
```
.
├── src/
│   ├── Game.h, Game.cpp         # Manages the game loop, window, and events.
│   ├── Player.h, Player.cpp     # Handles player logic, physics, and rendering.
│   ├── World.h, World.cpp       # Manages the tile grid, world generation, and rendering.
│   ├── Tile.h                   # Defines the different types of tiles.
│   └── main.cpp                 # Main entry point for the application.
├── CMakeLists.txt               # The main CMake build script.
└── README.md                    # This file.
```

## License
This project is licensed under the MIT License - see the `LICENSE.md` file for details.
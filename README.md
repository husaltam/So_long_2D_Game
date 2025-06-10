# So Long - A 2D Game Project

## Description

So Long is a basic 2D game developed as part of a computer graphics project. The game involves a player (represented by a dolphin or any character of your choice) who must collect all the fish (or collectibles) on the map and escape through the exit. [cite_start]The project focuses on working with textures, sprites, and basic gameplay elements using the MiniLibX library.

## Features

* [cite_start]**Window Management**: Opens a window to display the game and handles events like closing the window or pressing the ESC key.
* [cite_start]**Player Movement**: The player can move in four directions (up, down, left, right) using the W, A, S, D keys or arrow keys.
* [cite_start]**Map Parsing**: The game reads a map file with the `.ber` extension, validates it, and ensures it meets specific criteria (e.g., enclosed by walls, contains one exit, one player start, and at least one collectible).
* [cite_start]**Graphics**: Uses MiniLibX for rendering images and textures.
* [cite_start]**Movement Counter**: Displays the number of moves in the shell or on the screen (bonus).

## Requirements

* [cite_start]**Language**: C 
* [cite_start]**Library**: MiniLibX (provided by the school or installed from sources) 
* [cite_start]**Compiler**: GCC with flags `-Wall`, `-Wextra`, and `-Werror` 
* [cite_start]**Makefile**: Must include rules for `all`, `clean`, `fclean`, and `re` 

## Installation

1.  **Clone the repository:**
    ```bash
    git clone your_repository_link_here
    cd so_long
    ```

2.  **Compile the project:**
    ```bash
    make
    ```

## Usage

Run the game with a valid `.ber` map file as an argument:

```bash
./so_long maps/map1.ber

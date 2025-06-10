/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: husaltam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 19:39:05 by husaltam          #+#    #+#             */
/*   Updated: 2025/05/26 13:02:26 by husaltam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

/**
 * Resets the game state values (play_steps and game_finish flag) to their
 * initial state (zeros)
*/
static void	reset_game_state(t_game *game)
{
	game->play_steps = 0;
	game->game_finish = false;
}

/**
 * Initializes the game window using map dimensions from the game struct.
 * Calculates the window size based on the map, then creates the window using :
 	* *
	* mlx_new_window() → Creates a new window using the MLX library:
	* 	game->mlx: Pointer to the MLX connection (initialized via mlx_init).
	* 	game->window_width: Width of the window in pixels (based on map width).
	* 	game->window_hight: Height of the window in pixels (based on map height).
	* 	"so_long": Title of the window displayed in the window's title bar.
 * Returns a pointer to the newly created window and stores it in game->win.
 * Exits the program with an error if the window creation fails.
 */
static void	init_window(t_game *game)
{
	int	i;

	game->window_width = ft_strlen(game->map[0]) * TILE_SIZE;
	i = 0;
	while (game->map[i])
		i++;
	game->window_hight = i * TILE_SIZE;
	game->window_x11 = mlx_new_window(game->mlx, game->window_width,
			game->window_hight, "so_long");
	if (!game->window_x11)
		exit_with_error(game, "Error\nWindow creation failed");
}

/** 
 * Initializes the MLX library and assigns the MLX context to the game struct.
 * mlx_init() → Initializes the internal graphics context + connects 
 * to the display server
 */
static int	init_mlx(t_game *game)
{
	game->mlx = mlx_init();
	return (game->mlx != NULL);
}

/**
 * Main game initialization routine.
 * 
 * Initializes MLX, creates a window, resets game state, loads images, and draws 
 * the initial map.
 * Exits with an error if any of the initialization steps fail.
 */
void	load_game(t_game *game)
{
	if (!init_mlx(game))
		exit_with_error(game, "Error\nMLX init failed");
	init_window(game);
	reset_game_state(game);
	if (!img_init(game))
		exit_with_error(game, "Error\nFailed to load images");
	render_game_map(game);
}

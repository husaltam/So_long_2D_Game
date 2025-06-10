/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_game_map_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: husaltam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 19:39:05 by husaltam          #+#    #+#             */
/*   Updated: 2025/05/26 13:09:31 by husaltam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

/**
 * Draws a single image at a given tile location.
 */
void	render_image_x_y(t_game *game, void *image, int x, int y)
{
	if (image)
		mlx_put_image_to_window(game->mlx, game->window_x11, image,
			x * TILE_SIZE, (y * TILE_SIZE) + 64);
}

/**
 * Draws the player and updates their position.
 */
static void	draw_player(t_game *game, int x, int y)
{
	if (game->player)
	{
		game->player_x_pos = x;
		game->player_y_pos = y;
		render_image_x_y(game, game->player, x, y);
	}
}

/**
 * Draws the exit. Changes image if all collectibles are gathered.
 */
static void	draw_exit(t_game *game, int x, int y)
{
	if (game->collectible_n == 0 && game->exit)
	{
		mlx_destroy_image(game->mlx, game->exit);
		game->exit = mlx_xpm_file_to_image(
				game->mlx, EXIT_OPEN, &game->image_width, &game->image_hight);
	}
	render_image_x_y(game, game->exit, x, y);
}

/**
 * Draws a tile based on map character.
 */
static void	draw_tile(t_game *game, char tile, int x, int y)
{
	if (tile == '1')
		render_image_x_y(game, game->wall, x, y);
	else if (tile == '0')
		render_image_x_y(game, game->floor, x, y);
	else if (tile == 'P')
		draw_player(game, x, y);
	else if (tile == 'C')
		render_image_x_y(game, game->collectible, x, y);
	else if (tile == 'E')
		draw_exit(game, x, y);
	else if (tile == 'X')
		render_image_x_y(game, game->patrol, x, y);
}

/**
 * Iterates over the map and draws each tile.
 */
int	render_game_map(t_game *game)
{
	int				y;
	int				x;

	y = 0;
	while (game->map[y])
	{
		x = 0;
		while (game->map[y][x])
		{
			draw_tile(game, game->map[y][x], x, y);
			x++;
		}
		y++;
	}
	render_score_screen(game);
	game->color = GOLD;
	if ((game->game_finish && game->collectible_n != 0) || game->player_die)
		put_bold_text(game, game->window_width / 2 - 40,
			game->window_hight / 20, "GAME OVER!");
	else if (game->game_finish && game->collectible_n == 0 && !game->player_die)
		put_bold_text(game, game->window_width / 2 - 40,
			game->window_hight / 20, "Congratulations, YOU WON!");
	return (0);
}

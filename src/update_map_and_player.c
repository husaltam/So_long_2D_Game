/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_map_and_player.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: husaltam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 19:39:05 by husaltam          #+#    #+#             */
/*   Updated: 2025/05/26 13:01:48 by husaltam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

/**
 * Updates the player's sprite image based on movement direction.
 */
void	player_update_image(char direction_char, t_game *game)
{
	char	*new_img_path;

	if (direction_char == 'd')
		new_img_path = PLAYER_IMG_R;
	else if (direction_char == 'a')
		new_img_path = PLAYER_IMG_L;
	else
		return ;
	if (game->player)
		mlx_destroy_image(game->mlx, game->player);
	game->player = mlx_xpm_file_to_image(game->mlx,
			new_img_path, &game->image_width, &game->image_hight);
	if (!game->player)
		exit_with_error(game, "Failed to load player after direction change.");
}

/**
 * Handles the logic when the player moves onto a collectible.
 */
static void	handle_collectible(t_game *game)
{
	game->collectible_n--;
	ft_printf("Collected an item! %d remaining.\n", game->collectible_n);
}

/**
 * Handles the logic when the player attempts to move onto the exit.
 */
static int	handle_exit_condition(t_game *game, int old_x, int old_y)
{
	if (game->collectible_n == 0)
	{
		game->play_steps++;
		game->game_finish = true;
		game->map[old_y][old_x] = '0';
		ft_printf("Congratulations! You completed the game in %d moves!\n",
			game->play_steps);
		return (1);
	}
	else
	{
		ft_printf("You need to collect all items before exiting! \
			(%d remaining)\n", game->collectible_n);
		return (0);
	}
}

/**
 * Updates the map array and player's current coordinates.
 */
static void	update_map_and_player_pos(t_game *game, int old_x, int old_y)
{
	game->map[old_y][old_x] = '0';
	game->map[game->player_y_pos][game->player_x_pos] = 'P';
	game->play_steps++;
}

/**
 * Resolves the outcome of a player's attempted move.
 * Returns 1 if a move was successful and game state changed, 0 otherwise.
 * Max 25 lines
 */
int	resolve_move(t_game *game, int target_x, int target_y)
{
	char	target_tile;
	int		old_x;
	int		old_y;

	old_x = game->player_x_pos;
	old_y = game->player_y_pos;
	target_tile = game->map[target_y][target_x];
	if (target_tile == '1')
		return (0);
	if (target_tile == 'E')
		return (handle_exit_condition(game, old_x, old_y));
	if (target_tile == 'C')
		handle_collectible(game);
	game->player_x_pos = target_x;
	game->player_y_pos = target_y;
	update_map_and_player_pos(game, old_x, old_y);
	return (1);
}

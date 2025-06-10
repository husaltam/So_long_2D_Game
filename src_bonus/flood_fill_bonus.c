/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: husaltam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 15:44:35 by husaltam          #+#    #+#             */
/*   Updated: 2025/06/09 15:44:37 by husaltam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

static void	check_instant_death(t_game *game)
{
	int	px;
	int	py;

	px = game->player_x_pos;
	py = game->player_y_pos;
	if (game->map[py][px + 1] == 'X' || game->map[py][px - 1] == 'X')
	{
		log_validation_error(game,
			"Map invalid: Player starts next to a patrol (unwinnable)");
	}
}

// Helper: Flood-fill algorithm to mark reachable areas
static void	fill(char **map, int x, int y)
{
	if (y < 0 || x < 0 || !map[y] || !map[y][x])
		return ;
	if (map[y][x] == '1' || map[y][x] == 'V')
		return ;
	if (map[y][x] == '0' || map[y][x] == 'P'
		|| map[y][x] == 'C' || map[y][x] == 'X')
	{
		map[y][x] = 'V';
		fill(map, x + 1, y);
		fill(map, x - 1, y);
		fill(map, x, y + 1);
		fill(map, x, y - 1);
	}
	else if (map[y][x] == 'E')
	{
		map[y][x] = 'R';
	}
}

// Helper: Check for remaining collectibles or unreachable exit
static int	has_unreachable(char **map)
{
	int	y;
	int	x;

	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == 'C' || map[y][x] == 'E')
				return (1);
			x++;
		}
		y++;
	}
	return (0);
}

// Main validation function
void	flood_fill(char **temp_map, t_game *game)
{
	check_instant_death(game);
	fill(temp_map, game->player_x_pos, game->player_y_pos);
	if (has_unreachable(temp_map))
	{
		log_validation_error(game,
			"floodfill(): No valid path to collectibles/exit");
	}
}

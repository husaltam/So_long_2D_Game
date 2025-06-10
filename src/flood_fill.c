/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: husaltam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 13:22:48 by husaltam          #+#    #+#             */
/*   Updated: 2025/06/09 13:22:51 by husaltam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	fill(char **map, int x, int y)
{
	if (y < 0 || x < 0 || !map[y] || !map[y][x])
		return ;
	if (map[y][x] == '1' || map[y][x] == 'V')
		return ;
	if (map[y][x] == '0' || map[y][x] == 'P' || map[y][x] == 'C')
	{
		map[y][x] = 'V';
		fill(map, x + 1, y);
		fill(map, x - 1, y);
		fill(map, x, y + 1);
		fill(map, x, y - 1);
	}
	else if (map[y][x] == 'E')
		map[y][x] = 'R';
}

int	has_unreachable(char **map)
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

void	flood_fill(char **temp_map, t_game *game)
{
	fill(temp_map, game->player_x_pos, game->player_y_pos);
	if (has_unreachable(temp_map))
		log_validation_error(game, "No Valid Path for Winning has been found!");
}

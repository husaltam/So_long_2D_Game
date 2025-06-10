/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_patrol_movement.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: husaltam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 22:22:26 by husaltam          #+#    #+#             */
/*   Updated: 2025/06/09 22:22:36 by husaltam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

int	collect_patrols(t_game *game, t_patrol *patrols, int max)
{
	int	x;
	int	y;
	int	count;

	y = 0;
	count = 0;
	while (y < game->map_hight)
	{
		x = 0;
		while (x < game->map_width)
		{
			if (game->map[y][x] == 'X' && count < max)
			{
				patrols[count].x = x;
				patrols[count].y = y;
				patrols[count].dir = game->patrol_dirs[y][x];
				count++;
			}
			x++;
		}
		y++;
	}
	return (count);
}

static bool	handle_patrol_collision(t_game *game, int y, int x)
{
	game->map[y][x] = '0';
	render_game_map(game);
	player_die(game);
	return (true);
}

static void	update_patrol_position(t_game *game, t_patrol *patrol, int new_x)
{
	game->map[patrol->y][patrol->x] = '0';
	game->map[patrol->y][new_x] = 'X';
	game->patrol_dirs[patrol->y][new_x] = patrol->dir;
	game->patrol_dirs[patrol->y][patrol->x] = 0;
}

static void	reverse_patrol_direction(t_game *game, t_patrol *patrol)
{
	game->patrol_dirs[patrol->y][patrol->x] = -patrol->dir;
}

bool	process_patrol_movement(t_game *game, t_patrol *patrol)
{
	int	new_x;

	new_x = patrol->x + patrol->dir;
	if (new_x >= 0 && new_x < game->map_width
		&& game->map[patrol->y][new_x] == '0')
	{
		update_patrol_position(game, patrol, new_x);
	}
	else if (new_x >= 0 && new_x < game->map_width
		&& game->map[patrol->y][new_x] == 'P')
	{
		return (handle_patrol_collision(game, patrol->y, patrol->x));
	}
	else
	{
		reverse_patrol_direction(game, patrol);
	}
	return (false);
}

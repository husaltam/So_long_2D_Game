/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   perform_map_validation_bonus.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: husaltam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 19:39:05 by husaltam          #+#    #+#             */
/*   Updated: 2025/05/26 13:09:10 by husaltam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

/**
 *	Check if map has:
 *	- Exactly one player.
 *	- At least one exit.
 *	- At least one collectible.
*/
void	check_required_entities(t_game *game)
{
	if (game->player_n != 1)
		log_validation_error(game, "Player Count not Correct!");
	if (game->exit_n != 1)
		log_validation_error(game, "Exit-Door Count not Correct!");
	if (game->collectible_n < 1)
		log_validation_error(game, "Map has no Collectibles!");
}

/**
 *	Count occurrences of 'P', 'E', and 'C' in the map.
 *	- Validates that all characters are one of: 'P', 'E', 'C', '0', '1'.
 *	- Updates info struct with player, exit, and collect counts.
 *	Returns 1 if all characters are valid, 0 otherwise.
*/
void	count_map_entities(t_game *game)
{
	int	i;
	int	j;

	i = -1;
	while (++i < game->map_hight)
	{
		j = -1;
		while (++j < game->map_width)
		{
			if (game->map[i][j] == 'P')
			{
				game->player_n++;
				game->player_x_pos = j;
				game->player_y_pos = i;
			}
			else if (game->map[i][j] == 'E')
				game->exit_n++;
			else if (game->map[i][j] == 'C')
				game->collectible_n++;
			else if (game->map[i][j] != '0' && game->map[i][j] != '1'
					&& game->map[i][j] != 'X')
				log_validation_error(game, "Invalid Map Character/s Found!");
		}
	}
}

/**
 *	Check if the map is properly enclosed by walls.
 *	- Top and bottom rows must be entirely '1'.
 *	- Left and right borders of each middle row must be '1'.
 *	Returns 1 if all borders are valid, 0 otherwise.
*/
void	check_map_border_walls(t_game *game)
{
	int	i;

	i = 0;
	while (i < game->map_width)
	{
		if (game->map[0][i] != '1' || game->map[game->map_hight - 1][i] != '1')
		{
			log_validation_error(game, "Map not Enclosed with Walls!");
			break ;
		}
		i++;
	}
	i = 1;
	while (i < game->map_hight - 1)
	{
		if (game->map[i][0] != '1' || game->map[i][game->map_width - 1] != '1')
		{
			log_validation_error(game, "Map not Enclosed with Walls!");
			break ;
		}
		i++;
	}
}

/**
 *	Calculate map (height / width).
 *	- Validates that the map is rectangular [Ensure each line has same lenght].
 *	- Resets player, exit, and collect counts.
 *	Returns 0 if the map is invalid or empty, 1 otherwise.
*/
void	compute_map_metrics(t_game *game)
{
	game->map_hight = 0;
	if (!game->map || !game->map[0])
	{
		log_validation_error(game, "Map failed to load!");
		return ;
	}
	game->map_width = ft_strlen(game->map[0]);
	while (game->map[game->map_hight])
	{
		if ((int)ft_strlen(game->map[game->map_hight]) != game->map_width)
		{
			log_validation_error(game, "Map Lines are not Equal!");
		}
		game->map_hight++;
	}
	game->player_n = 0;
	game->exit_n = 0;
	game->collectible_n = 0;
}

/**
 *	Main map validation function.
*/
int	perform_map_validation(t_game *game, char *file)
{
	char	**temp_map;

	compute_map_metrics(game);
	check_map_border_walls(game);
	count_map_entities(game);
	check_required_entities(game);
	temp_map = parse_map_file(file);
	flood_fill(temp_map, game);
	free_map(temp_map);
	game->collectible_total = game->collectible_n;
	return (!game->validation_failed);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: husaltam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 19:39:05 by husaltam          #+#    #+#             */
/*   Updated: 2025/05/26 13:10:05 by husaltam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

static void	init_patrol_dirs(t_game *game)
{
	int	y;
	int	x;

	game->patrol_dirs = malloc(sizeof(int *) * game->map_hight);
	y = 0;
	while (y < game->map_hight)
	{
		game->patrol_dirs[y] = malloc(sizeof(int) * game->map_width);
		x = 0;
		while (x < game->map_width)
		{
			if (game->map[y][x] == 'X')
				game->patrol_dirs[y][x] = 1;
			else
				game->patrol_dirs[y][x] = 0;
			x++;
		}
		y++;
	}
}

/**
 * exit_with_error - Prints error message, frees map if loaded, and exits.
 */
void	exit_with_error(t_game *game, char *msg)
{
	if (game->map)
		free_map(game->map);
	ft_printf("Error!\n%s\n", msg);
	exit(1);
}

void	log_validation_error(t_game *game, const char *message)
{
	ft_printf("%s\n", message);
	game->validation_failed = true;
}

/**
 * validate_and_load - Reads and validates the game map.
 * Description: Exits the program if map cannot be loaded or is invalid.
 */
void	validate_and_load(t_game *game, char *file)
{
	game->map = parse_map_file(file);
	if (!game->map)
		exit_with_error(game, "→ Map has Extra Empty lines!");
	if (!perform_map_validation(game, file))
		exit_with_error(game, "→ Invalid Map Content!");
	init_patrol_dirs(game);
}

/**
 * validate_args - Checks argument count and `.ber` file extension.
 * file: The file path provided by the user.
 * Return: 1 if valid, 0 otherwise.
 */
int	validate_args(int argc, char *file)
{
	int	len;

	if (argc != 2)
	{
		ft_printf("Invalid Syntax!\n");
		ft_printf("Example usage:\n");
		ft_printf("./so_long_bonus asseets/maps_bonus/map.ber\n\n");
		return (0);
	}
	len = ft_strlen(file);
	if (len < 5 || file[len - 1] != 'r' || file[len - 2] != 'e'
		|| file[len - 3] != 'b' || file[len - 4] != '.')
	{
		ft_printf("Error\nInvalid File Extension!\n");
		return (0);
	}
	return (1);
}

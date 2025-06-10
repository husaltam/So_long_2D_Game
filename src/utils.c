/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: husaltam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 19:39:05 by husaltam          #+#    #+#             */
/*   Updated: 2025/05/26 13:01:58 by husaltam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

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
		exit_with_error(game, "→ Map could not be read\
							\n→ Map has Extra Empty lines!.");
	if (!perform_map_validation(game, file))
		exit_with_error(game, "→ Invalid Map Content.");
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
		ft_printf("Invalid Syntax\n");
		ft_printf("Example usage: ./so_long asseets/maps/map.ber\n");
		return (0);
	}
	len = ft_strlen(file);
	if (len < 5 || file[len - 1] != 'r' || file[len - 2] != 'e'
		|| file[len - 3] != 'b' || file[len - 4] != '.')
	{
		ft_printf("Error\nInvalid File Extension\n");
		return (0);
	}
	return (1);
}

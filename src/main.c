/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: husaltam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 19:39:05 by husaltam          #+#    #+#             */
/*   Updated: 2025/06/09 13:15:53 by husaltam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	file_checker(const char *filepath)
{
	int	fd;

	fd = open(filepath, O_RDONLY);
	if (fd == -1)
	{
		perror(filepath);
		return (0);
	}
	close(fd);
	return (1);
}

void	check_file_access(void)
{
	int			i;
	const char	**all_image_paths;

	all_image_paths = (const char *[]){
		WALL_IMG, FLOOR_IMG, EXIT_OPEN, EXIT_CLOSED,
		PLAYER_IMG_R, PLAYER_IMG_L, COLLECT_1,
		NULL};
	i = 0;
	while (all_image_paths[i])
	{
		if (!file_checker(all_image_paths[i]))
			exit(EXIT_FAILURE);
		i++;
	}
}

/**
 * start_game - Initializes and starts the game loop.
 */
static void	start_game(t_game *game)
{
	load_game(game);
	setup_event_hooks(game);
	mlx_loop(game->mlx);
}

/*********************************
 * main - Entry point of the game
	 **
	 * Zero-initializes the entire game structure before use.
	 * Ensures all pointers are NULL and integers are 0, avoiding
	 * undefined behavior from uninitialized memory.
	 *
   Return: 0 on success, 1 on argument error.
 */
int	main(int argc, char **argv)
{
	t_game	game;
	char	*path;

	check_file_access();
	ft_memset(&game, 0, sizeof(t_game));
	if (!validate_args(argc, argv[1]))
		return (1);
	path = argv[1];
	validate_and_load(&game, path);
	ft_printf("Game started!\n");
	start_game(&game);
	return (0);
}

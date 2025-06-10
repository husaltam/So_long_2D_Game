/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: husaltam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 19:39:05 by husaltam          #+#    #+#             */
/*   Updated: 2025/05/26 13:08:55 by husaltam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

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
		PLAYER_IMG_R, PLAYER_IMG_L, PLAYER_DEATH,
		PATROL_1, PATROL_2, PATROL_3, PATROL_4, PATROL_5, PATROL_6,
		PATROL_7, PATROL_8, PATROL_9, PATROL_10, PATROL_11,
		COLLECT_1, COLLECT_2, COLLECT_3, COLLECT_4,
		COLLECT_5, COLLECT_6, COLLECT_7, COLLECT_8,
		NULL
	};
	i = 0;
	while (all_image_paths[i])
	{
		if (!file_checker(all_image_paths[i]))
			exit(EXIT_FAILURE);
		i++;
	}
}

/*
 * Resets the game state values to their initial state (zeros)
*/
void	reset_game_state(t_game *game)
{
	game->play_steps = 0;
	game->patrol_state = 1;
	game->collectible_state = 1;
	game->patrol_loop = 0;
	game->collectible_loop = 0;
	game->patrol_pause_counter = 0;
	game->game_finish = false;
	game->player_die = false;
	game->validation_failed = false;
	game->patrol_direction = 1;
}

/*
 * start_game - Initializes and starts the game loop.
 */
static void	start_game(t_game *game)
{
	reset_game_state(game);
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

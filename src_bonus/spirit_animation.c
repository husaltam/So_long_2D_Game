/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spirit_animation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: husaltam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 19:39:05 by husaltam          #+#    #+#             */
/*   Updated: 2025/05/26 13:09:49 by husaltam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

void	handle_collectible_animation(t_game *game)
{
	const char	**collectibles;

	collectibles = (const char *[]){
		COLLECT_1, COLLECT_1, COLLECT_2, COLLECT_2, COLLECT_3, COLLECT_4,
		COLLECT_5, COLLECT_6, COLLECT_7, COLLECT_8, COLLECT_8, COLLECT_1};
	game->collectible_loop = 0;
	mlx_destroy_image(game->mlx, game->collectible);
	game->collectible = load_img(game, collectibles[game->collectible_state]);
	game->collectible_state = (game->collectible_state + 1) % 12;
	render_game_map(game);
}

static void	move_all_patrols(t_game *game)
{
	int			i;
	int			count;
	t_patrol	patrols[512];

	count = collect_patrols(game, patrols, 512);
	i = 0;
	while (i < count)
	{
		if (process_patrol_movement(game, &patrols[i]))
			return ;
		i++;
	}
}

/**
 * Handles patrol sprite animation and movement.
 */
void	handle_patrol_animation(t_game *game)
{
	const char	**sprites;

	sprites = (const char *[]){
		PATROL_1, PATROL_2, PATROL_3, PATROL_4, PATROL_5,
		PATROL_6, PATROL_7, PATROL_8, PATROL_9, PATROL_10, PATROL_11};
	game->patrol_loop = 0;
	if (game->patrol)
		mlx_destroy_image(game->mlx, game->patrol);
	game->patrol = load_img(game, sprites[game->patrol_state]);
	game->patrol_state = (game->patrol_state + 1) % 11;
	move_all_patrols(game);
	render_game_map(game);
}

int	animations_handler(t_game *game)
{
	if (game->game_finish)
		return (0);
	if (game->patrol_loop++ >= 2000)
		handle_patrol_animation(game);
	else if (game->collectible_loop++ >= 100)
		handle_collectible_animation(game);
	return (0);
}

void	player_die(t_game *game)
{
	mlx_destroy_image(game->mlx, game->player);
	mlx_clear_window(game->mlx, game->window_x11);
	game->player = load_img(game, PLAYER_DEATH);
	game->game_finish = true;
	game->player_die = true;
	ft_printf("game over!\nPress Q or ESC to quit the game!\n");
}

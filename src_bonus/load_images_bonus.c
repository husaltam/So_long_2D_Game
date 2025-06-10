/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_images_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: husaltam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 19:39:05 by husaltam          #+#    #+#             */
/*   Updated: 2025/05/26 13:08:47 by husaltam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

/**
 * Loads a single image and returns NULL on failure.
 */
void	*load_img(t_game *game, const char *path)
{
	return (mlx_xpm_file_to_image(game->mlx, (char *)path,
			&game->image_width, &game->image_hight));
}

/**
 * Loads all game images from file.
 */
int	img_init(t_game *game)
{
	game->floor = load_img(game, FLOOR_IMG);
	game->wall = load_img(game, WALL_IMG);
	game->player = load_img(game, PLAYER_IMG_R);
	game->collectible = load_img(game, COLLECT_1);
	game->exit = load_img(game, EXIT_CLOSED);
	game->patrol = load_img(game, PATROL_1);
	return (game->floor && game->wall && game->player
		&& game->collectible && game->exit && game->patrol);
}

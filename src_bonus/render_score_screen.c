/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_score_screen.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: husaltam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 15:16:07 by husaltam          #+#    #+#             */
/*   Updated: 2025/05/26 15:16:16 by husaltam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

void	put_bold_text(t_game *game, int x, int y, char *str)
{
	mlx_string_put(game->mlx, game->window_x11, x - 1, y, game->color, str);
	mlx_string_put(game->mlx, game->window_x11, x + 1, y, game->color, str);
	mlx_string_put(game->mlx, game->window_x11, x, y - 1, game->color, str);
	mlx_string_put(game->mlx, game->window_x11, x, y + 1, game->color, str);
	mlx_string_put(game->mlx, game->window_x11, x, y, 0xFFFFFF, str);
}

void	render_score_screen(t_game *game)
{
	char	*steps;
	char	*collected;
	char	*total;
	char	*xp_display;

	steps = ft_itoa(game->play_steps);
	collected = ft_itoa(game->collectible_collected);
	total = ft_itoa(game->collectible_total);
	xp_display = ft_strjoin(collected, " / ");
	xp_display = ft_strjoin_free(xp_display, total);
	game->color = GOLD;
	put_bold_text(game, 25, 20, "MOVES:");
	game->color = WHITE;
	put_bold_text(game, 90, 20, steps);
	game->color = GREEN;
	put_bold_text(game, 25, 40, "XP:");
	game->color = WHITE;
	put_bold_text(game, 90, 40, xp_display);
	free(steps);
	free(collected);
	free(total);
	free(xp_display);
}

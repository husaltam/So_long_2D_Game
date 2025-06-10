/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup_event_hooks.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: husaltam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 19:39:05 by husaltam          #+#    #+#             */
/*   Updated: 2025/05/26 13:01:39 by husaltam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

/**
 * Clears the window and redraws the entire map.
 * Called after any successful game state change (movement/interaction).
 */
static void	refresh_display(t_game *game)
{
	mlx_clear_window(game->mlx, game->window_x11);
	render_game_map(game);
}

/**
 * Extracts movement intent (delta_x, delta_y) and character for image.
 */
static void	movement_input(int keycode, int *dx, int *dy, char *dir_char)
{
	*dx = 0;
	*dy = 0;
	*dir_char = '\0';
	if (keycode == KEY_W || keycode == KEY_UP)
	{
		*dy = -1;
		*dir_char = 'w';
	}
	else if (keycode == KEY_S || keycode == KEY_DOWN)
	{
		*dy = 1;
		*dir_char = 's';
	}
	else if (keycode == KEY_D || keycode == KEY_RIGHT)
	{
		*dx = 1;
		*dir_char = 'd';
	}
	else if (keycode == KEY_A || keycode == KEY_LEFT)
	{
		*dx = -1;
		*dir_char = 'a';
	}
}

/**
 * Handles keyboard input during gameplay.
 * - ESC or Q: exit the game.
 * - If the game ended -> exit and prevent any event!
 * - WASD/Arrow keys: move the player if the game is not finished.
 * - Updates player direction, game state, and move count.
 */
static int	keypress(int keycode, t_game *game)
{
	int		dx;
	int		dy;
	int		moved;
	char	direction_char;

	if (keycode == KEY_ESC || keycode == KEY_Q)
		destroy_and_exit(game);
	if (game->game_finish)
		return (0);
	movement_input(keycode, &dx, &dy, &direction_char);
	if (direction_char != '\0')
	{
		player_update_image(direction_char, game);
		moved = resolve_move(game, game->player_x_pos
				+ dx, game->player_y_pos + dy);
		if (moved)
		{
			refresh_display(game);
			if (!game->game_finish)
				ft_printf("Moves: %d\n", game->play_steps);
		}
	}
	return (0);
}

/**
 * Wrapper for destroy_and_exit to be used as a hook for window close button.
 */
static int	exit_game_hook(t_game *game)
{
	destroy_and_exit(game);
	return (0);
}

/**
 * Sets up MinilibX event hooks for the game loop.
 * - Key press events trigger the keypress function.
 * - Window close button triggers the exit_game_hook function.
 */
void	setup_event_hooks(t_game *game)
{
	mlx_hook(game->window_x11, 2, 1L << 0, keypress, game);
	mlx_hook(game->window_x11, 17, 1L << 17, exit_game_hook, game);
}

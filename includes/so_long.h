/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: husaltam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 14:10:55 by husaltam          #+#    #+#             */
/*   Updated: 2025/05/26 13:13:02 by husaltam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <fcntl.h>
# include <errno.h>
# include <stdio.h>
# include "../lib/minilibx/mlx.h"
# include "../lib/libft/libft.h"
# include "../lib/ft_printf/ft_printf.h"
# include "../lib/get_next_line/get_next_line.h"

# define TILE_SIZE 64
# define KEY_ESC 65307
# define KEY_Q 113
# define KEY_W 119
# define KEY_A 97
# define KEY_S 115
# define KEY_D 100
# define KEY_UP 65362
# define KEY_LEFT 65361
# define KEY_DOWN 65364
# define KEY_RIGHT 65363

# define PLAYER_IMG_R  "assets/images/player_r.xpm"
# define PLAYER_IMG_L  "assets/images/player_l.xpm"
# define PLAYER_DEATH   "assets/images/death.xpm"
# define WALL_IMG    "assets/images/wall.xpm"
# define FLOOR_IMG   "assets/images/floor.xpm"
# define COLLECT_1 "assets/images/collectible_1.xpm"
# define EXIT_CLOSED "assets/images/door_closed.xpm"
# define EXIT_OPEN   "assets/images/door_open.xpm"

typedef struct s_game
{
	int		window_width;
	int		window_hight;
	int		map_width;
	int		map_hight;
	int		image_width;
	int		image_hight;
	int		collectible_n;
	int		player_n;
	int		exit_n;
	int		player_x_pos;
	int		player_y_pos;
	int		play_steps;
	int		game_finish;
	int		validation_failed;
	void	*mlx;
	void	*window_x11;
	char	**map;
	void	*floor;
	void	*wall;
	void	*player;
	void	*collectible;
	void	*exit;
}	t_game;

int		img_init(t_game *game);
int		render_game_map(t_game *game);
int		destroy_and_exit(t_game *game);
int		validate_args(int argc, char *file);
int		perform_map_validation(t_game *game, char *file);
int		resolve_move(t_game *game, int target_x, int target_y);
char	**parse_map_file(char *path);
void	free_map(char **map);
void	load_game(t_game *game);
void	setup_event_hooks(t_game *game);
void	exit_with_error(t_game *game, char *msg);
void	flood_fill(char **temp_map, t_game *game);
void	validate_and_load(t_game *game, char *file);
void	player_update_image(char dir, t_game *game);
void	player_update_image(char direction_char, t_game *game);
void	log_validation_error(t_game *game, const char *message);
void	render_image_x_y(t_game *game, void *image, int x, int y);

#endif

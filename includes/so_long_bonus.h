/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: husaltam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 14:10:55 by husaltam          #+#    #+#             */
/*   Updated: 2025/05/26 13:13:25 by husaltam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

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

# define WHITE 0xFFFFFF
# define RED   0xFF3333
# define GREEN 0x00CC66
# define BLUE  0x3399FF
# define GOLD  0xFF6600

# define WALL_IMG    "assets/images/wall.xpm"
# define FLOOR_IMG   "assets/images/floor.xpm"
# define EXIT_OPEN   "assets/images/door_open.xpm"
# define EXIT_CLOSED "assets/images/door_closed.xpm"
# define PLAYER_IMG_R  "assets/images/player_r.xpm"
# define PLAYER_IMG_L  "assets/images/player_l.xpm"
# define PLAYER_DEATH   "assets/images/death.xpm"

# define PATROL_1   "assets/images/patrol_1.xpm"
# define PATROL_2   "assets/images/patrol_2.xpm"
# define PATROL_3   "assets/images/patrol_3.xpm"
# define PATROL_4   "assets/images/patrol_4.xpm"
# define PATROL_5   "assets/images/patrol_5.xpm"
# define PATROL_6   "assets/images/patrol_6.xpm"
# define PATROL_7   "assets/images/patrol_7.xpm"
# define PATROL_8   "assets/images/patrol_8.xpm"
# define PATROL_9   "assets/images/patrol_9.xpm"
# define PATROL_10   "assets/images/patrol_10.xpm"
# define PATROL_11   "assets/images/patrol_11.xpm"

# define COLLECT_1 "assets/images/collectible_1.xpm"
# define COLLECT_2 "assets/images/collectible_2.xpm"
# define COLLECT_3 "assets/images/collectible_3.xpm"
# define COLLECT_4 "assets/images/collectible_4.xpm"
# define COLLECT_5 "assets/images/collectible_5.xpm"
# define COLLECT_6 "assets/images/collectible_6.xpm"
# define COLLECT_7 "assets/images/collectible_7.xpm"
# define COLLECT_8 "assets/images/collectible_8.xpm"

typedef struct s_text
{
	void	*mlx;
	void	*win;
	int		x;
	int		y;
	int		color;
	char	*str;
}	t_text;

typedef struct s_patrol
{
	int	x;
	int	y;
	int	dir;
}	t_patrol;

typedef struct s_game
{
	int			color;
	int			patrol_state;
	int			collectible_state;
	int			window_width;
	int			window_hight;
	int			map_width;
	int			map_hight;
	int			image_width;
	int			image_hight;
	int			collectible_n;
	int			collectible_total;
	int			collectible_collected;
	int			player_n;
	int			exit_n;
	int			player_x_pos;
	int			player_y_pos;
	int			play_steps;
	int			loop;
	int			patrol_loop;
	int			collectible_loop;
	int			patrol_pause_counter;
	int			validation_failed;
	int			n_patrols;
	int			**patrol_dirs;
	int			patrol_direction;
	void		*mlx;
	void		*window_x11;
	char		**map;
	void		*floor;
	void		*wall;
	void		*player;
	void		*collectible;
	void		*exit;
	void		*patrol;
	bool		game_finish;
	bool		player_die;
	t_patrol	*patrols;
}	t_game;

int		img_init(t_game *game);
int		render_game_map(t_game *game);
int		animations_handler(t_game *game);
int		destroy_and_exit(t_game *game);
int		validate_args(int argc, char *file);
int		perform_map_validation(t_game *game, char *file);
int		resolve_move(t_game *game, int target_x, int target_y);
int		collect_patrols(t_game *game, t_patrol *patrols, int max);
char	**parse_map_file(char *path);
void	free_map(char **map);
void	load_game(t_game *game);
void	player_die(t_game *game);
void	reset_game_state(t_game *game);
void	setup_event_hooks(t_game *game);
void	render_score_screen(t_game *game);
void	exit_with_error(t_game *game, char *msg);
void	flood_fill(char **temp_map, t_game *game);
void	*load_img(t_game *game, const char *path);
void	validate_and_load(t_game *game, char *file);
void	player_update_image(char dir, t_game *game);
void	put_bold_text(t_game *game, int x, int y, char *str);
void	player_update_image(char direction_char, t_game *game);
void	log_validation_error(t_game *game, const char *message);
void	render_image_x_y(t_game *game, void *image, int x, int y);
bool	process_patrol_movement(t_game *game, t_patrol *patrol);

#endif

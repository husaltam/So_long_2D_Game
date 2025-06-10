# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: husaltam <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/18 14:33:07 by husaltam          #+#    #+#              #
#    Updated: 2025/05/26 12:55:13 by husaltam         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME        = so_long
BONUS_NAME  = so_long_bonus

##############################################
#              Terminal Colors               #
##############################################

BRIGHT_AQUA = \033[1;38;5;51m  
SOLAR_YELLOW := \033[1;33m 
RESET       := \033[0m

##############################################
#        Compiler & Compilation Flags        #
##############################################

CC      = cc
CFLAGS  = -Wall -Wextra -Werror

##############################################
#        Source & Object Directories         #
##############################################

SRC_DIR         = src
BONUS_DIR       = src_bonus
LIB_SRC_DIR     = lib
MLX_DIR         = $(LIB_SRC_DIR)/minilibx

OBJ_ROOT_DIR    = obj
OBJ_SO_LONG_DIR = $(OBJ_ROOT_DIR)/so_long
OBJ_BONUS_DIR   = $(OBJ_ROOT_DIR)/so_long_bonus
OBJ_LIB_DIR     = $(OBJ_ROOT_DIR)/lib

##############################################
#             Library Paths/Names            #
##############################################

LIBFT   = $(OBJ_LIB_DIR)/libft_objs/libft.a
PRINTF  = $(OBJ_LIB_DIR)/ft_printf_objs/libftprintf.a
GNL     = $(OBJ_LIB_DIR)/get_next_line_objs/libgnl.a
MLX     = $(MLX_DIR)/libmlx.a

LIBS    = $(LIBFT) $(PRINTF) $(GNL) $(MLX) $(LIBFT)

##############################################
#               Include Paths                #
##############################################

INCLUDES = -I$(SRC_DIR) -I$(LIB_SRC_DIR)/libft \
		   -I$(LIB_SRC_DIR)/ft_printf \
		   -I$(LIB_SRC_DIR)/get_next_line -I$(MLX_DIR) \
		   -Iincludes

##############################################
#            Source & Object Files           #
##############################################

SRC_FILES = \
	$(SRC_DIR)/destroy_and_exit.c \
	$(SRC_DIR)/flood_fill.c \
	$(SRC_DIR)/load_game.c \
	$(SRC_DIR)/load_image.c \
	$(SRC_DIR)/main.c \
	$(SRC_DIR)/parse_map_file.c \
	$(SRC_DIR)/perform_map_validation.c \
	$(SRC_DIR)/render_game_map.c \
	$(SRC_DIR)/setup_event_hooks.c \
	$(SRC_DIR)/update_map_and_player.c \
	$(SRC_DIR)/utils.c

BONUS_FILES = \
	$(BONUS_DIR)/destroy_and_exit_bonus.c \
	$(BONUS_DIR)/event_hooks_bonus.c \
	$(BONUS_DIR)/flood_fill_bonus.c \
	$(BONUS_DIR)/load_game_bonus.c \
	$(BONUS_DIR)/load_images_bonus.c \
	$(BONUS_DIR)/main_bonus.c \
	$(BONUS_DIR)/parse_map_file_bonus.c \
	$(BONUS_DIR)/perform_map_validation_bonus.c \
	$(BONUS_DIR)/render_game_map_bonus.c \
	$(BONUS_DIR)/render_score_screen.c \
	$(BONUS_DIR)/spirit_animation.c \
	$(BONUS_DIR)/update_map_and_player_bonus.c \
	$(BONUS_DIR)/utils_bonus.c \
	$(BONUS_DIR)/process_patrol_movement.c

OBJ_FILES   = $(patsubst $(SRC_DIR)/%.c,$(OBJ_SO_LONG_DIR)/%.o,$(SRC_FILES))
BONUS_OBJS  = $(patsubst $(BONUS_DIR)/%.c,$(OBJ_BONUS_DIR)/%.o,$(BONUS_FILES))

##############################################
#                 Build Targets              #
##############################################

all: $(NAME)

bonus: $(BONUS_NAME)

# Link main executable
$(NAME): $(LIBS) $(OBJ_FILES)
	@echo "$(BRIGHT_AQUA)So_long GAME READY! ✨$(RESET)"
	@echo ""
	@$(CC) $(CFLAGS) $(OBJ_FILES) $(LIBS) -L$(OBJ_LIB_DIR) -L$(MLX_DIR) -lmlx -lXext -lX11 -lm -o $@

# Link bonus executable
$(BONUS_NAME): $(LIBS) $(BONUS_OBJS)
	@echo "$(BRIGHT_AQUA)🌟 BONUS LEVEL UNLOCKED! 🌟$(RESET)"
	@echo ""
	@$(CC) $(CFLAGS) $(BONUS_OBJS) $(LIBS) -L$(OBJ_LIB_DIR) -L$(MLX_DIR) -lmlx -lXext -lX11 -lm -o $@

# Compile main .c files into .o
$(OBJ_SO_LONG_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(@D)
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

# Compile bonus .c files into .o
$(OBJ_BONUS_DIR)/%.o: $(BONUS_DIR)/%.c
	@mkdir -p $(@D)
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

##############################################
#          Sub-library Build Targets         #
##############################################

$(OBJ_LIB_DIR):
	@mkdir -p $@

MAKEFLAGS += --no-print-directory

$(LIBFT):
	@$(MAKE) -C $(LIB_SRC_DIR)/libft

$(PRINTF):
	@$(MAKE) -C $(LIB_SRC_DIR)/ft_printf

$(GNL):
	@$(MAKE) -C $(LIB_SRC_DIR)/get_next_line

$(MLX):
	@$(MAKE) -C $(MLX_DIR)

##############################################
#             Cleaning Targets               #
##############################################

clean:
	@echo "$(SOLAR_YELLOW)Cleaning sub-libraries...$(RESET)"
	@$(MAKE) clean -C $(LIB_SRC_DIR)/libft
	@$(MAKE) clean -C $(LIB_SRC_DIR)/ft_printf
	@$(MAKE) clean -C $(LIB_SRC_DIR)/get_next_line
	@$(MAKE) clean -C $(MLX_DIR)
	@echo "$(SOLAR_YELLOW)Removing object directories...$(RESET)"
	@rm -rf $(OBJ_ROOT_DIR)

fclean: clean
	@echo "$(SOLAR_YELLOW)Full cleaning sub-libraries and executables...$(RESET)"
	@$(MAKE) fclean -C $(LIB_SRC_DIR)/libft
	@$(MAKE) fclean -C $(LIB_SRC_DIR)/ft_printf
	@$(MAKE) fclean -C $(LIB_SRC_DIR)/get_next_line
	@$(MAKE) fclean -C $(MLX_DIR)
	@rm -f $(NAME) $(BONUS_NAME)

re:
	@$(MAKE) fclean
	@echo "\n$(SOLAR_YELLOW)Rebuilding...\n$(RESET)"
	@$(MAKE) all

.PHONY: all clean fclean re bonus

# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: husaltam <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/21 13:33:45 by husaltam          #+#    #+#              #
#    Updated: 2025/05/21 13:34:47 by husaltam         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
NAME = ../../obj/lib/get_next_line_objs/libgnl.a
TEST = test_gnl

SRCDIR = .
OBJDIR = ../../obj/lib/get_next_line_objs

SRC =	get_next_line.c
OBJ = $(addprefix $(OBJDIR)/, $(SRC:.c=.o))

CC = cc
CFLAGS = -Wall -Wextra -Werror
AR = ar rcs

LIBFT_DIR = ../libft
PRINTF_DIR = ../ft_printf
INCLUDES = -I $(LIBFT_DIR) -I $(PRINTF_DIR)


# Silence all possible output
MAKEFLAGS += --no-print-directory --silent

all: $(OBJDIR) libs $(NAME)
	@echo "$(ORANGE)✓ GNL library ready$(RESET)"

libs:
	@$(MAKE) -C $(LIBFT_DIR) --no-print-directory --silent >/dev/null 2>&1
	@$(MAKE) -C $(PRINTF_DIR) --no-print-directory --silent >/dev/null 2>&1

$(OBJDIR):
	@mkdir -p $(OBJDIR)

$(NAME): $(OBJ)
	@$(AR) $@ $^

$(OBJDIR)/%.o: %.c | $(OBJDIR)
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

test: libs $(OBJ) main.c
	@$(CC) $(CFLAGS) $(OBJ) main.c -o $(TEST) $(INCLUDES) -L$(LIBFT_DIR) -lft -L$(PRINTF_DIR) -lftprintf
	@echo "$(GREEN)✓ Test executable ready$(RESET)"

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME) $(TEST)
	@$(MAKE) -C $(LIBFT_DIR) fclean --no-print-directory --silent >/dev/null 2>&1
	@$(MAKE) -C $(PRINTF_DIR) fclean --no-print-directory --silent >/dev/null 2>&1

re: fclean all

.PHONY: all libs $(OBJDIR) $(NAME) test clean fclean re
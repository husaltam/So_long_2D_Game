# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: husaltam <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/11 16:16:08 by husaltam          #+#    #+#              #
#    Updated: 2025/01/12 18:39:17 by husaltam         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ../../obj/lib/ft_printf_objs/libftprintf.a
CC = cc
CFLAGS = -Wall -Wextra -Werror
SRCDIR = .
OBJDIR = ../../obj/lib/ft_printf_objs
SRC =	ft_strcpy.c \
		ft_printf.c \
		ft_puthex.c \
		ft_putchar.c \
		ft_putnbr.c \
		ft_putptr.c \
		ft_putstr.c \
		ft_putunsigned.c \
		handle_conversion.c
OBJ = $(addprefix $(OBJDIR)/, $(SRC:.c=.o))
INCLUDES = -I.


# Silence directory messages
MAKEFLAGS += --no-print-directory

all: $(OBJDIR) $(NAME)
	@echo "$(BRIGHT_GREEN)✓ ft_printf library ready$(RESET)"

$(OBJDIR):
	@mkdir -p $(OBJDIR)

$(NAME): $(OBJ)
	@ar rcs $@ $^

$(OBJDIR)/%.o: %.c | $(OBJDIR)
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

test: $(NAME)
	@echo "$(MAGENTA)Building printf test...$(RESET)"
	@$(CC) $(CFLAGS) $(INCLUDES) $(SRC) main.c -o printf_test
	@echo "$(GREEN)Test executable ready!$(RESET)"

clean:
	@rm -f $(OBJ)
	@rm -f printf_test

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re test
# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: husaltam <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/19 16:41:08 by husaltam          #+#    #+#              #
#    Updated: 2025/05/21 13:24:13 by husaltam         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror

ROOT_OBJ_PATH = ../../obj
LIB_OUTPUT_DIR = $(ROOT_OBJ_PATH)/lib
OBJ_OUTPUT_DIR = $(LIB_OUTPUT_DIR)/libft_objs
NAME = $(OBJ_OUTPUT_DIR)/libft.a

SRCS =	ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c \
	ft_isprint.c ft_strlen.c ft_memset.c ft_bzero.c \
	ft_memcpy.c ft_memmove.c ft_strlcpy.c ft_strlcat.c \
	ft_strcmp.c \
	ft_toupper.c ft_tolower.c ft_strchr.c ft_strrchr.c \
	ft_strncmp.c ft_memchr.c ft_memcmp.c ft_strnstr.c \
	ft_atoi.c ft_calloc.c ft_strdup.c ft_substr.c ft_strjoin.c \
	ft_strjoin_free.c ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c \
	ft_striteri.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c

OBJECTS = $(patsubst %.c,$(OBJ_OUTPUT_DIR)/%.o,$(SRCS))

BONUS =	ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c \
	ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c

BONUS_OBJS = $(patsubst %.c,$(OBJ_OUTPUT_DIR)/%.o,$(BONUS))


all: $(NAME)
	@echo "$(HOT_PINK)✓ libft library ready$(RESET)"

$(OBJ_OUTPUT_DIR)/%.o: %.c
	@mkdir -p $(@D)
	@$(CC) $(CFLAGS) -c -o $@ $<

$(NAME): $(OBJECTS) 
	@mkdir -p $(LIB_OUTPUT_DIR)
	@ar rc $(NAME) $(OBJECTS)
	@ranlib $(NAME)

clean:
	@/bin/rm -f $(OBJECTS) $(BONUS_OBJS)
	@-rmdir $(OBJ_OUTPUT_DIR) 2>/dev/null || true
	@/bin/rm -f .ft_* .*.swp

fclean: clean
	@/bin/rm -f $(NAME)
	@-rmdir $(LIB_OUTPUT_DIR) 2>/dev/null || true

re: fclean all

bonus: $(OBJECTS) $(BONUS_OBJS)
	@mkdir -p $(LIB_OUTPUT_DIR)
	@ar rcs $(NAME) $(OBJECTS) $(BONUS_OBJS)

.PHONY: all clean fclean re bonus
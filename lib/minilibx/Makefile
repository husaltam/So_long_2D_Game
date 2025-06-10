##
## Makefile for MiniLibX in /home/boulon/work/c/raytraceur/minilibx
## 
## Made by Olivier Crouzet
## Login   <ol@epitech.net>
## 
## Started on  Tue Oct  5 15:56:43 2004 Olivier Crouzet
## Last update Tue May 15 15:44:41 2007 Olivier Crouzet
##

## Please use configure script


BOLD_ORANGE = \033[1;38;5;214m
RESET = \033[0m

NAME = minilibx

CC = gcc


all	: do_configure
	@echo "$(BRIGHT_AQUA)✓ Minilibx library ready\n$(RESET)"
do_configure	:
	@./configure > /dev/null 2>&1

clean	:
	@./configure clean > /dev/null 2>&1

# Fclean rule: Explicitly performs a full clean by calling configure's clean and the sub-Makefile's 'clean'
fclean	:
	@./configure clean > /dev/null 2>&1
	@$(MAKE) -s clean -C . # Calls the clean rule in the generated makefile (makefile.gen)

re	: clean all

.PHONY: all do_configure clean re


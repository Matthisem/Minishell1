##
## Makefile for pushswap in /home/wyzlic_a
##
## Made by Dimitri Wyzlic
## Login   <wyzlic_a@epitech.net>
##
## Started on  Thu Apr 21 15:01:37 2016 Dimitri Wyzlic
## Last update Fri Jul  8 21:43:26 2016 Dimitri Wyzlic
##

NAME	= mysh

SRC	= src/main.c \
	  lib/my_putchar.c \
	  lib/my_putstr.c \
	  lib/my_strlen.c \
	  lib/my_strstr.c \
	  lib/take_str.c \
	  lib/my_error.c \
	  lib/concastr.c \
	  lib/utils.c \
	  lib/utils_llist.c \
	  lib/my_put_nbr.c \
	  lib/get_next_line.c \
	  src/minishell.c \
	  src/startup_shell.c \
	  src/print_start.c \
	  src/get_env.c \
	  src/cmd.c \
	  src/cd.c \
	  src/exit_msg.c \
	  src/welcome.c \
	  src/utils_path.c \
	  src/parse_wave.c \
	  lib/str_to_tab.c

OBJ	= $(SRC:.c=.o)

CFLAGS = -g -W -Wall -Wextra -ansi -I inc

all	: $(NAME)

$(NAME)	: $(OBJ)
	cc $(OBJ) -o $(NAME)

clean	:
	rm -f $(OBJ)

fclean	: clean
	rm -f $(NAME)

re	: fclean all

check-syntax:
	gcc -W -Wall -o nul -I inc -S ${CHK_SOURCES}

.PHONY :	all clean fclean re

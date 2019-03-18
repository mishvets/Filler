# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mshvets <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/10/29 16:47:12 by mshvets           #+#    #+#              #
#    Updated: 2018/12/12 14:38:22 by mshvets          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= mshvets.filler
CC 			= gcc
CFLAGS 		= -Wall -Wextra -Werror
HEAD 		= includes/filler.h
LIB         = libft/libft.a

FILE    	+= srcs/main.c
FILE        += srcs/find_place_for_frag.c

BINARY		= $(FILE:.c=.o)

all: $(NAME)

$(NAME): $(BINARY)
	@make -C libft
	@$(CC) -o $(NAME) $(FLAG) $(BINARY) $(LIB)
	@echo "Filler player done"

clean:
	@make clean -C libft
	@rm -f $(BINARY)

fclean: clean
	@make fclean -C libft
	@rm -f $(NAME)

re: fclean all

reclean: fclean all
	@rm -f $(BINARY)

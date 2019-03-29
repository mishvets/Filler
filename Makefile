# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mshvets <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/03/29 17:09:01 by mshvets           #+#    #+#              #
#    Updated: 2019/03/29 17:09:03 by mshvets          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# name of the executable file

NAME		:= mshvets.filler

# project directories

SRC_DIR     = ./src/
OBJ_DIR     = ./obj/
INC_DIR     = ./inc/
LIB_DIR     = ./

# project source files

SRC             := $(SRC_DIR)main.c
SRC             += $(SRC_DIR)find_place_for_frag.c
SRC             += $(SRC_DIR)initialisation.c

# project object files

OBJ		        = $(SRC:$(SRC_DIR)%.c=$(OBJ_DIR)%.o)

# libraries

LIB             := $(LIBFT_DIR)libft.a
LIBFT_DIR       := $(LIB_DIR)libft/
LIBFT_INC       := $(LIBFT_DIR)
LIBFT_FLAGS     := -lft -L $(LIBFT_DIR)

# compilation flags

CC_FLAGS        := -Wall -Wextra -Werror

# linking flags

LINK_FLAGS      := $(LIBFT_FLAGS)

# header flags

HEAD            := $(INC_DIR)fillr.h
HEADER_FLAGS    := -I $(INC_DIR) -I $(LIBFT_INC)

# compiler

CC              := gcc

# rules

all: $(LIB) $(NAME)

$(NAME): $(OBJ)
	$(CC) $(OBJ) $(LINK_FLAGS) -o $(NAME)
	echo "Filler player done"

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	$(CC) $(CC_FLAGS) -c $< -o $@ $(HEADER_FLAGS)

$(LIB):
	make -C $(LIBFT_DIR)

clean:
	@rm -f $(OBJ)
	@make clean -C $(LIBFT_DIR)

fclean: clean
	@rm -f $(NAME)
	@make fclean -C $(LIBFT_DIR)

re: fclean all

reclean: fclean all
	@rm -f $(OBJ)

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

# name of the executable file

NAME		:= mshvets.filler

# project directories

SRC_DIR     = ./src/
OBJ_DIR     = ./
INC_DIR     = ./inc/
LIB_DIR     = ./

# project source files

SRC         := $(SRC_DIR)main.c
SRC         += $(SRC_DIR)find_place_for_frag.c

# project object files

OBJ		    = $(addprefix $(OBJ_DIR), $(SRC:.c=.o))

# libraries

LIBFT       = $(LIBFT_DIR)libft.a
LIBFT_DIR   := $(LIB_DIR)libft/
LIBFT_INC   := $(LIBFT_DIR)
LIBFT_FLAGS := -lft -L $(LIBFT_DIR)

# compilation flags

CC_FLAGS	:= -Wall -Wextra -Werror

# linking flags

LINK_FLAGS  :=   $(LIBFT_FLAGS)

# header flags

HEADER_FLAGS  := -I $(INC_DIR) -I $(LIBFT_INC)

# compiler

CC 			:= gcc

HEAD 		= includes/filler.h

# rules

all: $(NAME)

$(NAME): $(LIBFT) $(OBJ)
	@$(CC) $(OBJ) $(LINK_FLAGS) -o $(NAME)
	@echo "Filler player done"

$(OBJ_DIR)%.o: %.c
	@$(CC) -c $< -o $@ $(CC_FLAGS) $(HEADER_FLAGS)

$(LIBFT):
	@make -C $(LIBFT_DIR)

clean:
	@rm -f $(OBJ)
	@make clean -C $(LIBFT_DIR)

fclean: clean
	@rm -f $(NAME)
	@make fclean -C $(LIBFT_DIR)

re: fclean all

reclean: fclean all
	@rm -f $(OBJ)


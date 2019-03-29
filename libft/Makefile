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

NAME		= libft.a
CC 			= gcc
CFLAGS 		= -Wall -Wextra -Werror
HEAD 		= libft.h

FUNCTIONS	+= ft_atoi.c
FUNCTIONS	+= ft_bzero.c
FUNCTIONS	+= ft_isalnum.c
FUNCTIONS	+= ft_isalpha.c
FUNCTIONS	+= ft_isascii.c
FUNCTIONS	+= ft_isdigit.c
FUNCTIONS	+= ft_isprint.c
FUNCTIONS	+= ft_itoa.c
FUNCTIONS	+= ft_lstadd.c
FUNCTIONS	+= ft_lstdel.c
FUNCTIONS	+= ft_lstdelone.c
FUNCTIONS	+= ft_lstiter.c
FUNCTIONS	+= ft_lstmap.c
FUNCTIONS	+= ft_lstnew.c
FUNCTIONS	+= ft_memalloc.c
FUNCTIONS	+= ft_memccpy.c
FUNCTIONS	+= ft_memchr.c
FUNCTIONS	+= ft_memcmp.c
FUNCTIONS	+= ft_memcpy.c
FUNCTIONS	+= ft_memdel.c
FUNCTIONS	+= ft_memmove.c
FUNCTIONS	+= ft_memset.c
FUNCTIONS	+= ft_putchar_fd.c
FUNCTIONS	+= ft_putchar.c
FUNCTIONS	+= ft_putendl_fd.c
FUNCTIONS	+= ft_putendl.c
FUNCTIONS	+= ft_putnbr_fd.c
FUNCTIONS	+= ft_putnbr.c
FUNCTIONS	+= ft_putstr_fd.c
FUNCTIONS	+= ft_putstr.c
FUNCTIONS	+= ft_strcat.c
FUNCTIONS	+= ft_strchr.c
FUNCTIONS	+= ft_strclr.c
FUNCTIONS	+= ft_strcmp.c
FUNCTIONS	+= ft_strcpy.c
FUNCTIONS	+= ft_strdel.c
FUNCTIONS	+= ft_strdup.c
FUNCTIONS	+= ft_strequ.c
FUNCTIONS	+= ft_striter.c
FUNCTIONS	+= ft_striteri.c
FUNCTIONS	+= ft_strjoin.c
FUNCTIONS	+= ft_strlcat.c
FUNCTIONS	+= ft_strlen.c
FUNCTIONS	+= ft_strmap.c
FUNCTIONS	+= ft_strmapi.c
FUNCTIONS	+= ft_strncat.c
FUNCTIONS	+= ft_strncmp.c
FUNCTIONS	+= ft_strncpy.c
FUNCTIONS	+= ft_strnequ.c
FUNCTIONS	+= ft_strnew.c
FUNCTIONS	+= ft_strnstr.c
FUNCTIONS	+= ft_strrchr.c
FUNCTIONS	+= ft_strsplit.c
FUNCTIONS	+= ft_strstr.c
FUNCTIONS	+= ft_strsub.c
FUNCTIONS	+= ft_strtrim.c
FUNCTIONS	+= ft_tolower.c
FUNCTIONS	+= ft_toupper.c
FUNCTIONS   += ft_lstaddr.c
FUNCTIONS   += ft_isspace.c
FUNCTIONS	+= ft_cntwrd.c
FUNCTIONS	+= ft_srtwrd.c
FUNCTIONS	+= ft_numlen.c
FUNCTIONS	+= ft_pow.c
FUNCTIONS	+= ft_strupcase.c
FUNCTIONS	+= ft_strlowcase.c
FUNCTIONS	+= ft_itoa_base.c
FUNCTIONS	+= ft_sqrt.c
FUNCTIONS	+= get_next_line.c
FUNCTIONS	+= ft_printf.c
FUNCTIONS	+= ft_strjoinl.c
FUNCTIONS	+= ft_numinstr.c
FUNCTIONS	+= ft_uitoa_base.c
FUNCTIONS	+= ft_ftoa.c
FUNCTIONS	+= printf_specificator.c
FUNCTIONS	+= printf_specificator2.c
FUNCTIONS	+= printf_pointer.c
FUNCTIONS	+= printf_str.c
FUNCTIONS	+= printf_int.c
FUNCTIONS	+= printf_float_double.c
FUNCTIONS	+= printf_oux.c
FUNCTIONS	+= ft_check_sign_double.c
FUNCTIONS	+= ft_doublstrdel.c

BINARY		= $(FUNCTIONS:.c=.o)

all: $(NAME)

$(NAME): $(BINARY)
	@ar rc $(NAME) $(BINARY)
	@ranlib $(NAME)
	@rm -f libft.h.gch

$(BINARY): $(FUNCTIONS)
	@$(CC) -c $(CFLAGS) $(FUNCTIONS) -I. $(HEAD)

clean:
	@rm -f $(BINARY)

fclean: clean
	@rm -f $(NAME)

re: fclean all

reclean: fclean all
	@rm -f $(BINARY)

# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: proso <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/03/08 13:37:08 by proso             #+#    #+#              #
#    Updated: 2017/03/30 11:59:11 by proso            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =  libftprintf.a

SRC = add_attribute.c \
	  add_prefixe.c \
	  add_prefixe_s.c \
	  add_spec_prefixe.c \
	  change_style.c \
	  check_style.c \
	  convert_fb.c \
	  convert_lslc.c \
	  convert_douxsc.c \
	  flag_overflow.c \
	  ft_printf.c \
	  get_etoile.c \
	  get_modifier.c \
	  identify_percent.c \
	  unicode.c

CC = gcc

FLAGS = -Wall -Werror -Wextra

INCLUDE = Include/ft_printf.h

LIBFT_A = Libft/libft.a

OBJ = $(SRC:.c=.o)

all: $(NAME)

make_libft: 
	make -C Libft/

%.o:%.c
	$(CC) $(FLAGS) -o $@ -c $<

$(NAME): make_libft $(OBJ)
	cp $(LIBFT_A) $(NAME)
	ar rcs $(NAME) $(OBJ)

clean:
	@rm -rf $(OBJ)
	make clean -C Libft/

fclean: clean
	@rm -rf $(NAME)
	make fclean -C Libft/

re: fclean all

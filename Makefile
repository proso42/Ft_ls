# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: proso <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/03/30 11:47:45 by proso             #+#    #+#              #
#    Updated: 2017/03/31 17:12:12 by proso            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_ls

SRC = Sources/choice_print.c \
	  Sources/find_option.c \
	  Sources/fill_list_l.c \
	  Sources/ft_dup_list.c \
	  Sources/ft_print_arg.c \
	  Sources/ft_print_list.c \
	  Sources/ft_print_list_1.c \
	  Sources/ft_print_list_l.c \
	  Sources/ft_print_list_m.c \
	  Sources/ft_push_back.c \
	  Sources/ft_remove_list.c \
	  Sources/ft_remove_struct.c \
	  Sources/ft_reverse_list.c \
	  Sources/get_acl.c \
	  Sources/get_elem.c \
	  Sources/get_list_arg.c \
	  Sources/get_list_info.c \
	  Sources/get_p_elem.c \
	  Sources/get_perm.c \
	  Sources/get_width_win.c \
	  Sources/main.c \
	  Sources/sort_by_ascii.c \
	  Sources/sort_by_size.c \
	  Sources/sort_by_time.c \
	  Sources/sort_in_col.c

CC = gcc

CFLAGS = -Wall -Werror -Wextra

LIBFT = Libftprintf/Libft/libft.a

LIBFT_PRINTF = Libftprintf/libftprintf.a

OBJ = $(SRC:.c=.o)

all: $(NAME)

make_lib:
	make -C Libftprintf/

%.o:%.c
	$(CC) $(FLAGS) -I./$(LIBFT_PRINTF ) -o $@ -c $<

$(NAME): make_lib $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(LIBFT_PRINTF)

clean:
	@rm -rf $(OBJ)
	make clean -C Libftprintf/

fclean: clean
	@rm -rf $(NAME)
	make fclean -C Libftprintf/

re: fclean all

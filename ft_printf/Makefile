# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: awhana <awhana@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/04/27 10:31:02 by awhana            #+#    #+#              #
#    Updated: 2021/04/29 16:27:35 by awhana           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LIBFT	= ./libft/libft.a

NAME	= libftprintf.a

SRCS	= ft_printf.c \
		ft_putcharstr.c \
		set_flags.c \
		write_int.c \
		write_width.c \
		write_char.c \
		cmp_and_init_flags.c \
		write_string.c \
		write_pointer.c \
		write_unsigned_int.c \
		write_hex.c \
		write_percent.c

CC = gcc

FLAGS = -c -Wall -Werror -Wextra

OBJS = $(SRCS:.c=.o)

%.o: %.c ft_printf.h
	$(CC) $(FLAGS) -c $< -o $@
	
$(NAME):	$(OBJS)
	$(MAKE) -C ./libft
	cp libft/libft.a $(NAME)
	$(CC) $(FLAGS) ft_printf.h $(SRCS)
	ar -rcs $(NAME) $(OBJS)

all:	$(NAME)

clean:
	$(MAKE) clean -C ./libft
	rm -rf $(OBJS)

fclean: clean
	$(MAKE) fclean -C ./libft
	rm -rf $(NAME)

re: fclean all
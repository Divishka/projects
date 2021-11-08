# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: awhana <awhana@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/04/29 15:54:33 by awhana            #+#    #+#              #
#    Updated: 2021/05/19 11:17:54 by awhana           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= miniRT
LIBMLX	= ../minilibx/libmlx.dylib
LIBFT	= ../libft/libft.a
FLAGS	= -Wall -Werror -Wextra
OBJS	= $(SRCS:.c=.o)
FLAGX	= -lmlx -framework OpenGL -framework AppKit
SRCS	= miniRT.c get_next_line.c free_me_please.c \
		objects_manipulate.c screenshot.c \
		parse_utils.c parsing.c parsing2.c events.c action.c \
		formuls.c formuls2.c ray_tracing.c parsing3.c calculation.c calculation2.c calculation3.c \
		parse_utils2.c parsing4.c parsing5.c parsing6.c parsing7.c parsing8.c parsing9.c \
		rendering.c calculation4.c calculation5.c calculation6.c

$(NAME):	${OBJS} ../libft/libft.a ../minilibx/libmlx.dylib miniRT.h
	cp ../minilibx/libmlx.dylib .
	cp ../libft/libft.a .
	gcc -g ${FLAGS} ${FLAGX} ${LIBMLX} ${LIBFT} ${SRCS} -o ${NAME}

all:	make_libs $(NAME)

make_libs:
	MAKE -C ../libft
	MAKE -C ../minilibx

../libft/libft.a:
	MAKE -C ../libft

../minilibx/libmlx.dylib:
	MAKE -C ../minilibx

clean:
	rm -f ${OBJS}
	MAKE clean -C ../libft

fclean:		clean
	rm -f ${NAME}
	rm -f ${LIBMLX}
	rm -f ${LIBFT}
	MAKE fclean -C ../libft

re: fclean all

# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: awhana <awhana@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/04/16 05:45:50 by awhana            #+#    #+#              #
#    Updated: 2021/05/04 10:12:56 by awhana           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	libft.a

LIST		=	ft_substr.c ft_strjoin.c ft_strtrim.c \
				ft_split.c ft_itoa.c ft_strmapi.c ft_putchar_fd.c ft_putstr_fd.c \
				ft_putendl_fd.c ft_putnbr_fd.c ft_memset.c ft_bzero.c ft_memcpy.c ft_memccpy.c \
				ft_memmove.c ft_memchr.c ft_memcmp.c ft_strlen.c ft_strlcpy.c ft_strlcat.c ft_strchr.c \
				ft_strrchr.c ft_strnstr.c ft_strncmp.c ft_atoi.c ft_isalpha.c ft_isdigit.c ft_isalnum.c \
				ft_isascii.c ft_isprint.c ft_toupper.c ft_tolower.c ft_calloc.c ft_strdup.c ft_strdel.c \
				ft_strequ.c ft_atof.c ft_ccount.c \
				ft_lstadd_back.c ft_lstnew.c ft_lstadd_front.c \
				ft_lstsize.c ft_lstlast.c ft_lstdelone.c \
				ft_lstclear.c ft_lstiter.c ft_lstmap.c 

OBJ			=	$(patsubst %.c,%.o,$(LIST))
OBJ_B		=	$(patsubst %.c,%.o,$(LIST_B))

OPTFLAGS	=	-O2
CFLAGS		=	-Wall -Wextra -Werror

all : $(NAME)

$(NAME) : $(OBJ) libft.h
	ar rcs $(NAME) $?

%.o : %.c
	gcc $(CFLAGS) $(OPTFLAGS) -c $< -o $@

clean :
	@rm -f $(OBJ) $(OBJ_B)

fclean : clean
	@rm -f $(NAME)

re : fclean all

.PHONY : all clean fclean re bonus

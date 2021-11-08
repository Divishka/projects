NAME	=	push_swap
NAME_CH =	checker
LIBFT	= 	libft.a
CC		=	gcc
CFLAGS	=	-Wall -Wextra -Werror
RM		=	rm -f

SRC		=	libft.a push_swap.c big_sorting.c main.c\
			utilities.c temporary.c error.c operations.c\
			operations2.c find_step.c validation.c operations3.c

HEADER	=	push_swap.h libft/libft.h

all		:	$(LIBFT) $(NAME)

$(NAME)	: $(SRC) $(HEADER)
	$(CC) $(CFLAGS) -I. $(SRC) -o $(NAME)

$(LIBFT):
	@$(MAKE) -C libft
	@mv libft/libft.a ./

clean	:
	@$(RM) libft/*.o

fclean	:	clean
	@$(RM) libft.a $(NAME) $(NAME_CH) 

re		:	fclean all

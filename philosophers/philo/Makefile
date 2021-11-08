NAME = philo

CFLAGS = -Wall -Wextra -Werror

SRCS	= 	philo.c \
			logic.c \
			read_data.c \
			utils.c \
			valid_check.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	gcc $(CFLAGS) $(SRCS) -o $(NAME)

$(OBJS) : %.o : %.c philo.h

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all
NAME 			= Brainz
SRCS			= main.cpp newZombie.cpp randomChump.cpp Zombie.cpp
OBJS			= main.o newZombie.o randomChump.o Zombie.o
CPPFLAGS		= -Wall -Wextra -Werror -I. -std=c++98
RM				= rm -f

all: $(NAME)

$(NAME):		$(OBJS)
	clang++ -o $(NAME) $(CPPFLAGS) $(OBJS)
	make clean

%.o : %.cpp
	clang++ $(CPPFLAGS) -c $(SRCS)

clean:
	$(RM) $(OBJS)

fclean:			clean
	$(RM) $(NAME)

re:	fclean $(NAME)

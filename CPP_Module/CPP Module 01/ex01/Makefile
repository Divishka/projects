NAME 			= Moar_Brainz
SRCS			= main.cpp  Zombie.cpp zombieHorde.cpp
OBJS			= main.o  Zombie.o zombieHorde.o
CPPFLAGS		= -Wall -Wextra -Werror -I. -std=c++98
RM				= rm -f

all: $(NAME)

$(NAME):		$(OBJS)
	clang++ $(CPPFLAGS) -o $(NAME) $(OBJS)
	make clean

%.o : %.cpp
	clang++ $(CPPFLAGS) -c $(SRCS)

clean:
	$(RM) $(OBJS)

fclean:			clean
	$(RM) $(NAME)

re:	fclean $(NAME)

NAME 			= Unnecessary_violence
SRCS			= main.cpp HumanA.cpp HumanB.cpp Weapon.cpp
OBJS			= main.o HumanA.o HumanB.o Weapon.o
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

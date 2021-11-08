NAME 			= fighting
SRCS			= main.cpp ClapTrap.cpp ScavTrap.cpp FragTrap.cpp DiamondTrap.cpp
OBJS			= $(SRCS:.cpp=.o)
CPPFLAGS		= -Wall -Wextra -Werror -std=c++98 -I. -Wshadow -Wno-shadow
RM				= rm -f

all: $(NAME)

$(NAME):		$(OBJS)
	clang++ $(CPPFLAGS) -o $(NAME) $(OBJS)

%.o : %.cpp
	clang++ $(CPPFLAGS) -c $(SRCS)

clean:
	$(RM) $(OBJS)

fclean:			clean
	$(RM) $(NAME)

re:	fclean $(NAME)
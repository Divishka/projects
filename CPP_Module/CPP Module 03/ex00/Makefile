NAME 			= fighting
SRCS			= main.cpp ClapTrap.cpp
OBJS			= $(SRCS:.cpp=.o)
CPPFLAGS		= -Wall -Wextra -Werror -std=c++98 -I.
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
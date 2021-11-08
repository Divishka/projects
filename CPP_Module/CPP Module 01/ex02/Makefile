NAME 			= HI_THIS_IS_BRAIN
SRCS			= main.cpp
OBJS			= main.o
CPPFLAGS		= -Wall -Wextra -Werror -std=c++98
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

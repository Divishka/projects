NAME 			= powertest
SRCS			= Account.cpp tests.cpp
OBJS			= $(SRCS:.cpp=.o)
CPPFLAGS		= -I. -Wall -Wextra -Werror 
RM				= rm -f

all: $(NAME)

$(NAME):		$(OBJS)
	clang++ $(CPPFLAGS) -o $(NAME) $(OBJS) -std=c++98

clean:
	$(RM) $(OBJS)

fclean:			clean
	$(RM) $(NAME)

re:	fclean $(NAME)
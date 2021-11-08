NAME 			= megaphone
SRCS			= megaphone.cpp
OBJS			= $(SRCS:.cpp=.o)
CPPFLAGS		= -Wall -Wextra -Werror -I.
RM				= rm -f

all: $(NAME)

$(NAME):		$(OBJS)
	clang++ $(CPPFLAGS) -o $(NAME) $(OBJS) -std=c++98

clean:
	$(RM) $(OBJS)

fclean:			clean
	$(RM) $(NAME)

re:	fclean $(NAME)

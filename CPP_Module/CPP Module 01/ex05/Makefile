NAME 			= Karen_2_0
SRCS			= main.cpp Karen.cpp
OBJS			= main.o Karen.o
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

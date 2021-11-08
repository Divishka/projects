NAME 			= my_awesome_phonebook
SRCS			= Contact.cpp adress_book.cpp Phone_book.cpp
OBJS			= $(SRCS:.cpp=.o)
CPPFLAGS		=  -Wall -Wextra -Werror -I.
RM				= rm -f

all: $(NAME)

$(NAME):		$(OBJS)
	clang++ $(CPPFLAGS) -o $(NAME) $(OBJS) -std=c++98

clean:
	$(RM) $(OBJS)

fclean:			clean
	$(RM) $(NAME)

re:	fclean $(NAME)
NAME = test

SRCS = ./test.cpp

CXXFLAGS = -g

re:			fclean all

all:	$(NAME)

$(NAME):
			c++ $(CXXFLAGS) -std=c++17 $(SRCS) -g -o test

fclean:
			rm -rf $(NAME)

.PHONEY: clean fclean re all
NAME = test

SRCS = ./test.cpp ./fixedPoint.cpp

CXXFLAGS = -g

re:			fclean all

all:	$(NAME)

$(NAME):
			c++ $(CXXFLAGS) -std=c++17 $(SRCS) -o test

fclean:
			rm -rf $(NAME)

.PHONEY: clean fclean re all
NAME = test

SRCS = ./test.cpp

re:			fclean all

all:	$(NAME)

$(NAME):
			g++ -std=c++14 -Wall test.cpp -o test

fclean:
			rm -rf $(NAME)

.PHONEY: clean fclean re all
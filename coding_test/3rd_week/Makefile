NAME = test

SRCS = ./test.cpp

re:			fclean all

all:	$(NAME)

$(NAME):
			g++ -std=c++17 test.cpp -o test

fclean:
			erase $(NAME).exe

.PHONEY: clean fclean re all
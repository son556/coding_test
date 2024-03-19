NAME = test

SRCS = ./test.cpp

re:			fclean all

all:	$(NAME)

$(NAME):
			c++ -std=c++17 $(SRCS) -g -o test

fclean:
			erase $(NAME).exe

.PHONEY: clean fclean re all
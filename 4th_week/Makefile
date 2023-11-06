NAME = test

SRCS = ./test.cpp

re:			fclean all

all:	$(NAME)

$(NAME):
			g++ -std=c++17 $(SRCS) -o test

fclean:
			rm -rf $(NAME)

.PHONEY: clean fclean re all
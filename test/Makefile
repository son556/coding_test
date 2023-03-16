NAME = test

CC = gcc

LDFLAGS = -L/Users/chanson/.brew/opt/readline/lib -lreadline -lncurses

CPPFLAGS = -I/Users/chanson/.brew/opt/readline/include

SRCS =  ./test.c

OBJS = $(SRCS:.c=.o)

SRCS2 = ./test2.c

OBJS_BONUS = $(SRCS2:.c=.o)

ifdef BONUS
	OBJS_ALL = $(OBJS_BONUS)
else
	OBJS_ALL = $(OBJS)
endif

all : $(NAME)

$(NAME) : $(OBJS_ALL)
	$(CC) $(LDFLAGS) $(CPPFLAGS) $(OBJS_ALL) -o $(NAME) 

%.o: %.c
	$(CC) $(COMFILE_FLAGS) -c $< -o $@

bonus:
		make BONUS=1 all

clean :
	rm -rf $(OBJS)
	rm -rf $(OBJS_BONUS)

fclean : clean
	rm -rf $(NAME)

re : fclean all

.PHONY : all clean fclean re bonus
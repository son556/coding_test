NAME = microshell

SRCS_NAME = ./microshell \
			./display \

SRCS_BONUS_NAME = ./microshell2

SRCS = $(addsuffix .c, $(SRCS_NAME))

SRCS_BONUS = $(addsuffix .c, $(SRCS_BONUS_NAME))

OBJS = $(addsuffix .o, $(SRCS_NAME))

OBJS_BONUS = $(addsuffix .o, $(SRCS_BONUS_NAME))

CC		=	cc

ifdef BONUS
	OBJS_ALL = $(OBJS_BONUS)
else
	OBJS_ALL = $(OBJS)
endif

all:	$(NAME)

$(NAME):	$(OBJS_ALL)
			$(CC) $(OBJS_ALL) -o $(NAME)

%.o : %.c
			$(CC) $(CFLAGS) -c $< -o $@

clean:
			rm -rf $(NAME)
			rm -rf $(OBJS) $(OBJS_BONUS)

fclean:		clean

re:			fclean all

bonus:
	make BONUS=1 all

.PHONY:		all clean fclean re bonus
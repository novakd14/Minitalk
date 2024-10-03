CC = cc
CFLAGS = -Wall -Wextra -Werror -g -D ERROR_MESSAGES
CLIB_DIR = ../push_swap/libft
CLIB = ft

SRCS_DIR = ../push_swap/
TEST_DIR = ../unity_test/

NAME = test.out
SRCS = input.c clean.c rules.c sort.c adv_bubble_sort.c
HEAD = test_push_swap.h
UNIT = unity.c
TEST = test_push_swap.c redef.c
SRCS := $(addprefix $(SRCS_DIR), $(SRCS))
OBJS = $(UNIT:.c=.o) $(TEST:.c=.o) $(SRCS:.c=.o)

.PHONY: all clean fclean bclean re test ftest memleak cpybonus

all: test

$(NAME): $(OBJS)
	make -C $(CLIB_DIR) bonus
	$(CC) -o $(NAME) $(OBJS) -L$(CLIB_DIR) -l$(CLIB)

clean:
	rm -f *.o

fclean: clean
	rm -f $(SRCS:.c=.o)
	rm -f *.exe

bclean:
	rm -f $(wildcard $(SRCS_DIR)*_bonus.*)

re: fclean all

test: $(NAME)
	clear
	-./$(NAME)

ftest: test
	make fclean

norm:
	norminette $(SRCS_DIR)

memleak: $(NAME)
	valgrind -s --leak-check=full --show-leak-kinds=all ./$(NAME)

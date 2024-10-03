CC = cc
CFLAGS = -Wall -Wextra -Werror
TEST_CFLAGS = -g
CLIB_DIR = libft
CLIB = ft

NAME_CLIENT = client
NAME_SERVER = server
SRCS_CLIENT = main_client.c
SRCS_SERVER = main_server.c
HEAD_CLIENT = client.h
HEAD_SERVER = server.h
OBJS_CLIENT = $(SRCS_CLIENT:.c=.o)
OBJS_SERVER = $(SRCS_SERVER:.c=.o)

.PHONY: all clean fclean re test norm memleak

all: $(NAME)

$(NAME_CLIENT): $(OBJS_CLIENT)
	make -C $(CLIB_DIR) bonus
	$(CC) -o $@ $^ -L$(CLIB_DIR) -l$(CLIB)

$(NAME_SERVER): $(OBJS_SERVER)
	make -C $(CLIB_DIR) bonus
	$(CC) -o $@ $^ -L$(CLIB_DIR) -l$(CLIB)

clean:
	rm -f *.o

fclean: clean
	rm -f $(NAME)

re: fclean all

test: $(NAME)
	clear
	-./$(NAME)

norm:
	norminette

# memleak: $(NAME)
# 	valgrind -s --leak-check=full --show-leak-kinds=all ./$(TEST_NAME)

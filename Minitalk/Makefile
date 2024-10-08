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

MESSAGE1 = "Lorem ipsum dolor sit amet, consectetuer adipiscing elit. Aenean commodo ligula eget dolor."
MESSAGE2 = "Lorem ipsum dolor sit amet, consectetuer adipiscing elit. Aenean commodo ligula eget dolor. Aenean massa. Cum sociis natoque penatibus et magnis dis parturient montes, nascetur ridiculus mus."
MESSAGE3 = "Lorem ipsum dolor sit amet, consectetuer adipiscing elit. Aenean commodo ligula eget dolor. Aenean massa. Cum sociis natoque penatibus et magnis dis parturient montes, nascetur ridiculus mus. Donec quam felis, ultricies nec, pellentesque eu, pretium quis, sem. Nulla consequat massa quis enim. Donec pede justo, fringilla vel, aliquet nec, vulputate eget, arcu. In enim justo, rhoncus ut, imperdiet a, venenatis vitae, justo. Nullam dictum felis eu pede mollis pretium. Integer tincidunt."

.PHONY: all clean fclean re test norm memleak

all: $(NAME_CLIENT) $(NAME_SERVER)

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

run_client: $(NAME_CLIENT)
	-./$< $(PID) $(MESSAGE)
	-./$< $(PID) $(MESSAGE1)
	-./$< $(PID) $(MESSAGE2)
	-./$< $(PID) $(MESSAGE3)

run_server: $(NAME_SERVER)
	-./$<

norm:
	norminette

# memleak: $(NAME)
# 	valgrind -s --leak-check=full --show-leak-kinds=all ./$(TEST_NAME)

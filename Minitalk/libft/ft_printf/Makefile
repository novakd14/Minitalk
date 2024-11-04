CC = cc
CFLAGS = -Wall -Wextra -Werror


NAME = libftprintf.a
SRCS = ft_printf.c ft_set_flags.c ft_save_char.c ft_save_str.c ft_save_ptr.c \
	ft_save_int.c ft_save_uint.c ft_save_hexa_small.c ft_save_hexa_big.c ft_save_pct.c \
	ft_save_flags.c ft_cpyextra.c ft_put_arg.c
LIB_DIR = libft/
LIB_SRCS = ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c \
	ft_isascii.c ft_isdigit.c ft_isprint.c ft_itoa.c ft_memchr.c \
	ft_memcmp.c ft_memcpy.c ft_memmove.c ft_memset.c ft_putchar_fd.c \
	ft_putendl_fd.c ft_putnbr_fd.c ft_putstr_fd.c ft_split.c ft_strchr.c \
	ft_strdup.c ft_striteri.c ft_strjoin.c ft_strlcat.c ft_strlcpy.c \
	ft_strlen.c ft_strmapi.c ft_strncmp.c ft_strnstr.c ft_strrchr.c \
	ft_strtrim.c ft_substr.c ft_tolower.c ft_toupper.c
LIB_SRCS := $(addprefix $(LIB_DIR), $(LIB_SRCS))
BONS =
HEAD = libftprintf.h ft_printf.h
OBJS = $(SRCS:.c=.o)
LIB_OBJS = $(LIB_SRCS:.c=.o)
O_BONS = $(BONS:.c=.o)

.PHONY: all clean fclean re bonus norm

all: $(NAME)

$(NAME): $(OBJS) $(LIB_OBJS) $(HEAD)
	ar -crs $(NAME) $(OBJS) $(LIB_OBJS)

clean:
	rm -f *.o $(LIB_OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

bonus: $(OBJS) $(LIB_OBJS) $(HEAD) $(O_BONS)
	ar -crs $(NAME) $(OBJS) $(LIB_OBJS) $(O_BONS)

norm: all fclean
	norminette $(SRCS) $(LIB_SRCS) $(BONS) $(HEAD)


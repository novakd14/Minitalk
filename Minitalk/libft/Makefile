CC = cc
CFLAGS = -Wall -Wextra -Werror

NAME = libft.a
SRCS = ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c \
	ft_isascii.c ft_isdigit.c ft_isprint.c ft_itoa.c ft_memchr.c \
	ft_memcmp.c ft_memcpy.c ft_memmove.c ft_memset.c ft_putchar_fd.c \
	ft_putendl_fd.c ft_putnbr_fd.c ft_putstr_fd.c ft_split.c ft_strchr.c \
	ft_strdup.c ft_striteri.c ft_strjoin.c ft_strlcat.c ft_strlcpy.c \
	ft_strlen.c ft_strmapi.c ft_strncmp.c ft_strnstr.c ft_strrchr.c \
	ft_strtrim.c ft_substr.c ft_tolower.c ft_toupper.c
BONS = ft_lstadd_back_bonus.c ft_lstadd_front_bonus.c ft_lstclear_bonus.c ft_lstdelone_bonus.c ft_lstiter_bonus.c \
	ft_lstlast_bonus.c ft_lstmap_bonus.c ft_lstnew_bonus.c ft_lstsize_bonus.c
PRINTF_DIR = ft_printf/
PRINTF_SRCS = ft_printf.c ft_set_flags.c ft_save_char.c ft_save_str.c ft_save_ptr.c \
	ft_save_int.c ft_save_uint.c ft_save_hexa_small.c ft_save_hexa_big.c ft_save_pct.c \
	ft_save_flags.c ft_cpyextra.c ft_put_arg.c
PRINTF_SRCS := $(addprefix $(PRINTF_DIR), $(PRINTF_SRCS))
HEAD = libft.h
PRINTF_HEAD = ft_printf.h libftprintf.h
PRINTF_HEAD := $(addprefix $(PRINTF_DIR), $(PRINTF_HEAD))
OBJS = $(SRCS:.c=.o)
O_BONS = $(BONS:.c=.o)
PRINTF_OBJS = $(PRINTF_SRCS:.c=.o)

.PHONY: all clean fclean re bonus norm

all: $(NAME)

$(NAME): $(OBJS) $(HEAD)
	ar -crs $(NAME) $(OBJS)

clean:
	rm -f *.o

fclean: clean
	rm -f $(NAME)

re: fclean all

bonus: $(OBJS) $(O_BONS) $(PRINTF_OBJS) $(HEAD) $(PRINTF_HEAD)
	ar -crs $(NAME) $(OBJS) $(O_BONS) $(PRINTF_OBJS)

norm: all fclean
	norminette $(SRCS) $(BONS) $(PRINTF_SRCS) $(HEAD) $(PRINTF_HEAD)


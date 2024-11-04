CC = cc
CFLAGS = -Wall -Wextra -Werror

NAME = libft.a
SRCS = ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c \
	ft_isascii.c ft_isdigit.c ft_isprint.c ft_itoa.c ft_memchr.c \
	ft_memcmp.c ft_memcpy.c ft_memmove.c ft_memset.c ft_putchar_fd.c \
	ft_putendl_fd.c ft_putnbr_fd.c ft_putstr_fd.c ft_split.c ft_strchr.c \
	ft_strdup.c ft_striteri.c ft_strjoin.c ft_strlcat.c ft_strlcpy.c \
	ft_strlen.c ft_strmapi.c ft_strncmp.c ft_strnstr.c ft_strrchr.c \
	ft_strtrim.c ft_substr.c ft_tolower.c ft_toupper.c ft_isspace.c \
	ft_isupper.c ft_islower.c ft_strtol.c
LIST_SRCS = ft_lstadd_back.c ft_lstadd_front.c ft_lstclear.c ft_lstdelone.c ft_lstiter.c \
	ft_lstlast.c ft_lstmap.c ft_lstnew.c ft_lstsize.c
UTILS_SRCS = ft_utils.c
PRINTF_DIR = ft_printf/
PRINTF_SRCS = ft_printf.c ft_set_flags.c ft_save_char.c ft_save_str.c ft_save_ptr.c \
	ft_save_int.c ft_save_uint.c ft_save_hexa_small.c ft_save_hexa_big.c ft_save_pct.c \
	ft_save_flags.c ft_cpyextra.c ft_put_arg.c
GNL_DIR = get_next_line/
GNL_SRCS = get_next_line.c get_next_line_utils.c
HEAD = libft.h
PRINTF_HEAD = ft_printf.h
GNL_HEAD = get_next_line.h

PRINTF_SRCS := $(addprefix $(PRINTF_DIR), $(PRINTF_SRCS))
PRINTF_HEAD := $(addprefix $(PRINTF_DIR), $(PRINTF_HEAD))
GNL_SRCS := $(addprefix $(GNL_DIR), $(GNL_SRCS))
GNL_HEAD := $(addprefix $(GNL_DIR), $(GNL_HEAD))
SRCS := $(SRCS) $(LIST_SRCS) $(UTILS_SRCS) $(PRINTF_SRCS) $(GNL_SRCS)
HEADS = $(HEAD) $(PRINTF_HEAD) $(GNL_HEAD)
OBJS = $(SRCS:.c=.o)

.PHONY: all clean fclean re norm

all: $(NAME)

$(NAME): $(OBJS) $(HEADS)
	ar -crs $@ $^

clean:
	find . -name '*.o' -type f -delete

fclean: clean
	find . -name '*.a' -type f -delete

re: fclean all

norm: all fclean
	norminette $(SRCS) $(HEADS)


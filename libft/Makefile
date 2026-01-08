NAME = libft.a

CC = cc
CFLAGS = -Wall -Werror -Wextra

INC = libft.h
SRCS = ft_bzero.c \
		ft_printf.c \
		ft_strcmp.c \
		ft_strstr.c \
		printf_utils.c \
		printf_utils2.c
OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $@ $^

%.o: %.c $(INC)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
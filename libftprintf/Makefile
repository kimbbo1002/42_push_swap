NAME = libftprintf.a
CC = cc
CFLAGS = -Wall -Wextra -Werror 
SOURCES = ft_printf.c print_char.c print_pointer.c print_signed.c print_string.c print_unsigned.c print_hex.c
OBJECTS = $(SOURCES:.c=.o)

all: $(NAME)
$(NAME) : $(OBJECTS)
	ar rcs $(NAME) $(OBJECTS)
%.o: %.c ft_printf.h
	$(CC) $(CFLAGS) -c $< -o $@
clean:
	rm -f $(OBJECTS)
fclean: clean
	rm -f $(NAME)
re : fclean all
PHONY: all clean fclean re

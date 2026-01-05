NAME = push_swap
CHECKER_NAME = checker
CC = cc
CFLAGS = -Wall -Wextra -Werror -g
PRINTF_PATH = ./libftprintf
PRINTF_INC  = -I $(PRINTF_PATH)
SOURCES = utils.c simple_algo.c parsing_arg.c operations3.c operations2.c operations.c complex_algo.c medium_algo.c main.c get_next_line.c get_next_line_utils.c exec_op3.c exec_op2.c exec_op.c dispatch_operations.c disorder.c checker.c bench_mode.c libftprintf/printf_utils2.c libftprintf/printf_utils.c libftprintf/ft_strcmp.c libftprintf/ft_printf.c libftprintf/ft_bzero.c libftprintf/ft_strstr.c
OBJECTS = $(SOURCES:.c=.o)
all: $(NAME)
$(NAME) : $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) -o $(NAME)
%.o: %.c push_swap.h
	$(CC) $(CFLAGS) $(PRINTF_INC) -c $< -o $@
bonus: $(NAME)
	cp $(NAME) $(CHECKER_NAME)
clean:
	rm -f $(OBJECTS)
fclean: clean
	rm -f $(NAME) $(CHECKER_NAME)
re : fclean all
PHONY: all clean fclean re bonus
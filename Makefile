NAME = push_swap
BONUS_NAME = checker

LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a
INC = -Iincls -I$(LIBFT_DIR)
HDRS = incls/push_swap.h \
		incls/push_swap_bonus.h

CC = cc
CFLAGS = -Wall -Wextra -Werror $(INC)

SRCS_DIR = srcs/
SRCS_FILES = bench_mode.c \
			complex_algo.c \
			disorder.c \
			dispatch_operations.c \
			exec_op.c \
			exec_op2.c \
			exec_op3.c \
			free_stack.c \
			main.c \
			medium_algo.c \
			operations.c \
			operations2.c \
			operations3.c \
			parsing_arg.c \
			simple_algo.c \
			utils.c
SRCS = $(addprefix $(SRCS_DIR), $(SRCS_FILES))
OBJS = $(SRCS:.c=.o)

BONUS_DIR = bonus/
BONUS_FILES = checker_bonus.c \
			get_next_line_bonus.c \
			get_next_line_utils_bonus.c \
			main_bonus.c \
			operations_bonus.c \
			operations2_bonus.c \
			operations3_bonus.c \
			parsing_bonus.c \
			utils_bonus.c
BONUS_SRCS = $(addprefix $(BONUS_DIR), $(BONUS_FILES))
BONUS_OBJS = $(BONUS_SRCS:.c=.o)

all: $(NAME)

$(NAME) : $(LIBFT) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)

bonus: $(LIBFT) $(BONUS_OBJS)
	$(CC) $(CFLAGS) $(BONUS_OBJS) $(LIBFT) -o $(BONUS_NAME)

$(LIBFT):
	@make -C $(LIBFT_DIR)

%.o: %.c $(HDRS)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	@make clean -C $(LIBFT_DIR)
	rm -f $(OBJS) $(BONUS_OBJS)

fclean: clean
	@make fclean -C $(LIBFT_DIR)
	rm -f $(NAME) $(BONUS_NAME)

re : fclean all

.PHONY: all bonus clean fclean re
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayhammou <ayhammou@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 15:00:53 by ayhammou          #+#    #+#             */
/*   Updated: 2025/12/19 16:02:34 by ayhammou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

//headers
# include <unistd.h>
# include <stdlib.h>
# include <unistd.h>
# include <stddef.h>
# include <stdbool.h>
# include <limits.h>
# include "libftprintf/libftprintf.h"

//structs
typedef struct t_stack
{
	int				value;
	int				index;
	struct t_stack	*next;
}	t_stack;

typedef struct operation
{
	int	pa;
	int	pb;
	int	sa;
	int	sb;
	int	ss;
	int	ra;
	int	rb;
	int	rr;
	int	rra;
	int	rrb;
	int	rrr;
	int	total;
}	t_operation;

typedef struct s_data
{
	t_stack		*a;
	t_stack		*b;
	t_operation	operation;
	int			strategy;
	bool		bench_mode;
	bool		checker;
	int			disorder;
}	t_data;

//operations.c
void	sa(t_data *data);
void	sb(t_data *data);
void	ss(t_data *data);
void	pa(t_data *data);
void	pb(t_data *data);

void	ra(t_data *data);
void	rb(t_data *data);
void	rr(t_data *data);

void	rra(t_data *data);
void	rrb(t_data *data);
void	rrr(t_data *data);

//exec_op.c    
void	exec_sa(t_data *data);
void	exec_sb(t_data *data);
void	exec_ss(t_data *data);
void	exec_pa(t_data *data);
void	exec_pb(t_data *data);

void	exec_ra(t_data *data);
void	exec_rb(t_data *data);
void	exec_rr(t_data *data);

void	exec_rra(t_data *data);
void	exec_rrb(t_data *data);
void	exec_rrr(t_data *data);

//algo
void	simple_sort(t_data *data);
void	medium_sort(t_data *data, int range);
void	complex_algo(t_data *data);

//parse/disorder/dispatch/bench
int		parsing_arg(char *stack, t_stack **digit_stack);
int		calc_disorder(t_stack *a);
void	dispatch_op(t_data *data);
void	bench_mode(t_data *data);

//utils.c
void	init_data(t_data *data);
int		duplicate(t_stack *stack, int num);
t_stack	*store(int content);
void	add_stack(t_stack **numbers, t_stack *store);
int		stack_size(t_stack *stack);
void	free_stack(t_data *data);
int		is_sorted(t_data *data);
void	index_value(t_stack *a);
int		max_idx(t_stack *b);

//bonus
char	*gnl_strjoin(char *s1, char *s2);
char	*gnl_strchr(const char *s, int c);
char	*gnl_buffer(char *buf);
char	*alloc_newbuffer(size_t i, size_t alloc, char *buf);
char	*get_next_line(int fd);
char	*gnl_substr(char *buf);
size_t	gnl_strlen(const char *s);
void	checker(t_data *data);

#endif

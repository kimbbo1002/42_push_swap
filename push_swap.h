/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bokim <bokim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 15:00:53 by ayhammou          #+#    #+#             */
/*   Updated: 2025/12/13 17:35:01 by bokim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <stdbool.h>
# include <limits.h>

typedef struct t_stack
{
	int				value;
	struct t_stack	*next;
}	t_stack;

typedef struct operation
{
	int	total;
	int	pa;
	int	pb;
	int sa;
	int sb;
	int	ss;
	int	ra;
	int	rb;
	int	rr;
	int	rra;
	int	rrb;
	int	rrr;
}t_operation;

typedef struct s_data
{
	t_stack		*a;
	t_stack		*b;
	t_operation	operation;
	int			strategy;
	bool		bench_mode;
	double		disorder;
}	t_data;



# define START_ADAPTIVE 0
# define START_SIMPLE 1
# define START_MEDIUM 2
# define START_COMPLEX 3

//operations
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


void	init_data(t_data *data);
int		duplicate(t_stack *stack, int num);
t_stack	*store(int content);
void	add_stack(t_stack **numbers, t_stack *store);
int		parsing_arg(char *stack, t_stack **digit_stack);
int		ft_strcmp(char *s1, char *s2);
double	calc_disorder(t_stack *a);
void	ft_bzero(void *s, size_t n);
void	exec_op(t_data *data, char *operation);
int stack_size(t_stack *stack);

#endif

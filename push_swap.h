/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayhammou <ayhammou@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 15:00:53 by ayhammou          #+#    #+#             */
/*   Updated: 2025/12/15 17:20:15 by ayhammou         ###   ########.fr       */
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
	int				index;
	struct t_stack	*next;
}	t_stack;

typedef struct operation
{
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
	int	total;
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
int		stack_size(t_stack *stack);
void	simple_algo(t_data *data);
void	medium_sort(t_data *data, int range);
void	dispatch_op(t_data *data);
void	ft_putstr_error(char *s);
void	ft_putnbr_error(int n);
void	ft_putfloat_error(double n);
void	bench_mode(t_data *data, double disorder);

#endif

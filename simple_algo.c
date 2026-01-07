/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_algo.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 15:51:07 by ayhammou          #+#    #+#             */
/*   Updated: 2026/01/07 01:38:37 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	find_min(t_stack *a)
{
	int	min_idx;
	int	min_val;
	int	i;

	if (!a)
		return (-1);
	min_idx = 0;
	i = 0;
	min_val = a->value;
	while (a)
	{
		if (a->value < min_val)
		{
			min_idx = i;
			min_val = a->value;
		}
		a = a->next;
		i++;
	}
	return (min_idx);
}

static void	sort_three1(t_data *data)
{
	int	top;
	int	mid;
	int	bot;

	top = data->a->value;
	mid = data->a->next->value;
	bot = data->a->next->next->value;
	if (top < mid && mid > bot && top > bot)
		exec_rra(data);
	else if (top < bot && bot < mid)
	{
		exec_rra(data);
		exec_sa(data);
	}
}

static void	sort_three(t_data *data)
{
	int	top;
	int	mid;
	int	bot;

	top = data->a->value;
	mid = data->a->next->value;
	bot = data->a->next->next->value;
	if (top > mid && mid < bot && top < bot)
		exec_sa(data);
	else if (top > mid && mid > bot)
	{
		exec_sa(data);
		exec_rra(data);
	}
	else if (top > mid && mid < bot && top > bot)
	{
		exec_rra(data);
		exec_rra (data);
	}
	sort_three1(data);
}

static void	move_min(t_data *data)
{
	int	min_idx;
	int	i;
	int	size;

	min_idx = find_min(data->a);
	size = stack_size(data->a);
	i = 0;
	if (min_idx <= size / 2)
	{
		while (i++ < min_idx)
			exec_ra(data);
	}
	else
	{
		while (i++ < size - min_idx)
			exec_rra(data);
	}
	exec_pb(data);
}

void	simple_sort(t_data *data)
{
	int	size;

	size = stack_size(data->a);
	if (size == 2)
	{
		if (data->a->value > data->a->next->value)
			exec_sa(data);
		return ;
	}
	while (size > 3)
	{
		move_min(data);
		size--;
	}
	sort_three(data);
	while (data->b)
		exec_pa(data);
}

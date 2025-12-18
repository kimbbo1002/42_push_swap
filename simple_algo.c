/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_algo.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayhammou <ayhammou@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 15:51:07 by ayhammou          #+#    #+#             */
/*   Updated: 2025/12/17 14:21:35 by ayhammou         ###   ########.fr       */
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
	while (a != NULL)
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
	int	i;
	int	size;

	size = stack_size(data->a);
	if (size == 2)
	{
		if (data->a->value > data->a->next->value)
			exec_sa(data);
		return ;
	}
	while (size > 0)
	{
		move_min(data);
		size--;
	}
	i = 0;
	while (data->b != NULL)
		exec_pa(data);
}

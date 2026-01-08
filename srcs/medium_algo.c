/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium_algo.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayhammou <ayhammou@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/12 17:12:46 by ayhammou          #+#    #+#             */
/*   Updated: 2025/12/19 14:29:47 by ayhammou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	index_value(t_stack *a)
{
	int		idx;
	int		tmp;
	t_stack	*num;
	t_stack	*browse;

	idx = 0;
	if (!a)
		return ;
	num = a;
	while (num != NULL)
	{
		tmp = num->value;
		browse = a;
		while (browse != NULL)
		{
			if (tmp > browse->value)
				idx++;
			browse = browse->next;
		}
		num->index = idx;
		idx = 0;
		num = num->next;
	}
}

int	max_idx(t_stack *b)
{
	int	idx;
	int	max;
	int	i;

	if (!b)
		return (0);
	idx = 0;
	i = 0;
	max = b->value;
	while (b != NULL)
	{
		if (b->value > max)
		{
			max = b->value;
			idx = i;
		}
		i++;
		b = b->next;
	}
	return (idx);
}

static void	move_to_b(t_data *data, int range)
{
	int	i;

	i = 0;
	index_value(data->a);
	while (data->a != NULL)
	{
		if (data->a->index < i)
		{
			exec_pb(data);
			exec_rb(data);
			i++;
		}
		else if (data->a->index <= (i + range))
		{
			exec_pb(data);
			i++;
		}
		else
			exec_ra(data);
	}
}

static void	move_to_a(t_data *data)
{
	int	size;
	int	idx_max;

	while (data->b != NULL)
	{
		size = stack_size(data->b);
		idx_max = max_idx(data->b);
		if (idx_max < (size / 2))
		{
			while (idx_max > 0)
			{
				exec_rb(data);
				idx_max--;
			}
		}
		if (idx_max >= (size / 2))
		{
			while (idx_max < size)
			{
				exec_rrb(data);
				idx_max++;
			}
		}
		exec_pa(data);
	}
}

void	medium_sort(t_data *data, int range)
{
	move_to_b(data, range);
	move_to_a(data);
}

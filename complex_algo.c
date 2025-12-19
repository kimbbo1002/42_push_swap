/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex_algo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayhammou <ayhammou@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/19 13:42:52 by ayhammou          #+#    #+#             */
/*   Updated: 2025/12/19 16:29:09 by ayhammou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	get_max_bits(t_data *data)
{
	t_stack *first;
	int		max_index;
	int		max_bits;

	max_bits = 0;
	index_value(data->a);
	first = data->a;
	max_index = max_idx(data->a);
	while (first->next != NULL)
	{
		if (first->index > first->next->index)
			max_index = first->index;
		first = first->next; 
	}
	while ((max_index >> max_bits) != 0)
		max_bits++;
	return (max_bits);
}

void	complex_algo(t_data *data)
{
	int		i;
	int		j;
	int		size;
	int		max_bits;
	t_stack	*first;

	size =stack_size(data->a);
	max_bits = get_max_bits(data);
	i = 0;
	while (i < max_bits)
	{
		j = 0;
		while (j < size)
		{
			first = data->a;
			if (((first->index >> i) & 1) == 1)
			{
				exec_ra(data);
			}
			else
				exec_pb(data);
			j++;
		}
		while (data->b != NULL)
			exec_pa(data);
		i++;
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex_algo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayman <ayman@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/19 13:42:52 by ayhammou          #+#    #+#             */
/*   Updated: 2026/01/04 16:44:05 by ayman            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	get_max_bits(t_data *data)
{
	int		max_index;
	int		max_bits;

	max_bits = 0;
	index_value(data->a);
	max_index = max_idx(data->a);
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

	size = stack_size(data->a);
	max_bits = get_max_bits(data);
	i = 0;
	while (i < max_bits)
	{
		j = 0;
		while (j++ < size)
		{
			if (((data->a->index >> i) & 1) == 1)
			{
				exec_ra(data);
			}
			else
				exec_pb(data);
		}
		while (data->b != NULL)
			exec_pa(data);
		i++;
	}
}

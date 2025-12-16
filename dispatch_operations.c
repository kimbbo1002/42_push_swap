/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dispatch_operations.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bokim <bokim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 15:17:32 by ayhammou          #+#    #+#             */
/*   Updated: 2025/12/16 17:34:37 by bokim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int static	is_sorted(t_data *data)
{
	t_stack	*first;

	if (!data->a)
		return (1);
	first = data->a;
	while (first->next != NULL)
	{
		if ((first->value) > (first->next->value))
			return (0);
		first = first->next;
	}
	return (1);
}
void	dispatch_op(t_data *data)
{
	double	d;

	d = calc_disorder(data->a);
	if (data->strategy == 1)
		simple_algo(data);
	else if (data->strategy == 2)
		medium_sort (data, 15);
	else if (data->strategy == 3)
		medium_sort (data, 45);
	else
	{
		if (d < 0.2)
		{
			if (is_sorted(data) == 0)
				simple_algo(data);
		}
		else if (d >= 0.2 && d < 0.5)
			medium_sort (data, 15);
		else if (d >= 0.5)
			medium_sort (data, 45);
	}
}
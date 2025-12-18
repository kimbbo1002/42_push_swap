/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dispatch_operations.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayhammou <ayhammou@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 15:17:32 by ayhammou          #+#    #+#             */
/*   Updated: 2025/12/18 11:52:56 by ayhammou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_data *data)
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
	if (data->strategy == 1)
		simple_sort(data);
	else if (data->strategy == 2)
		medium_sort(data, 15);
	else if (data->strategy == 3)
		medium_sort(data, 45);
	else
	{
		if (data->disorder < 2000)
		{
			if (is_sorted(data) == 0)
				simple_sort(data);
		}
		else if (data->disorder >= 2000 && data->disorder < 5000)
			medium_sort(data, 15);
		else if (data->disorder >= 5000)
			medium_sort(data, 45);
	}
}

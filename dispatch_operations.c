/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dispatch_operations.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bokim <bokim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 15:17:32 by ayhammou          #+#    #+#             */
/*   Updated: 2026/01/05 14:39:23 by bokim            ###   ########.fr       */
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

int	ft_sqrt(int nb)
{
	long	i;

	if (nb < 0)
		return (0);
	if (nb == 0 || nb == 1)
		return (nb);
	i = 1;
	while (i * i <= nb)
		i++;
	return (i - 1);
}

void	dispatch_op(t_data *data)
{
	int	size;

	size = stack_size(data->a);
	if (is_sorted(data) && data->b == NULL)
		return ;
	if (data->strategy == 1)
		simple_sort(data);
	else if (data->strategy == 2)
		medium_sort(data, ft_sqrt(size));
	else if (data->strategy == 3)
		complex_algo(data);
	else
	{
		if (data->disorder < 2000 || size < 6)
		{
			if (is_sorted(data) == 0)
				simple_sort(data);
		}
		else if (data->disorder >= 2000 && data->disorder < 5000)
			medium_sort(data, ft_sqrt(size));
		else if (data->disorder >= 5000)
			complex_algo(data);
	}
}

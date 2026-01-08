/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 14:42:29 by marvin            #+#    #+#             */
/*   Updated: 2026/01/09 00:23:59 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	free_stack(t_data *data)
{
	t_stack	*tmp;

	while (data->a != NULL)
	{
		tmp = data->a;
		data->a = data->a->next;
		free(tmp);
	}
	while (data->b != NULL)
	{
		tmp = data->b;
		data->b = data->b->next;
		free(tmp);
	}
}

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

void	init_data(t_data *data)
{
	data->a = NULL;
	data->b = NULL;
	
}

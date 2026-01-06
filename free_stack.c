/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayhammou <ayhammou@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 16:24:19 by ayhammou          #+#    #+#             */
/*   Updated: 2026/01/06 16:59:19 by ayhammou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

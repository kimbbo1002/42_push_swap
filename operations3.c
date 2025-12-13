/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bokim <bokim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/13 17:31:14 by bokim             #+#    #+#             */
/*   Updated: 2025/12/13 17:34:44 by bokim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_data *data)
{
	t_stack	*tmp;
	t_stack	*first;
	t_stack **a;

	a = &(data->a);
	if (!a || !(*a) || !(*a)->next)
		return ;
	first = *a;
	while ((*a)->next->next != NULL)
		(*a) = (*a)->next;
	tmp = (*a)->next;
	(*a)->next = NULL;
	tmp->next = first;
	*a = tmp;
	data->operation.rra++;
	data->operation.total++;
}

void	rrb(t_data *data)
{
	t_stack	*tmp;
	t_stack	*first;
	t_stack	**b;

	b = &(data->b);
	if (!b || !(*b) || !(*b)->next)
		return ;
	first = (*b);
	while ((*b)->next->next != NULL)
		(*b) = (*b)->next;
	tmp = (*b)->next;
	(*b)->next = NULL;
	tmp->next = first;
	*b = tmp;
	data->operation.rra++;
	data->operation.total++;
}

void	rrr(t_data *data)
{
	rra(data);
	rrb(data);
	data->operation.rrr++;
	data->operation.rra--;
	data->operation.rrb--;
	data->operation.total--;
}

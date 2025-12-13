/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bokim <bokim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/13 17:29:50 by bokim             #+#    #+#             */
/*   Updated: 2025/12/13 17:31:06 by bokim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_data *data)
{
	t_stack	*tmp;
	t_stack	*last;
	t_stack **a;

	a = &(data->a);
	if (!a || !*a || !(*a)->next)
		return ;
	tmp = (*a);
	*a = tmp->next;
	tmp->next = NULL;
	last = (*a);
	while (last->next != NULL)
	{
		last = last->next;
	}
	last->next = tmp;
	data->operation.ra++;
	data->operation.total++;
}

void	rb(t_data *data)
{
	t_stack	*tmp1;
	t_stack	*tmp2;
	t_stack **b;

	b = &(data->b);
	if (!b || !*b || !(*b)->next)
		return ;
	tmp1 = *b;
	*b = tmp1->next;
	tmp1->next = NULL;
	tmp2 = *b;
	while (tmp2->next != NULL)
	{
		tmp2 = tmp2->next;
	}
	tmp2->next = tmp1;
	data->operation.rb++;
	data->operation.total++;
}

void	rr(t_data *data)
{
	ra(data);
	rb(data);
	data->operation.rr++;
	data->operation.ra--;
	data->operation.rb--;
	data->operation.total--;
}

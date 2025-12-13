/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bokim <bokim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/13 17:28:24 by bokim             #+#    #+#             */
/*   Updated: 2025/12/13 17:29:32 by bokim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_data *data)
{
	int	tmp;
	t_stack **a;

	a = &(data->a);
	if (!a || !*a || !(*a)->next)
		return ;
	tmp = (*a)->value;
	(*a)->value = (*a)->next->value;
	(*a)->next->value = tmp;
	data->operation.sa++;
	data->operation.total++;
}

void	sb(t_data *data)
{
	int	tmp;
	t_stack **b;

	b = &(data->b);
	if (!b || !*b || !(*b)->next)
		return ;
	tmp = (*b)->value;
	(*b)->value = (*b)->next->value;
	(*b)->next->value = tmp;
	data->operation.sb++;
	data->operation.total++;
}

void	ss(t_data *data)
{
	sa(data);
	sb(data);
	data->operation.ss++;
	data->operation.sa--;
	data->operation.sb--;
	data->operation.total--;
}

void	pa(t_data *data)
{
	t_stack	*tmp;
	t_stack **a;
	t_stack **b;

	a = &(data->a);
	b = &(data->b);
	if (!b || !*b)
		return ;
	tmp = (*b);
	(*b) = (*b)->next;
	tmp->next = *a;
	*a = tmp;
	data->operation.pa++;
	data->operation.total++;
}

void	pb(t_data *data)
{
	t_stack	*tmp;
	t_stack **a;
	t_stack **b;

	a = &(data -> a);
	b = &(data -> b);
	if (!a || !(*a))
		return ;
	tmp = (*a);
	*a = (*a)->next;
	tmp->next = *b;
	*b = tmp;
	data->operation.pb++;
	data->operation.total++;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bokim <bokim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/13 17:28:24 by bokim             #+#    #+#             */
/*   Updated: 2025/12/16 14:57:54 by bokim            ###   ########.fr       */
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
}

void	ss(t_data *data)
{
	sa(data);
	sb(data);
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
}

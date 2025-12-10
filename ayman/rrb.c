/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrb.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayhammou <ayhammou@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/06 16:36:00 by ayhammou          #+#    #+#             */
/*   Updated: 2025/12/10 15:19:26 by ayhammou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_stack **b)
{
	t_stack	*tmp;
	t_stack	*first;

	if (!b || !(*b) || !(*b)->next)
		return ;
	first = (*b);
	while ((*b)->next->next != NULL)
		(*b) = (*b)->next;
	tmp = (*b)->next;
	(*b)->next = NULL;
	tmp->next = first;
	*b = tmp;
}

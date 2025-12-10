/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rra.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayhammou <ayhammou@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/06 16:19:08 by ayhammou          #+#    #+#             */
/*   Updated: 2025/12/10 15:19:14 by ayhammou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_stack **a)
{
	t_stack	*tmp;
	t_stack	*first;

	if (!a || !(*a) || !(*a)->next)
		return ;
	first = *a;
	while ((*a)->next->next != NULL)
		(*a) = (*a)->next;
	tmp = (*a)->next;
	(*a)->next = NULL;
	tmp->next = first;
	*a = tmp;
}

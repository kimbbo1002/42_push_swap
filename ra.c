/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ra.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayhammou <ayhammou@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 14:32:10 by ayhammou          #+#    #+#             */
/*   Updated: 2025/12/10 15:18:38 by ayhammou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_stack **a)
{
	t_stack	*tmp;
	t_stack	*last;

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
}

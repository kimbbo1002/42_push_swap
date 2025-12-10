/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rb.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayhammou <ayhammou@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 15:38:34 by ayhammou          #+#    #+#             */
/*   Updated: 2025/12/10 15:18:56 by ayhammou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rb(t_stack **b)
{
	t_stack	*tmp1;
	t_stack	*tmp2;

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
}

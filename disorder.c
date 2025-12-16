/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disorder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bokim <bokim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 11:03:55 by ayhammou          #+#    #+#             */
/*   Updated: 2025/12/16 16:44:53 by bokim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	calc_disorder(t_stack *a)
{
	t_stack	*i;
	t_stack	*j;
	int		total_pairs;
	int		mistakes;
	int		percentage;

	if (!a || !a->next)
		return (0);
	i = a;
	total_pairs = 0;
	mistakes = 0;
	while (i)
	{
		j = i->next;
		while (j)
		{
			total_pairs++;
			if (i->value > j->value)
				mistakes++;
			j = j->next;
		}
		i = i->next;
	}
	percentage = ((double)mistakes / total_pairs * 10000) + 0.5;
	return (percentage);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disorder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bokim <bokim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 14:19:44 by bokim             #+#    #+#             */
/*   Updated: 2025/12/10 14:34:26 by bokim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "disorder.h"

double	calc_disorder(struct stack *a)
{
	stack *i;
	stack *j;
	int	total_pairs;
	int	mistakes;

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
			if (i->val > j->val)
			mistakes++;
			j = j->next;
		}
		i = i->next;
	}
	return ((double)mistakes / total_pairs);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_algo.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bokim <bokim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 15:28:23 by bokim             #+#    #+#             */
/*   Updated: 2025/12/10 16:33:34 by bokim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "disorder.h"
#include "libft/libft.h"

/*
simple_algo() completely relies on the operations such as sa() sb() .. 
to update the total operation number, and number of each operation 
in bench
*/

void	simple_algo(stack *a, stack *b, bench *ben)
{
	int		i;
	int		size;
	
	ben->strategy = "Selection Sort Adaption / O(n^2)";
	size = ft_lstsize(a);
	while (ft_lstsize(a) > 0)
		move_min(a, b, ben);
	i = 0;
	while (i++ < size)
		pa(a, b, ben);
}

int	find_min(stack *a)
{
	int	i;
	int	min_val;
	int	min_index;

	i = 0;
	min_index = 0;
	min_val = a->val;
	while(a)
	{
		if (a->val < min_val)
		{
			min_val = a->val;
			min_index = i;
		}
		i++;
		a = a->next;
	}
	return (min_index);
}

void	move_min(stack *a, stack *b, bench *ben)
{
	int	min;
	int	i;
	int	size;

	min = find_min(a);
	size = ft_lstsize(a);
	i = 0;
	if (min <= size / 2)
	{
		while (i++ < min)
			ra(a, b, ben);
		pb(a, b, ben);
	}
	else
	{
		while (i++ < size - min)
			rra(a, b, ben);
		pb(a, b, ben);
	}
}
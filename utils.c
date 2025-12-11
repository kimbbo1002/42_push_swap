/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayhammou <ayhammou@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 16:40:14 by ayhammou          #+#    #+#             */
/*   Updated: 2025/12/11 14:40:04 by ayhammou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_data(t_data *data)
{
	data->a = NULL;
	data->b = NULL;
	ft_bzero(&data->ops, sizeof(t_operation));
	data->strategy = START_ADAPTIVE;
	data->bench_mode = false;
	data->disorder = 0.0;
}

int	duplicate(t_stack *stack, int num)
{
	while (stack != NULL)
	{
		if (stack->value == num)
			return (0);
		stack = stack->next;
	}
	return (1);
}

t_stack	*store(int content)
{
	t_stack	*new_num;

	new_num = (t_stack *)malloc(sizeof(t_stack));
	if (new_num == 0)
		return (NULL);
	new_num->value = content;
	new_num->next = NULL;
	return (new_num);
}

void	add_stack(t_stack **numbers, t_stack *store)
{
	t_stack	*last;

	if (store == NULL)
		return ;
	if (*numbers == NULL)
	{
		*numbers = store;
		return ;
	}
	last = *numbers;
	while (last->next != NULL)
		last = last->next;
	last->next = store;
}

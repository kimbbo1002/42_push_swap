/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bokim <bokim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 16:40:14 by ayhammou          #+#    #+#             */
/*   Updated: 2025/12/16 18:03:55 by bokim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_data(t_data *data)
{
	data->a = NULL;
	data->b = NULL;
	ft_bzero(&data->operation, sizeof(t_operation));
	data->strategy = 0;
	data->bench_mode = false;
	data->disorder = 0.00;
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
	new_num->index = -1;
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

int stack_size(t_stack *stack)
{
    int count;

    count = 0;
    if (!stack)
        return (0);
    
    while (stack)
    {
        count++;
        stack = stack->next;
    }
    return (count);
}
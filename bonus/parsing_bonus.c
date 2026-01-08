/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 14:39:14 by marvin            #+#    #+#             */
/*   Updated: 2026/01/09 00:19:11 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

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

static int	ft_atol(char *stack, int *i, long *result)
{
	long	total;
	int		sign;

	sign = 1;
	total = 0;
	while ((stack[*i] >= 9 && stack[*i] <= 13) || stack[*i] == 32)
		(*i)++;
	if (stack[*i] == '-' || stack[*i] == '+')
	{
		if (stack[*i] == '-')
			sign = -1;
		(*i)++;
	}
	if (stack[*i] < 48 || stack[*i] > 57)
		return (0);
	while (stack[*i] >= 48 && stack[*i] <= 57)
	{
		total = (total * 10) + (stack[*i] - '0');
		(*i)++;
	}
	if ((total * sign) > 2147483647 || (total * sign) < -2147483648)
		return (0);
	*result = (total * sign);
	return (1);
}

int	parsing_arg(char *stack, t_stack **digit_stack)
{
	int		i;
	long	result;
	t_stack	*new_num;

	i = 0;
	new_num = NULL;
	while (stack[i])
	{
		if (ft_atol(stack, &i, &result) == 0)
			return (0);
		if (!duplicate(*digit_stack, result))
			return (0);
		new_num = store(result);
		add_stack(digit_stack, new_num);
		if (stack[i] != 32 && stack[i] != '\0' && (stack[i] < 9
				|| stack[i] > 13))
			return (0);
	}
	return (1);
}

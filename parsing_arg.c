/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_arg.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayhammou <ayhammou@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 15:23:19 by ayhammou          #+#    #+#             */
/*   Updated: 2025/12/11 11:04:33 by ayhammou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
		if (ft_atol (stack, &i, &result) == 0)
			return (0);
		if (!duplicate(*digit_stack, result))
			return (0);
		new_num = store(result);
		add_stack(digit_stack, new_num);
		if (stack[i] != 32 && stack[i] != '\0'
			&& (stack[i] < 9 || stack[i] > 13))
			return (0);
	}
	return (1);
}

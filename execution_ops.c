/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution_ops.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayhammou <ayhammou@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 14:45:23 by ayhammou          #+#    #+#             */
/*   Updated: 2025/12/11 15:25:55 by ayhammou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	exec_op3(t_data *data, char *operation)
{
	if (ft_strcmp(operation, "pa") == 0)
	{
		pa(&data->a, &data->b);
		data->operation.pa++;
	}
	if (ft_strcmp(operation, "pb") == 0)
	{
		pb(&data->a, &data->b);
		data->operation.pb++;
	}
	if (ft_strcmp(operation, "rr") == 0)
	{
		rr(&data->a, &data->b);
		data->operation.rr++;
	}
	if (ft_strcmp(operation, "rrr") == 0)
	{
		rrr(&data->a, &data->b);
		data->operation.rrr++;
	}
}

void	exec_op2(t_data *data, char *operation)
{
	if (ft_strcmp(operation, "sb") == 0)
	{
		sb(&data->b);
		data->operation.sb++;
	}
	if (ft_strcmp(operation, "rb") == 0)
	{
		rb(&data->b);
		data->operation.rb++;
	}
	if (ft_strcmp(operation, "rrb") == 0)
	{
		rrb(&data->b);
		data->operation.rrb++;
	}
	exec_op3(data, operation);

}

void	exec_op(t_data *data, char *operation)
{
	if (ft_strcmp(operation, "sa") == 0)
	{
		sa(&data->a);
		data->operation.sa++;
	}
	if (ft_strcmp(operation, "ra") == 0)
	{
		ra(&data->a);
		data->operation.ra++;
	}
	if (ft_strcmp(operation, "rra") == 0)
	{
		rra(&data->a);
		data->operation.rra++;
	}
	exec_op2(data, operation);
}


/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_op2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bokim <bokim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 14:52:48 by bokim             #+#    #+#             */
/*   Updated: 2025/12/16 15:18:34 by bokim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	exec_ra(t_data *data, char *op)
{
	if (ft_strcmp(op, "ra"))
	{
		ra(data);
		data->operation.ra++;
		data->operation.total++;
	}
	if (!data->bench_mode)
		ft_printf(1, "%s", op);
}

void	exec_rb(t_data *data, char *op)
{
	if (ft_strcmp(op, "rb"))
	{
		rb(data);
		data->operation.rb++;
		data->operation.total++;
	}
	if (!data->bench_mode)
		ft_printf(1, "%s", op);
}

void	exec_rr(t_data *data, char *op)
{
	if (ft_strcmp(op, "rr"))
	{
		rr(data);
		data->operation.rr++;
		data->operation.total++;
	}
	if (!data->bench_mode)
		ft_printf(1, "%s", op);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_op.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bokim <bokim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 14:46:00 by bokim             #+#    #+#             */
/*   Updated: 2025/12/16 15:18:23 by bokim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	exec_sa(t_data *data, char *op)
{
	if (ft_strcmp(op, "sa"))
	{
		sa(data);
		data->operation.sa++;
		data->operation.total++;
	}
	if (!data->bench_mode)
		ft_printf(1, "%s", op);
}

void	exec_sb(t_data *data, char *op)
{
	if (ft_strcmp(op, "sb"))
	{
		sb(data);
		data->operation.sb++;
		data->operation.total++;
	}
	if (!data->bench_mode)
		ft_printf(1, "%s", op);
}

void	exec_ss(t_data *data, char *op)
{
	if (ft_strcmp(op, "ss"))
	{
		ss(data);
		data->operation.ss++;
		data->operation.total++;
	}
	if (!data->bench_mode)
		ft_printf(1, "%s", op);
}

void	exec_pa(t_data *data, char *op)
{
	if (ft_strcmp(op, "pa"))
	{
		pa(data);
		data->operation.pa++;
		data->operation.total++;
	}
	if (!data->bench_mode)
		ft_printf(1, "%s", op);
}

void	exec_pb(t_data *data, char *op)
{
	if (ft_strcmp(op, "pb"))
	{
		pb(data);
		data->operation.pb++;
		data->operation.total++;
	}
	if (!data->bench_mode)
		ft_printf(1, "%s", op);
}
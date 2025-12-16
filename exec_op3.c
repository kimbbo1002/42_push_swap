/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_op3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bokim <bokim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 14:54:08 by bokim             #+#    #+#             */
/*   Updated: 2025/12/16 15:18:44 by bokim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	exec_rra(t_data *data, char *op)
{
	if (ft_strcmp(op, "rra"))
	{
		rra(data);
		data->operation.rra++;
		data->operation.total++;
	}
	if (!data->bench_mode)
		ft_printf(1, "%s", op);
}

void	exec_rrb(t_data *data, char *op)
{
	if (ft_strcmp(op, "rrb"))
	{
		rrb(data);
		data->operation.rrb++;
		data->operation.total++;
	}
	if (!data->bench_mode)
		ft_printf(1, "%s", op);
}

void	exec_rrr(t_data *data, char *op)
{
	if (ft_strcmp(op, "rrr"))
	{
		rrr(data);
		data->operation.rrr++;
		data->operation.total++;
	}
	if (!data->bench_mode)
		ft_printf(1, "%s", op);
}
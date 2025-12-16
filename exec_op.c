/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_op.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bokim <bokim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 14:46:00 by bokim             #+#    #+#             */
/*   Updated: 2025/12/16 17:52:44 by bokim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	exec_sa(t_data *data)
{
	sa(data);
	data->operation.sa++;
	data->operation.total++;
	if (!data->bench_mode)
		ft_printf(1, "%s", "sa");
}

void	exec_sb(t_data *data)
{
	sb(data);
	data->operation.sb++;
	data->operation.total++;
	if (!data->bench_mode)
		ft_printf(1, "%s", "sb");
}

void	exec_ss(t_data *data)
{
	ss(data);
	data->operation.ss++;
	data->operation.total++;
	if (!data->bench_mode)
		ft_printf(1, "%s", "ss");
}

void	exec_pa(t_data *data)
{
	pa(data);
	data->operation.pa++;
	data->operation.total++;
	if (!data->bench_mode)
		ft_printf(1, "%s", "pa");
}

void	exec_pb(t_data *data)
{
	pb(data);
	data->operation.pb++;
	data->operation.total++;
	if (!data->bench_mode)
		ft_printf(1, "%s", "pb");
}
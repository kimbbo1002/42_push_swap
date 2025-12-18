/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_op.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayhammou <ayhammou@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 14:46:00 by bokim             #+#    #+#             */
/*   Updated: 2025/12/18 11:32:04 by ayhammou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	exec_sa(t_data *data)
{
	sa(data);
	data->operation.sa++;
	data->operation.total++;
	if (!data->bench_mode && !data->checker)
		ft_printf(1, "%s", "sa\n");
}

void	exec_sb(t_data *data)
{
	sb(data);
	data->operation.sb++;
	data->operation.total++;
	if (!data->bench_mode && !data->checker)
		ft_printf(1, "%s", "sb\n");
}

void	exec_ss(t_data *data)
{
	ss(data);
	data->operation.ss++;
	data->operation.total++;
	if (!data->bench_mode && !data->checker)
		ft_printf(1, "%s", "ss\n");
}

void	exec_pa(t_data *data)
{
	pa(data);
	data->operation.pa++;
	data->operation.total++;
	if (!data->bench_mode && !data->checker)
		ft_printf(1, "%s", "pa\n");
}

void	exec_pb(t_data *data)
{
	pb(data);
	data->operation.pb++;
	data->operation.total++;
	if (!data->bench_mode && !data->checker)
		ft_printf(1, "%s", "pb\n");
}

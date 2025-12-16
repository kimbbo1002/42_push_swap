/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_op2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bokim <bokim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 14:52:48 by bokim             #+#    #+#             */
/*   Updated: 2025/12/16 17:49:28 by bokim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	exec_ra(t_data *data)
{
	ra(data);
	data->operation.ra++;
	data->operation.total++;
	if (!data->bench_mode)
		ft_printf(1, "%s", "ra");
}

void	exec_rb(t_data *data)
{
	rb(data);
	data->operation.rb++;
	data->operation.total++;
	if (!data->bench_mode)
		ft_printf(1, "%s", "rb");
}

void	exec_rr(t_data *data)
{
	rr(data);
	data->operation.rr++;
	data->operation.total++;
	if (!data->bench_mode)
		ft_printf(1, "%s", "rr");
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_op3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bokim <bokim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 14:54:08 by bokim             #+#    #+#             */
/*   Updated: 2025/12/16 18:08:21 by bokim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	exec_rra(t_data *data)
{
	rra(data);
	data->operation.rra++;
	data->operation.total++;
	if (!data->bench_mode)
		ft_printf(1, "%s", "rra\n");
}

void	exec_rrb(t_data *data)
{
	rrb(data);
	data->operation.rrb++;
	data->operation.total++;
	if (!data->bench_mode)
		ft_printf(1, "%s", "rrb\n");
}

void	exec_rrr(t_data *data)
{
	rrr(data);
	data->operation.rrr++;
	data->operation.total++;
	if (!data->bench_mode)
		ft_printf(1, "%s", "rrr\n");
}
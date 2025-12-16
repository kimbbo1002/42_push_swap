/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bench_mode.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bokim <bokim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 16:44:56 by ayhammou          #+#    #+#             */
/*   Updated: 2025/12/16 16:52:35 by bokim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	print_adap_strategy(t_data *data)
{
	ft_printf(2, "[bench] strategy : Adaptive");
	if (data->disorder < 2000)
		ft_printf(2, " (O(n²))\n");
	else if (data->disorder >= 2000 && data->disorder < 5000)
		ft_printf(2, " (O(n√n))\n");
	else
		ft_printf(2, " (O(n log n))\n");
}

void	bench_mode(t_data *data)
{
	ft_printf(2, "[bench] disorder : %f\n", data->disorder);
	if (!ft_strcmp(data->strategy, "Adaptive /"))
		print_adap_strategy(data);
	else
		ft_printf(2, "[bench] strategy : %s\n", data->strategy);
	ft_printf(2, "[bench] total_ops : %d\n", 
		data->operation.total);
	ft_printf(2, "[bench] sa: %d sb: %d ss: %d pa: %d pb: %d\n", 
		data->operation.sa, data->operation.sb, data->operation.ss, 
		data->operation.pa, data->operation.pb);
	ft_printf(2, "[bench] ra: %d rb: %d rr: %d rra: %d rrb: %d rrr: %d\n",
		data->operation.ra, data->operation.rb, data->operation.rr,
		data->operation.rra, data->operation.rrb, data->operation.rrr);
}
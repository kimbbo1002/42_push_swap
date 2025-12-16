/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bench_mode.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bokim <bokim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 16:44:56 by ayhammou          #+#    #+#             */
/*   Updated: 2025/12/16 15:36:56 by bokim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	bench_mode(t_data *data)
{
	ft_printf(2, "[bench] Disorder : %f\n", data->disorder);
	ft_printf(2, "[bench] Strategy : %s\n", data->strategy);
	ft_printf(2, "[bench] Total number of operations : %d\n", 
		data->operation.total);
	ft_printf(2, "[bench] sa: %d sb: %d ss: %d pa: %d pb: %d\n", 
		data->operation.sa, data->operation.sb, data->operation.ss, 
		data->operation.pa, data->operation.pb);
	ft_printf(2, "[bench] ra: %d rb: %d rr: %d rra: %d rrb: %d rrr: %d\n",
		data->operation.ra, data->operation.rb, data->operation.rr,
		data->operation.rra, data->operation.rrb, data->operation.rrr);
}

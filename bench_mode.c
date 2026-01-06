/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bench_mode.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayhammou <ayhammou@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 16:44:56 by ayhammou          #+#    #+#             */
/*   Updated: 2026/01/06 17:14:17 by ayhammou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

#include "push_swap.h"

static void	print_adap_strategy(t_data *data, int size)
{
	ft_printf(2, "[bench] strategy : Adaptive");
	if (data->disorder < 2000 || size < 6)
		ft_printf(2, " (O(n²))\n");
	else if (data->disorder >= 2000 && data->disorder < 5000)
		ft_printf(2, " (O(n√n))\n");
	else
		ft_printf(2, " (O(n log n))\n");
}

static void	print_strategy(t_data *data)
{
	int	size;

	size = stack_size(data->a);
	if (data->strategy == 0)
		print_adap_strategy(data, size);
	else if (data->strategy == 1)
		ft_printf(2, "[bench] strategy : Simple / (O(n²))\n");
	else if (data->strategy == 2)
		ft_printf(2, "[bench] strategy : Medium / (O(n√n))\n");
	else if (data->strategy == 3)
		ft_printf(2, "[bench] strategy : Complex / (O(n log n))\n");
}

void	bench_mode(t_data *data)
{
	ft_printf(2, "[bench] disorder : %f%\n", data->disorder);
	print_strategy(data);
	ft_printf(2, "[bench] total_ops : %d\n", data->operation.total);
	ft_printf(2, "[bench] sa: %d sb: %d ss: %d pa: %d pb: %d\n",
		data->operation.sa, data->operation.sb, data->operation.ss,
		data->operation.pa, data->operation.pb);
	ft_printf(2, "[bench] ra: %d rb: %d rr: %d rra: %d rrb: %d rrr: %d\n",
		data->operation.ra, data->operation.rb, data->operation.rr,
		data->operation.rra, data->operation.rrb, data->operation.rrr);
}

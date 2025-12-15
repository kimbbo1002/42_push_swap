/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bench_mode.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayhammou <ayhammou@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 16:44:56 by ayhammou          #+#    #+#             */
/*   Updated: 2025/12/15 17:35:45 by ayhammou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	bench_mode(t_data *data, double disorder)
{
	ft_putstr_error("[bench] Disorder : ");
	ft_putfloat_error(disorder);
	ft_putstr_error("\n");
	ft_putstr_error("[bench] Strategy : ");
	if (data->strategy == 0)
		ft_putstr_error("Adaptive \n");
	else if (data->strategy == 1)
		ft_putstr_error("Simple \n");
	else if (data->strategy == 2)
		ft_putstr_error("Medium \n");
	else if (data->strategy == 3)
		ft_putstr_error("Complex \n");
	ft_putstr_error("[bench] Total number of operations :");
	ft_putnbr_error(data->operation.total);
	ft_putstr_error("\n");
}

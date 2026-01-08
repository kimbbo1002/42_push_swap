/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 14:15:51 by marvin            #+#    #+#             */
/*   Updated: 2026/01/09 00:22:49 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

static void	run_checker(t_data *data)
{
	checker(data);
	if (is_sorted(data))
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
}

static int	parse_args(int argc, char **argv, t_data *data)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		if (!parsing_arg(argv[i], &data->a))
				return (0);
		i++;
	}
	return (1);
}

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc < 2)
		return (0);
	init_data(&data);
	if (!parse_args(argc, argv, &data))
	{
		write(2, "Error\n", 6);
		free_stack(&data);
		return (0);
	}
	run_checker(&data);
}

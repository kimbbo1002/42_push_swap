/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bokim <bokim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 16:44:57 by ayhammou          #+#    #+#             */
/*   Updated: 2026/01/05 14:08:46 by bokim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf/libftprintf.h"
#include "push_swap.h"

/* static void	print_stack(t_stack *stack)
{
	while (stack != NULL)
	{
		ft_printf(1, "%d\n", stack->value);
		stack = stack->next;
	}
} */
static void	run_checker(t_data *data)
{
	checker(data);
	if (is_sorted(data) == 1 && data->b == NULL)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
}

static int	manage_flags2(char *argv, t_data *data)
{
	if (ft_strcmp(argv, "--complex") == 0)
	{
		data->strategy = 3;
		return (1);
	}
	if (ft_strcmp(argv, "--adaptive") == 0)
		return (1);
	return (0);
}

static int	manage_flags(char *argv, t_data *data)
{
	if (ft_strcmp(argv, "--bench") == 0)
	{
		data->bench_mode = true;
		return (1);
	}
	if (ft_strcmp(argv, "--simple") == 0)
	{
		data->strategy = 1;
		return (1);
	}
	if (ft_strcmp(argv, "--medium") == 0)
	{
		data->strategy = 2;
		return (1);
	}
	return (manage_flags2(argv, data));
}

static int	parse_args(int argc, char **argv, t_data *data)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		if (manage_flags(argv[i], data) == 1)
		{
			if (data->checker == true)
				return (0);
		}
		else
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
	if (ft_strstr(argv[0], "checker"))
		data.checker = true;
	if (parse_args(argc, argv, &data) == 0)
	{
		write(2, "Error\n", 6);
		free_stack(&data);
		return (0);
	}
	if (data.checker == true)
		run_checker(&data);
	else
	{
		data.disorder = calc_disorder(data.a);
		dispatch_op(&data);
		if (data.bench_mode == true)
			bench_mode(&data);
	}
	free_stack(&data);
	return (0);
}

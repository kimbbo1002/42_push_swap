/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bokim <bokim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 16:44:57 by ayhammou          #+#    #+#             */
/*   Updated: 2025/12/16 17:36:18 by bokim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libftprintf/libftprintf.h"

static void	print_stack(t_stack *stack)
{
	while (stack != NULL)
	{
		ft_printf("%d\n", stack->value);
		stack = stack->next;
	}
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

int	main(int argc, char **argv)
{
	int		i;
	t_data	data;

	if (argc < 2)
		return (0);
	init_data (&data);
	i = 1;
	while (i < argc)
	{
		if (manage_flags(argv[i], &data) == 1)
			i++;
		else
		{
			if (parsing_arg (argv[i], &data.a) == 0)
			{
				write(2, "ERROR\n", 6);
				return (0);
			}
			i++;
		}
	}
	data.disorder = calc_disorder(data.a);
	dispatch_op(&data);
	print_stack(data.a);
	if (data.bench_mode == true)
		bench_mode(&data);
	free (data.a);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayhammou <ayhammou@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 16:44:57 by ayhammou          #+#    #+#             */
/*   Updated: 2025/12/19 17:11:37 by ayhammou         ###   ########.fr       */
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

void	free_stack(t_data *data)
{
	t_stack	*tmp;

	while (data->a != NULL)
	{
		tmp = data->a;
		data->a = data->a->next;
		free(tmp);
	}
	while (data->b != NULL)
	{
		tmp = data->b;
		data->b = data->b->next;
		free(tmp);
	}
}

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
	if (ft_strcmp(argv, "checker") == 0)
	{
		data->checker = true;
		return (1);
	}
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
	init_data(&data);
	i = 1;
	while (i < argc)
	{
		if (!manage_flags(argv[i], &data) && !parsing_arg(argv[i], &data.a))
		{
			write(2, "ERROR\n", 6);
			return (0);
		}
		i++;
	}
	data.disorder = calc_disorder(data.a);
	if (data.checker == true)
		run_checker(&data);
	dispatch_op(&data);
	if (data.bench_mode == true)
		bench_mode(&data);
	free_stack(&data);
	return (0);
}

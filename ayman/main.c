/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayhammou <ayhammou@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 16:44:57 by ayhammou          #+#    #+#             */
/*   Updated: 2025/12/10 17:54:56 by ayhammou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libftprintf/ft_printf.h"

void	print_stack(t_stack *stack)
{
	while (stack != NULL)
	{
		ft_printf("%d\n", stack->value);
		stack = stack->next;
	}
}
int	main(int argc, char **argv)
{
	int		i;
	t_stack	*numbers;

	i = 1;
	numbers = NULL;
	if (argc < 2)
		return (0);
	while (i < argc)
	{
		if (parsing_arg (argv[i], &numbers) == 0)
		{
			write(2, "ERROR\n", 6);
			return (0);
		}
		i++;
	}
	print_stack(numbers);
	return (0);
}

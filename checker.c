/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayhammou <ayhammou@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 14:30:49 by ayhammou          #+#    #+#             */
/*   Updated: 2025/12/18 11:55:13 by ayhammou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libftprintf/libftprintf.h"

static void	error_and_exit(t_data *data, char *line)
{
	write(2, "ERROR\n", 6);
	if (line)
		free (line);
	free_stack(data);
	exit(1);
}
static int	take_ops2(t_data *data, char *line)
{
	if (ft_strcmp(line, "ra\n") == 0)
		exec_ra(data);
	else if (ft_strcmp(line, "rb\n") == 0)
		exec_rb(data);
	else if (ft_strcmp(line, "rr\n") == 0)
		exec_rr(data);
	else if (ft_strcmp(line, "rra\n") == 0)
		exec_rra(data);
	else if (ft_strcmp(line, "rrb\n") == 0)
		exec_rrb(data);
	else if (ft_strcmp(line, "rrr\n") == 0)
		exec_rrr(data);
	else
		return (0);
	return (1);
}
void	checker(t_data *data)
{
	char	*line;
	
	line = get_next_line (0);
	while (line != NULL)
	{
		if (ft_strcmp(line, "sa\n") == 0)
			exec_sa(data);
		else if (ft_strcmp(line, "sb\n") == 0)
			exec_sb(data);
		else if (ft_strcmp(line, "ss\n") == 0)
			exec_ss(data);
		else if (ft_strcmp(line, "pa\n") == 0)
			exec_pa(data);
		else if (ft_strcmp(line, "pb\n") == 0)
			exec_pb(data);
		else if (take_ops2(data, line) == 0)
			error_and_exit(data, line);
		free(line);
		line = get_next_line(0);
	}
}

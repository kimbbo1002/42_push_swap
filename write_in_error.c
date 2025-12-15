/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_in_error.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayhammou <ayhammou@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 17:05:52 by ayhammou          #+#    #+#             */
/*   Updated: 2025/12/15 17:31:31 by ayhammou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_putstr_error(char *s)
{
	int	i;
	
	i = 0;
	if (!s)
		return;
	while (s[i])
		i++;
	write(2, s, i);
}
	
void	ft_putnbr_error(int n)
{
	int		sign;
	char	c;
	
	sign = 1;
	if (n < 0)
	{
		sign = -1;
		n = -n;
	}
	if (n < 10)
	{
		c = ((n % 10) + '0');
		write (2, &c, 1);	
	}
	if (n >= 10)
		ft_putnbr_error(n / 10);
}

void	ft_putfloat_error(double n)
{
	int	entier;
	int	decimal;

	entier = (int)(n);
	decimal = (int) ((n - entier) * 100);
	ft_putnbr_error(entier);
	write(2, ".", 1);
	ft_putnbr_error(decimal);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bokim <bokim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 15:48:40 by bokim             #+#    #+#             */
/*   Updated: 2025/12/16 15:28:39 by bokim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr(int fd, int n)
{
	int	tmp;

	if (n < 0)
	{
		ft_putchar(fd, '-');
		ft_putunbr(fd, -n);
	}
	if (n >= 0)
	{
		tmp = n % 10 + '0';
		if (n > 9)
			ft_putnbr(fd, n / 10);
		ft_putchar(fd, tmp);
	}
	return (ft_numlen(n));
}

int	ft_putunbr(int fd, unsigned int n)
{
	int	tmp;

	tmp = n % 10 + '0';
	if (n > 9)
		ft_putunbr(fd, n / 10);
	ft_putchar(fd, tmp);
	return (ft_numlen(n));
}

int	ft_numlen(long n)
{
	int	count;

	count = 0;
	if (n < 0)
	{
		count++;
		n = -n;
	}
	while (n / 10 != 0)
	{
		count++;
		n = n / 10;
	}
	return (count + 1);
}

int	ft_putdouble(int fd, double n)
{
	int	int_part;
	int	frac_part;
	int	scaled;

	scaled = n * 100;
	int_part = scaled / 100;
	frac_part = scaled % 100;
	ft_putnbr(fd, int_part);
	ft_putchar(fd, '.');
	ft_putnbr(fd, frac_part);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bokim <bokim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 15:46:00 by bokim             #+#    #+#             */
/*   Updated: 2025/12/16 17:44:27 by bokim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_putchar(int fd, int c)
{
	write(fd, &c, 1);
	return (1);
}

int	ft_putstr(int fd, char *str)
{
	int	i;

	if (!str)
	{
		ft_putstr(fd, "(null)");
		return (6);
	}
	i = 0;
	while (str[i])
		ft_putchar(fd, str[i++]);
	return (i);
}

int	ft_putvoid(int fd, unsigned long n)
{
	int	tmp;
	int	count;

	count = 0;
	tmp = n % 16;
	if (n >= 16)
		count = ft_putvoid(fd, n / 16);
	count += ft_puthex(fd, 'x', tmp);
	return (count);
}

int	ft_puthex(int fd, char c, unsigned int n)
{
	char	*base;
	int		count;

	count = 0;
	if (c == 'x')
		base = "0123456789abcdef";
	else
		base = "0123456789ABCDEF";
	if (n >= 16)
		count += ft_puthex(fd, c, n / 16);
	ft_putchar(fd, base[n % 16]);
	return (count + 1);
}

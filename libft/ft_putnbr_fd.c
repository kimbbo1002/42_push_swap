/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bokim <bokim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 10:12:48 by bokim             #+#    #+#             */
/*   Updated: 2025/11/20 11:25:11 by bokim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
description :
ft_putnbr_fd converts the int to a string then writes it to the given fd

return value :
none
*/

void	ft_putnbr_fd(int n, int fd)
{
	int	tmp;

	if (n == -2147483648)
	{
		write(fd, "-2147483648", 11);
		return ;
	}
	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		ft_putnbr_fd(-n, fd);
	}
	if (n >= 0)
	{
		tmp = n % 10 + '0';
		if (n > 9)
			ft_putnbr_fd(n / 10, fd);
		write(fd, &tmp, 1);
	}
}

/*
int	main(void)
{
	ft_putnbr_fd(-2147483648, 1);
}*/
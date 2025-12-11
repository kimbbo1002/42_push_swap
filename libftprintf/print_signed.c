/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_signed.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayhammou <ayhammou@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 11:24:00 by ayhammou          #+#    #+#             */
/*   Updated: 2025/11/19 14:24:14 by ayhammou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdlib.h>

static void	var_declar(int *len, int *i, unsigned long *tmp, unsigned long *n)
{
	*len = 0;
	*i = 1;
	*tmp = *n;
}

static int	itoa_like_int(unsigned long n)
{
	char			*s;
	int				len;
	int				i;
	unsigned long	tmp;

	var_declar(&len, &i, &tmp, &n);
	while (tmp > 0)
	{
		len++;
		tmp = tmp / 10;
	}
	s = malloc(sizeof(char) * (len + 1));
	if (s == 0)
		return (0);
	s[len] = '\0';
	while (len - i >= 0)
	{
		s[len - i] = (n % 10) + '0';
		n = n / 10;
		i++;
	}
	write (1, s, len);
	free (s);
	return (len);
}

int	print_signed(int n)
{
	int				printed;
	unsigned long	number;

	number = (unsigned long)n;
	printed = 0;
	if (n == 0)
	{
		write (1, "0", 1);
		return (1);
	}
	if (n < 0)
	{
		write (1, "-", 1);
		printed++;
		number = -(long)n;
	}
	printed = printed + itoa_like_int(number);
	return (printed);
}

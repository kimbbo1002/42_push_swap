/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayhammou <ayhammou@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 12:44:03 by ayhammou          #+#    #+#             */
/*   Updated: 2025/11/17 14:22:22 by ayhammou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	var_declar(int *len, int *i, unsigned int *tmp, unsigned int *x)
{
	*len = 0;
	*i = 1;
	*tmp = *x;
}

static int	itoa_like_hex(unsigned int x, char *base)
{
	char			*s;
	int				i;
	int				len;
	unsigned int	tmp;

	var_declar(&len, &i, &tmp, &x);
	while (tmp > 0)
	{
		len++;
		tmp = tmp / 16;
	}
	s = malloc(sizeof(char) * (len + 1));
	if (s == 0)
		return (0);
	s[len] = '\0';
	while (len - i >= 0)
	{
		s[len - i] = base[x % 16];
		x = x / 16;
		i++;
	}
	write(1, s, len);
	free(s);
	return (len);
}

int	print_hex(unsigned int x, char format)
{
	int		printed;
	char	*lower_base;
	char	*upper_base;

	printed = 0;
	lower_base = "0123456789abcdef";
	upper_base = "0123456789ABCDEF";
	if (x == 0)
	{
		write (1, "0", 1);
		return (1);
	}
	if (format == 'x')
		printed = itoa_like_hex(x, lower_base);
	if (format == 'X')
		printed = itoa_like_hex(x, upper_base);
	return (printed);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_unsigned.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayhammou <ayhammou@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 12:26:04 by ayhammou          #+#    #+#             */
/*   Updated: 2025/11/19 14:18:02 by ayhammou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	like_itoa_unsigned(unsigned int u)
{
	char			*s;
	int				len;
	int				i;
	unsigned int	tmp;

	len = 0;
	i = 1;
	tmp = u;
	while (tmp > 0)
	{
		len++;
		tmp = tmp / 10;
	}
	s = malloc(sizeof(char) * (len + 1));
	while (len - i >= 0)
	{
		s[len - i] = (u % 10) + '0';
		u = u / 10;
		i++;
	}
	write (1, s, len);
	free(s);
	return (len);
}

int	print_unsigned(unsigned int u)
{
	int	printed;
	int	i;

	i = 0;
	printed = 0;
	if (u == 0)
	{
		write (1, "0", 1);
		return (1);
	}
	return (like_itoa_unsigned(u));
}

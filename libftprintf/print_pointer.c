/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_pointer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayhammou <ayhammou@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 14:34:55 by ayhammou          #+#    #+#             */
/*   Updated: 2025/11/19 14:59:16 by ayhammou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	print_hexpointer(unsigned long ptr)
{
	int		printed;
	char	*base;
	char	c;

	base = "0123456789abcdef";
	printed = 0;
	if (ptr >= 16)
		printed = printed + print_hexpointer(ptr / 16);
	c = base[ptr % 16];
	write (1, &c, 1);
	printed++;
	return (printed);
}

int	print_pointer(void *p)
{
	unsigned long	ptr;
	int				printed;

	ptr = (unsigned long) p;
	printed = 0;
	if (ptr == 0)
	{
		write(1, "(nil)", 5);
		return (5);
	}
	write (1, "0x", 2);
	printed = 2;
	printed = printed + print_hexpointer(ptr);
	return (printed);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayhammou <ayhammou@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/16 11:45:05 by ayhammou          #+#    #+#             */
/*   Updated: 2025/11/19 14:20:06 by ayhammou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	handle3(char format, va_list args)
{
	void	*p;
	char	percent;

	if (format == 'p')
	{
		p = va_arg(args, void *);
		return (print_pointer(p));
	}
	if (format == '%')
	{
		percent = '%';
		write (1, &percent, 1);
		return (1);
	}
	(void)args;
	return (0);
}

static int	handle2(char format, va_list args)
{
	unsigned int	u;
	unsigned int	x;
	unsigned int	xupper;

	if (format == 'u')
	{
		u = va_arg(args, unsigned int);
		return (print_unsigned(u));
	}
	if (format == 'x')
	{
		x = va_arg(args, unsigned int);
		return (print_hex(x, format));
	}
	if (format == 'X')
	{
		xupper = va_arg(args, unsigned int);
		return (print_hex(xupper, format));
	}
	return (handle3(format, args));
}

static int	handle(char format, va_list args)
{
	int				c;
	char			*s;
	long			n;

	if (format == 'c')
	{
		c = va_arg(args, int);
		return (print_char(c));
	}
	if (format == 's')
	{
		s = va_arg(args, char *);
		return (print_string(s));
	}
	if (format == 'd' || format == 'i')
	{
		n = va_arg(args, int);
		return (print_signed(n));
	}
	return (handle2 (format, args));
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		printed;
	int		i;

	if (format == 0)
		return (0);
	printed = 0;
	i = 0;
	va_start(args, format);
	while (format[i])
	{
		if (format[i] == '%' && format[i + 1])
		{
			i++;
			printed = printed + handle(format[i], args);
		}
		else
		{
			write (1, &format[i], 1);
			printed++;
		}
		i++;
	}
	va_end(args);
	return (printed);
}

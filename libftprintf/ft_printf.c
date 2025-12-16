/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bokim <bokim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 14:23:28 by bokim             #+#    #+#             */
/*   Updated: 2025/12/16 16:44:22 by bokim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
return value :
- number of bytes printed
- negative number if error occurs
*/

static int	is_format(char c);
static int	sort_type(int fd, const char c, va_list arg);
static int	do_void(int fd, void *arg);

int	ft_printf(int fd, const char *format, ...)
{
	int		i;
	int		count;
	va_list	arg;

	count = 0;
	i = 0;
	if (!format)
		return (-1);
	va_start(arg, format);
	while (format[i])
	{
		if (format[i] == '%' && is_format(format[i + 1]))
		{
			count += sort_type(fd, format[i + 1], arg);
			i = i + 2;
		}
		else
			count += ft_putchar(fd, format[i++]);
	}
	va_end(arg);
	return (count);
}

static int	is_format(char c)
{
	if (c == 'c' || c == 's' || c == 'p' || c == 'd' || c == 'i' || c == 'u'
		|| c == 'x' || c == 'X' || c == '%')
		return (1);
	else
		return (0);
}

static int	sort_type(int fd, const char c, va_list arg)
{
	int	count;

	count = 0;
	if (c == 'c')
		count = ft_putchar(fd, va_arg(arg, int));
	else if (c == 's')
		count = ft_putstr(fd, va_arg(arg, char *));
	else if (c == 'p')
		count = do_void(fd, va_arg(arg, void *));
	else if (c == 'd' || c == 'i')
		count = ft_putnbr(fd, va_arg(arg, int));
	else if (c == 'u')
		count = ft_putunbr(fd, va_arg(arg, unsigned int));
	else if (c == 'x' || c == 'X')
		count = ft_puthex(fd, c, va_arg(arg, unsigned int));
	else if (c == 'f')
		count = ft_putdouble(fd, va_arg(arg, int));
	else if (c == '%')
		count = ft_putchar(fd, c);
	return (count);
}

static int	do_void(int fd, void *arg)
{
	int	count;

	if (arg == 0)
	{
		count = ft_putstr(fd, "(nil)");
		return (count);
	}
	ft_putstr(fd, "0x");
	count = ft_putvoid(fd, (unsigned long)arg) + 2;
	return (count);
}

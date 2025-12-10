/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bokim <bokim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 12:36:47 by bokim             #+#    #+#             */
/*   Updated: 2025/11/20 11:24:21 by bokim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
description :
ft_itoa converts the integer n into a string

return value :
- the string representing the integer
- NULL if the allocation fails
*/

static char	*ft_revstr(char *str);
static int	ft_intlen(long n);

char	*ft_itoa(int n)
{
	int		i;
	char	*res;
	long	num;

	num = n;
	if (n < 0)
		num = -num;
	res = malloc(sizeof(char) * (ft_intlen(n) + 1));
	if (!res)
		return (0);
	i = 0;
	while (num / 10 != 0)
	{
		res[i++] = num % 10 + '0';
		num = num / 10;
	}
	res[i++] = num + '0';
	if (n < 0)
		res[i++] = '-';
	res[i] = '\0';
	return (ft_revstr(res));
}

static int	ft_intlen(long n)
{
	int		count;
	long	num;

	count = 0;
	num = n;
	if (n < 0)
	{
		count++;
		num = -num;
	}
	while (num / 10 != 0)
	{
		count++;
		num = num / 10;
	}
	return (count + 1);
}

static char	*ft_revstr(char *str)
{
	int		i;
	int		len;
	char	tmp;

	i = 0;
	len = ft_strlen(str);
	while (i < len / 2)
	{
		tmp = str[i];
		str[i] = str[len - i - 1];
		str[len - i - 1] = tmp;
		i++;
	}
	return (str);
}

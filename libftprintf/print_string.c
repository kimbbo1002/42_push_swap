/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_string.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayhammou <ayhammou@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/16 13:44:48 by ayhammou          #+#    #+#             */
/*   Updated: 2025/11/19 13:47:56 by ayhammou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_string(char *s)
{
	int	len;

	len = 0;
	if (s == 0)
	{
		(write(1, "(null)", 6));
		return (6);
	}
	while (s[len])
	{
		len++;
	}
	if (len > 0)
		write(1, s, len);
	return (len);
}

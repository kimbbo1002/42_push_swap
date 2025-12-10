/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bokim <bokim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 09:34:44 by bokim             #+#    #+#             */
/*   Updated: 2025/11/20 11:25:22 by bokim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
description :
ft_strchr finds the first occurence of c in str

return value :
- pointer to the first occurence of c in str
- NULL if c is not found
*/

char	*ft_strchr(const char *str, int c)
{
	size_t	i;
	size_t	len;
	char	*res;

	res = (char *)str;
	i = 0;
	len = ft_strlen(str);
	while (i <= len)
	{
		if (res[i] == (unsigned char)c)
			return (&res[i]);
		i++;
	}
	return (0);
}
/*
#include <stdio.h>

int	main(void)
{
	printf("%s", ft_strchr("hello", 'l'));
}
	*/
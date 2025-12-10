/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bokim <bokim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 09:02:45 by bokim             #+#    #+#             */
/*   Updated: 2025/11/20 11:25:51 by bokim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
description :
ft_strmapi applies function f to each character in s and allocates memory 
to store the resulting new string

return value :
- pointer to the newly created string
- NULL if memory allocation fails
*/

char	*ft_strmapi(const char *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*res;

	if (!f)
		return (ft_strdup(""));
	res = malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (!res)
		return (0);
	i = 0;
	while (s[i])
	{
		res[i] = f(i, s[i]);
		i++;
	}
	res[i] = '\0';
	return (res);
}
/*
#include <stdio.h>

int	main(void)
{
	printf("%s", ft_strmapi("hello", ft_example));
}

char	ft_example(unsigned int n, char c)
{
	if (n % 2 == 0)
		return (c - 32);
	else
		return (n + '0');
}
		*/
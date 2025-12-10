/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bokim <bokim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 13:41:25 by bokim             #+#    #+#             */
/*   Updated: 2025/11/20 09:53:18 by bokim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count_len(char const *s, unsigned int start, size_t len);

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	j;
	char	*res;

	i = 0;
	j = 0;
	if (!s)
		return (malloc(0));
	res = malloc((ft_count_len(s, start, len) + 1) * sizeof(char));
	if (!res)
		return (0);
	if ((size_t)start < ft_strlen(s))
	{
		i = start;
		while (s[i] && j < len)
			res[j++] = s[i++];
	}
	res[j] = '\0';
	return (res);
}

static int	ft_count_len(char const *s, unsigned int start, size_t len)
{
	size_t	count;
	size_t	i;

	count = 0;
	i = ft_strlen(s);
	if ((size_t)start < i)
	{
		if (len < i - (size_t)start)
			count = len;
		else
			count = i - (size_t)start;
	}
	return (count);
}
/*
#include <stdio.h>

int	main(void)
{
	char const* test = "hellothisisatest";
	printf("%s", ft_substr(test, 30, 30));
}
*/
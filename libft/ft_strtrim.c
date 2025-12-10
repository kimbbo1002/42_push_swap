/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bokim <bokim@student.42.fr>	            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 14:13:19 by bokim             #+#    #+#             */
/*   Updated: 2025/11/13 22:29:16 by bokim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_set(char c, char const *set);
static int	count_alloc(char const *s1, char const *set);

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*res;
	size_t	start;
	size_t	end;
	size_t	i;

	if (!s1 || !set)
		return (0);
	start = 0;
	end = ft_strlen(s1) - 1;
	i = 0;
	res = malloc(sizeof(char) * (count_alloc(s1, set) + 1));
	if (!res)
		return (0);
	while (s1[start] && is_set(s1[start], set))
		start++;
	while (end >= start && is_set(s1[end], set))
		end--;
	while (s1[start] && start <= end)
		res[i++] = s1[start++];
	res[i] = '\0';
	return (res);
}

static int	is_set(char c, char const *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if ((unsigned char)c == (unsigned char)set[i])
			return (1);
		i++;
	}
	return (0);
}

static int	count_alloc(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;
	size_t	count;

	start = 0;
	end = ft_strlen(s1) - 1;
	count = 0;
	while (s1[start] && is_set(s1[start], set))
		start++;
	while (end >= start && is_set(s1[end], set))
		end--;
	while (s1[start] && start++ <= end)
		count++;
	return (count);
}
/*
#include <stdio.h>

int	main(void)
{
	printf("%s", ft_strtrim(" lorem ipsum dolor sit amet", "l "));
}
*/
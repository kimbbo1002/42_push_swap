/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bokim <bokim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 11:01:46 by bokim             #+#    #+#             */
/*   Updated: 2025/11/20 11:15:54 by bokim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
description :
ft_split allocates and copies an array of strings by splitting the given
string s using the given separator c

return value :
- array of strings resulting from the split
- NULL if memory allocation fails
*/

static int		count_group(char const *s, char c);
static char		*assign_word(char *str, char c);
static int		check_malloc(char *str, char **res);

char	**ft_split(char const *s, char c)
{
	char	**res;
	int		i;
	int		j;

	i = 0;
	j = 0;
	res = malloc(sizeof(char *) * count_group(s, c));
	if (!res || !s)
		return (0);
	while (s[i])
	{
		if (s[i] != (unsigned char)c)
		{
			res[j] = assign_word((char *)&s[i], c);
			if (!check_malloc(res[j++], res))
				return (0);
			while (s[i] && s[i] != (unsigned char)c)
				i++;
		}
		else
			i++;
	}
	res[j] = 0;
	return (res);
}

static int	check_malloc(char *str, char **res)
{
	int	i;

	i = 0;
	if (!str)
	{
		while (res[i])
			free(res[i++]);
		free(res);
		return (0);
	}
	else
		return (1);
}

static int	count_group(char const *s, char c)
{
	int	i;
	int	count;

	if (!s)
		return (0);
	i = 0;
	count = 0;
	while (s[i])
	{
		if (s[i] != (unsigned char)c)
		{
			count++;
			while (s[i] && s[i] != (unsigned char)c)
				i++;
		}
		else
			i++;
	}
	return (count + 1);
}

static char	*assign_word(char *str, char c)
{
	char	*word;
	int		i;

	i = 0;
	while (str[i] && str[i] != (unsigned char)c)
		i++;
	word = malloc(sizeof(char) * (i + 1));
	if (!word)
		return (0);
	i = 0;
	while (str[i] && str[i] != (unsigned char)c)
	{
		word[i] = str[i];
		i++;
	}
	word[i] = '\0';
	return (word);
}

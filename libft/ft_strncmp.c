/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bokim <bokim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 09:00:22 by bokim             #+#    #+#             */
/*   Updated: 2025/11/11 15:28:59 by bokim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	*cpy1;
	unsigned char	*cpy2;

	i = 0;
	cpy1 = (unsigned char *)s1;
	cpy2 = (unsigned char *)s2;
	while (i < n && (cpy1[i] || cpy2[i]))
	{
		if (cpy1[i] == cpy2[i])
			i++;
		else
			return (cpy1[i] - cpy2[i]);
	}
	return (0);
}
/*
#include <stdio.h>
#include <stdlib.h>

int	main(int argc, char** argv)
{
    (void)argc;
    printf("%d", ft_strncmp(argv[1], argv[2], atoi(argv[3])));
}
	*/
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bokim <bokim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 09:00:12 by bokim             #+#    #+#             */
/*   Updated: 2025/11/20 11:25:42 by bokim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
description :
ft_strlcpy copies up to dstsize - 1 characters from src to dst

return value :
total length of the string that it tried to create (length of src)
*/

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;

	i = 0;
	if (dstsize != 0)
	{
		while (i < dstsize - 1 && src[i])
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	return (ft_strlen(src));
}

/*
#include <stdio.h>
#include <string.h>

int	main(int argc, char **argv)
{
    char dest[5];

    (void)argc;
    printf("%u\n", ft_strlcpy(dest, argv[1], 5));
    printf("%s", dest);
}
	*/
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bokim <bokim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 13:33:17 by bokim             #+#    #+#             */
/*   Updated: 2025/11/20 11:25:27 by bokim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
description :
ft_strdup duplicates s1 by allocating memory and copying

return value :
- pointer to the new string
- NULL if the memory allocation fails
*/

char	*ft_strdup(const char *s1)
{
	char	*res;
	size_t	len;

	len = ft_strlen(s1);
	res = malloc((len + 1) * sizeof(char));
	if (!res)
		return (0);
	ft_strlcpy(res, s1, len + 1);
	return (res);
}

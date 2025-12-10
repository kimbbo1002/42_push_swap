/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bokim <bokim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 10:35:23 by bokim             #+#    #+#             */
/*   Updated: 2025/11/20 10:56:30 by bokim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
description :
ft_memcpy copies n btyes from src to dst
- does not account for memory overlaps

return value :
- pointer to dst
- NULL if src and dst are both NULL
*/

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	i;

	i = 0;
	if (!dst && !src)
		return (0);
	while (i < n)
	{
		*(unsigned char *)(dst + i) = *(unsigned char *)(src + i);
		i++;
	}
	return (dst);
}
/*
#include <stdio.h>
int main() {

    // Initialize a variable
    int a = 20;
    int b = 10;
    
    printf("Value of b before calling memcpy: %d\n", b);

    // Use memcpy to copy the value of 'a' into 'b'
    ft_memcpy(&b, &a, sizeof(int)); 

    printf("Value of b after calling memcpy: %d\n", b);

    return 0;
}
	*/
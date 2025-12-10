/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bokim <bokim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 11:54:11 by bokim             #+#    #+#             */
/*   Updated: 2025/11/20 09:26:48 by bokim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
description :
ft_calloc allocated memorty for an array and fills the memory with 0

return value :
- pointer to the allocated memory
- NULL if memory allocation fails
- if n or size is 0, a unique pointer value that can be successfully passed 
to free()
*/

void	*ft_calloc(size_t nmemb, size_t size)
{
	unsigned char	*res;

	if (nmemb != 0 && size > SIZE_MAX / nmemb)
		return (0);
	res = malloc(size * nmemb);
	if (!res)
		return (0);
	ft_memset(res, 0, size * nmemb);
	return (res);
}
/*
#include <stdio.h>
#include <stdlib.h>

int	main(void) {
    int *ptr = (int *)ft_calloc(5, sizeof(int));
    
    // Checking if failed or pass
    if (ptr == NULL) {
        printf("Allocation Failed");
        exit(0);
    }
    
    // No need to populate as already
    // initialized to 0
        
    // Print the array
    for (int i = 0; i < 5; i++)
        printf("%d ", ptr[i]);
    return (0);
}
	*/

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bokim <bokim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 15:15:53 by bokim             #+#    #+#             */
/*   Updated: 2025/11/20 10:55:54 by bokim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
description :
ft_memmove copies len bytes from src to dst
- memory areas may overlap

return value :
- pointer to dst
- NULL if src and dst are both NULL
*/

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t		i;

	if (!dst && !src)
		return (0);
	if (dst < src)
	{
		i = 0;
		while (i < len)
		{
			*(unsigned char *)(dst + i) = *(unsigned char *)(src + i);
			i++;
		}
	}
	else
	{
		i = len;
		while (i > 0)
		{
			i--;
			*(unsigned char *)(dst + i) = *(unsigned char *)(src + i);
		}
	}
	return (dst);
}
/*
#include <stdio.h>
#include <string.h>

int main () {
   char dest_str[] = "oldstring";
   const char src_str[]  = "newstring";
   (void)dest_str;
   (void)src_str;
   printf("Before memmove dest = %s, src = %s\n", 0, 0);
   ft_memmove(dest_str, dest_str + 5, 9);
   printf("After memmove dest = %s, src = %s\n", 0, 0);
   return(0);
}
*/

/*
#include <stdio.h> 
#include <string.h> 
int main() 
{ 
char csrc[100] = "Geeksfor"; 
memmove(csrc+5, csrc, strlen(csrc)+1); 
printf("%s", csrc); 
return 0; 
}
*/
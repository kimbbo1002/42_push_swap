/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bokim <bokim@student.42.fr>    	        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 09:55:17 by bokim             #+#    #+#             */
/*   Updated: 2025/11/11 23:29:13 by bokim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
description :
ft_memchr serches n bytes of the memory pointed by s for the first occurence
of c. 

return value :
- a pointer to the matching byte
- NULL if the character does not occur
*/

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*res;

	i = 0;
	res = (unsigned char *)s;
	while (i < n)
	{
		if (res[i] == (unsigned char)c)
			return (&res[i]);
		i++;
	}
	return (0);
}

/*
#include <stdio.h>
#include <string.h>

int	main(void) {
   const char str[] = "Welcome to India";
   const char ch = 't';

   char* result = (char*)memchr(str, ch, strlen(str));

   if (result != NULL) {
       printf("'%c' found at position %ld\n", ch, result - str);
   } else {
       printf("'%c' not found in the string\n", ch);
   }
   
   return (0);
}
   */

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bokim <bokim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 10:06:52 by bokim             #+#    #+#             */
/*   Updated: 2025/11/20 11:24:46 by bokim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
description :
ft_memcmp compares the first n bytes of s1 and s2

return value :
- 
- 0 if same
*/

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*cpy1;
	unsigned char	*cpy2;

	i = 0;
	cpy1 = (unsigned char *)s1;
	cpy2 = (unsigned char *)s2;
	while (i < n)
	{
		if (cpy1[i] != cpy2[i])
			return (cpy1[i] - cpy2[i]);
		i++;
	}
	return (0);
}
/*
#include <stdio.h>
#include <string.h>

int main () 
{
   char str1[15];
   char str2[15];
   int ret;

   memcpy(str1, "abcdef", 6);
   memcpy(str2, "ABCDEF", 6);

   ret = ft_memcmp(str1, str2, 5);

   if(ret > 0) {
      printf("str2 is less than str1");
   } 
   else if(ret < 0) {
      printf("str1 is less than str2");
   } 
   else {
      printf("str1 is equal to str2");
   }
   return(0);
}*/

/*
#include <stdio.h>
#include <string.h>

int	main(void) {
   int arr1[] = {1, 2, 3, 5, 5};
   int arr2[] = {1, 2, 3, 4, 6};

   int result = ft_memcmp(arr1, arr2, sizeof(arr1));

   if (result == 0) {
       printf("Arrays are equal\n");
   } else {
       printf("Arrays are not equal\n");
   }
    return (0);
}
*/
/*
#include <stdio.h>
#include <string.h>

int	main(void) {
   char str1[] = "12345678901400345678";
   char str2[] = "1234567";

   int result = memcmp(str1, str2, 10);

   if (result < 0) {
       printf("First is less than second.\n");
   } else if (result == 0) {
       printf("First is equal to second.\n");
   } else {
       printf("First is greater than second.\n");
   }
    return (0);
}
	*/
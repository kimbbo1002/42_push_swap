/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bokim <bokim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 10:31:41 by bokim             #+#    #+#             */
/*   Updated: 2025/11/20 11:25:57 by bokim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
description :
ct_Strnstr searches first n bytes of big for the first occurence of little

return value :
- pointer to first char of first occurence of little in big
- pointer to big is little is empty
- NULL if little is not found
*/

char	*ft_strnstr(const char *big, const char *little, size_t n)
{
	size_t	i;
	size_t	j;
	size_t	little_len;

	little_len = ft_strlen(little);
	if (little_len == 0 || big == little)
		return ((char *)big);
	i = 0;
	while (i < n && big[i])
	{
		j = 0;
		while (little[j] && big[i + j] == little[j] && i + j < n)
		{
			j++;
			if (!little[j])
				return ((char *)&big[i]);
		}
		i++;
	}
	return (0);
}
/*
#include <stdio.h>
#include <string.h>

int main () {
   const char str[20] = "TutorialsPoint";
   const char substr[10] = "Point";
   char *ret;
   
   // strstr(main_string, substring)
   ret = ft_strnstr(str, substr, 20);
   
   // Display the output
   printf("The substring is: %s\n", ret);
   
   return(0);
}
   */

/*
#include <stdio.h>
#include <string.h>

int	main(void) {
   char str_1[100] = "Welcome to Tutorialspoint";
   char *str_2;
   str_2 = ft_strnstr(str_1, "ials", 100);
   printf("\nSubstring is: %s", str_2);
   return (0);
}
*/
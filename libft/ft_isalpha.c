/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bokim <bokim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 14:45:04 by bokim             #+#    #+#             */
/*   Updated: 2025/11/20 11:24:05 by bokim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
description :
ft_isalpha checks whether the value of c is alphabetic

return value :
- 1 if c is alphabetic
- 0 if not
*/

int	ft_isalpha(int c)
{
	if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))
		return (1);
	else
		return (0);
}

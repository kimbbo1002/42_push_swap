/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bokim <bokim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 15:08:00 by bokim             #+#    #+#             */
/*   Updated: 2025/11/20 11:38:03 by bokim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
description :
ft_isprint checks whether the value of c is a printable character

return value :
- 1 if c is printable
- 0 if not
*/

int	ft_isprint(int c)
{
	if (c > 31 && c < 127)
		return (1);
	else
		return (0);
}

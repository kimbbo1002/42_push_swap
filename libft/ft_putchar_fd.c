/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bokim <bokim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 10:04:57 by bokim             #+#    #+#             */
/*   Updated: 2025/11/20 11:25:03 by bokim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
description :
ft_putchar_fd writes the given character to the given fd

return value :
none
*/

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

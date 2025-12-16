/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bokim <bokim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 14:24:25 by bokim             #+#    #+#             */
/*   Updated: 2025/12/16 17:55:04 by bokim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

// standard headers
# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

// libft
int		ft_strcmp(char *s1, char *s2);
void	ft_bzero(void *s, size_t n);


// printf
int	ft_printf(int fd, const char *format, ...);
int	ft_putchar(int fd, int c);
int	ft_putstr(int fd, char *str);
int	ft_putnbr(int fd, int n);
int	ft_putunbr(int fd, unsigned int n);
int	ft_puthex(int fd, char c, unsigned int n);
int	ft_putvoid(int fd, unsigned long n);
int	ft_putdouble(int fd, int n);
int	ft_numlen(long n);

#endif
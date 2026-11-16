/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fermonte <fermonte@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/10 17:25:44 by fermonte          #+#    #+#             */
/*   Updated: 2026/11/16 14:43:40 by fermonte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

int	ft_printf(const char *format, ...);
int	ft_format(char format, va_list args);
int	ft_putdec(unsigned int n);
int	ft_putnbr(int n);
int	ft_putstr(char *str);
int	ft_putchar(int c);
int	ft_puthex(unsigned long n, char format);
int	ft_putprt(void *prt);

#endif

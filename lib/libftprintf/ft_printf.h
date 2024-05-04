/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emyildir <emyildir@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 19:35:42 by emyildir          #+#    #+#             */
/*   Updated: 2023/12/27 19:35:42 by emyildir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>

int	ft_printf(const char *str, ...);
int	ft_putchar(char c);
int	ft_putstr(char *str);
int	print_base(unsigned long long num, int base, char *charset);
int	handle_char(va_list va);
int	handle_string(va_list va);
int	handle_hex_lower(va_list va);
int	handle_hex_upper(va_list va);
int	handle_address(va_list va);
int	handle_int(va_list va);
int	handle_unsigned_int(va_list va);

#endif
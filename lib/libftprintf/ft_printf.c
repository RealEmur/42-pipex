/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emyildir <emyildir@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 19:35:27 by emyildir          #+#    #+#             */
/*   Updated: 2023/12/27 19:35:27 by emyildir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	handle_format(char c, va_list va)
{
	int		(*f[128])(va_list);
	size_t	i;

	i = 0;
	while (i < 128)
		f[i++] = 0;
	f['c'] = handle_char;
	f['s'] = handle_string;
	f['x'] = handle_hex_lower;
	f['X'] = handle_hex_upper;
	f['p'] = handle_address;
	f['d'] = handle_int;
	f['i'] = handle_int;
	f['u'] = handle_unsigned_int;
	if (c >= 0 && f[(int) c])
		return (f[(int) c](va));
	return (0);
}

int	ft_printf(const char *str, ...)
{
	int		chars_written;
	size_t	index;
	va_list	va;

	chars_written = 0;
	index = 0;
	va_start(va, str);
	while (str[index])
	{
		if (str[index] == '%' && str[++index])
		{
			if (str[index] == '%')
				chars_written += ft_putchar('%');
			else
				chars_written += handle_format(str[index], va);
			index++;
		}
		else if (str[index])
			chars_written += ft_putchar(str[index++]);
	}
	va_end(va);
	return (chars_written);
}

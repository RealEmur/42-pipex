/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emyildir <emyildir@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 15:21:06 by emyildir          #+#    #+#             */
/*   Updated: 2024/01/10 15:21:06 by emyildir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	print_base(unsigned long long num, int base, char *charset)
{
	unsigned long long	divider;
	int					total_chars;

	total_chars = 0;
	divider = 1;
	while (num / divider >= (unsigned long long) base)
		divider *= base;
	while (divider > 0)
	{
		ft_putchar(charset[num / divider]);
		total_chars++;
		num = num % divider;
		divider /= base;
	}
	return (total_chars);
}

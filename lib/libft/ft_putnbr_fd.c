/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emyildir <emyildir@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 21:06:29 by emyildir          #+#    #+#             */
/*   Updated: 2023/12/06 21:06:29 by emyildir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	int		divider;
	long	num;

	num = n;
	divider = 1;
	if (num < 0)
	{
		ft_putchar_fd('-', fd);
		num *= -1;
	}
	while (num / divider >= 10)
		divider *= 10;
	while (divider >= 1)
	{
		ft_putchar_fd('0' + (num / divider), fd);
		num = num % divider;
		divider /= 10;
	}
}

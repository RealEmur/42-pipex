/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_address.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emyildir <emyildir@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 15:48:39 by emyildir          #+#    #+#             */
/*   Updated: 2024/01/10 15:48:39 by emyildir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	handle_address(va_list va)
{
	return (\
	ft_putstr("0x") + \
	print_base(va_arg(va, unsigned long long), 16, "0123456789abcdef"));
}

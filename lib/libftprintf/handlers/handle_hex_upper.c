/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_hex_upper.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emyildir <emyildir@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 15:28:33 by emyildir          #+#    #+#             */
/*   Updated: 2024/01/10 15:28:33 by emyildir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	handle_hex_upper(va_list va)
{
	return (\
	print_base(va_arg(va, unsigned int), 16, "0123456789ABCDEF"));
}

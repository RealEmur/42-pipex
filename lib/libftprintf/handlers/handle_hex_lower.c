/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_hex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emyildir <emyildir@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 15:25:32 by emyildir          #+#    #+#             */
/*   Updated: 2024/01/10 15:25:32 by emyildir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	handle_hex_lower(va_list va)
{
	return (\
	print_base(va_arg(va, unsigned int), 16, "0123456789abcdef"));
}

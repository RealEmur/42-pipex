/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_string.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emyildir <emyildir@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 19:14:29 by emyildir          #+#    #+#             */
/*   Updated: 2024/01/08 19:14:29 by emyildir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	handle_string(va_list va)
{
	char	*str;

	str = va_arg(va, char *);
	if (!str)
		return (ft_putstr("(null)"));
	return (ft_putstr(str));
}

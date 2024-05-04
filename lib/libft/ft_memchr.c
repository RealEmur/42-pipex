/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emyildir <emyildir@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 18:30:10 by emyildir          #+#    #+#             */
/*   Updated: 2023/12/07 18:42:25 by emyildir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*char_s;
	size_t			i;

	char_s = (unsigned char *) s;
	i = 0;
	while (i < n)
	{
		if (char_s[i] == (unsigned char) c)
			return (char_s + i);
		i++;
	}
	return (0);
}

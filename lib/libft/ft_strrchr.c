/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emyildir <emyildir@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 20:24:36 by emyildir          #+#    #+#             */
/*   Updated: 2023/12/07 15:51:03 by emyildir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	i;
	size_t	last_index;

	if ((char) c == '\0')
		return ((char *)(s + ft_strlen(s)));
	i = 0;
	last_index = 0;
	while (s[i])
	{
		if (s[i] == (char) c)
			last_index = i;
		i++;
	}
	if (last_index == 0 && s[0] != (char) c)
		return (0);
	return ((char *) s + last_index);
}

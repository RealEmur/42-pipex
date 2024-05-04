/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emyildir <emyildir@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 18:59:24 by emyildir          #+#    #+#             */
/*   Updated: 2023/12/07 18:54:34 by emyildir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	needle_len;

	needle_len = ft_strlen(needle);
	if (needle_len == 0)
		return ((char *) haystack);
	i = 0;
	while (haystack[i] && i + needle_len <= len && \
	ft_strncmp(haystack + i, needle, ft_strlen(needle)) != 0)
		i++;
	if (!*haystack || i + needle_len > len)
		return (0);
	return ((char *) haystack + i);
}

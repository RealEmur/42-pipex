/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emyildir <emyildir@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 17:43:04 by emyildir          #+#    #+#             */
/*   Updated: 2023/12/06 17:43:04 by emyildir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	s_len;
	char	*str;

	s_len = ft_strlen(s);
	if (start > s_len)
		len = 0;
	else if (len > s_len - start)
		len = s_len - start;
	str = (char *) malloc(sizeof(char) * (len + 1));
	if (!str)
		return (0);
	i = 0;
	str[len] = '\0';
	while (i < len && s[start + i])
	{
		str[i] = s[start + i];
		i++;
	}
	return (str);
}

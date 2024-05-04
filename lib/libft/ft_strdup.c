/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emyildir <emyildir@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 20:11:06 by emyildir          #+#    #+#             */
/*   Updated: 2023/12/08 21:10:35 by emyildir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	size_t	len;
	char	*str;

	len = ft_strlen(s1) + 1;
	str = (char *) malloc(sizeof(char) * len);
	if (!str)
		return (0);
	ft_strlcpy(str, s1, len);
	return (str);
}

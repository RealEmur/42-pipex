/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emyildir <emyildir@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 18:50:31 by emyildir          #+#    #+#             */
/*   Updated: 2023/12/07 16:53:06 by emyildir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*chr_s1;
	unsigned char	*chr_s2;
	size_t			i;

	chr_s1 = (unsigned char *) s1;
	chr_s2 = (unsigned char *) s2;
	i = 0;
	while (i < n && chr_s1[i] == chr_s2[i])
		i++;
	if (i == n)
		return (0);
	return (chr_s1[i] - chr_s2[i]);
}

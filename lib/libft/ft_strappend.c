/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strappend.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emyildir <emyildir@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 12:32:30 by emyildir          #+#    #+#             */
/*   Updated: 2024/05/04 12:52:12 by emyildir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strappend(char const *s1, char const *s2)
{
	char	*str;

	str = ft_strjoin(s1, s2);
	free((void *) s1);
	return (str);
}

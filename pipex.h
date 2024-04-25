/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emyildir <emyildir@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 23:35:18 by emyildir          #+#    #+#             */
/*   Updated: 2024/04/25 23:36:12 by emyildir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/wait.h>
# include <fcntl.h>

char	*ft_strjoin(const char *str1, const char *str2);
char	**ft_split(char const *s, char c);
int		ft_strlen(const char *str);
int		ft_strncmp(const char *s1, const char *s2, size_t n);

#endif

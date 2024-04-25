#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <fcntl.h>

char    *ft_strjoin(const char *str1, const char *str2);
int     ft_strlen(const char *str);
int     ft_strncmp(const char *s1, const char *s2, size_t n);
char	**ft_split(char const *s, char c);

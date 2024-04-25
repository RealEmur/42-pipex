#include "../pipex.h"

char *ft_strjoin(const char *s1, const char *s2)
{
	size_t	s1_len;
	size_t  s2_len;
	size_t	i;
	char	*str;

	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	str = malloc(sizeof(char) * (s1_len + s2_len + 1));
	if(!str)
		return (0);
	i = 0;
	while(i < s1_len)
	{
		str[i] = s1[i];
		i++;
	}
	i = 0;
	while(i < s2_len)
	{
		str[i + s1_len] = s2[i];
		i++;
	}
	str[i + s1_len] = '\0';
	return str;

}
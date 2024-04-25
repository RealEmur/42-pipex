#include "../pipex.h"

int ft_strlen(const char *str)
{
	int size;

	size = 0;
	while(str[++size]);
	return size;
}

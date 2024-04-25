#include "pipex.h"

char *get_command_path(char *command)
{
	if (!command)
		return 0;
	return ft_strjoin("/bin/", command);
}



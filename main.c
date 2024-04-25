#include "pipex.h"

//access(const char *path, int amode) -> dosyaya erisim izni

void	swap_str_and_free(char **str, char *new_str)
{
	free(*str);
	*str = new_str;
}

char *get_path(char *command, char **env)
{
	char 	**paths;
	char	*path;
	size_t	i;

	i = 0;
	while(ft_strncmp(env[i], "PATH", 4))
		i++;
	paths = ft_split(env[i] +5 , ':');
	i = 0;
	while(paths[i])
	{
		
		path = ft_strjoin(paths[i++], "/");
		swap_str_and_free(&path, ft_strjoin(path, command));
		if(!access(path, F_OK))
			break;
		free(path);
	}
	while(paths[i])
		free(paths[i++]);
	free(paths);
	return path;
}

char *execute_command(char *command, char **env, int *p, int count, int fd)
{
	char	**command_splitted;
	char 	*path;
	pid_t 	pid;
	int		i;

	command_splitted = ft_split(command, ' ');
	path = get_path(command_splitted[0], env);
	pid = fork();
	if(pid)
	{
		if(count == 0)
		{
			close(p[0]);
			dup2(fd, STDIN_FILENO);
			dup2(p[1], STDOUT_FILENO);
		}
		else if(count == 1)
		{
			close(p[1]);
			dup2(fd, STDOUT_FILENO);
			dup2(p[0], STDIN_FILENO);
		}
		else
		{
			dup2(p[0], STDIN_FILENO);
			dup2(p[1], STDOUT_FILENO);
		}
		execve(path, command_splitted, env);
		exit(1);
	}
	else
		waitpid(pid, 0, 0);
	i = 0;
	while(command_splitted[i])
		free(command_splitted[i++]);
	free(command_splitted);
	free(path);
	return 0;
}

int main(int size, char **args, char **env)
{
	int input_file;
	int output_file;

	int	p[2];

	if(pipe(p) < 0)
		return 0;
	input_file = open(args[1], O_RDWR);
	output_file = open(args[4], O_RDWR);
	if(input_file == -1|| output_file == -1) 
		printf("HATA");
	if(size == 5)
	{
		execute_command(args[2], env, p, 0, input_file);
		execute_command(args[3], env, p, 1, output_file);
	}
	else
		printf("Usage: ./a.out <input_file> command command <outputfile>\n");
	return 0;	
}

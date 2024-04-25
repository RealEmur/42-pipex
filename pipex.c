/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emyildir <emyildir@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 23:30:27 by emyildir          #+#    #+#             */
/*   Updated: 2024/04/26 02:40:54 by emyildir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	swap_str_and_free(char **str, char *new_str)
{
	free(*str);
	*str = new_str;
}

char	*get_path(char *command, char **env)
{
	char	**paths;
	char	*path;
	size_t	i;

	i = 0;
	while (ft_strncmp(env[i], "PATH", 4))
		i++;
	path = 0;
	paths = ft_split(env[i] + 5, ':');
	i = 0;
	while (paths[i])
	{
		path = ft_strjoin(paths[i++], "/");
		swap_str_and_free(&path, ft_strjoin(path, command));
		if (!access(path, F_OK))
			break ;
		free(path);
		path = 0;
	}
	i = 0;
	while (paths[i])
		free(paths[i++]);
	free(paths);
	return (path);
}

void	free_matrix(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

void	execute_command(char *command, char **env, int *p, int index, int fd)
{
	char	**command_splitted;
	char	*path;
	pid_t	pid;

	command_splitted = ft_split(command, ' ');
	path = get_path(command_splitted[0], env);
	if (!path)
		send_error("Command not found.\n");
	pid = fork();
	if (pid)
	{
		close(p[index]);
		dup2(fd, index);
		dup2(p[!index], !index);
		if (execve(path, command_splitted, env) == -1)
			send_error("An error occured while running the command.\n");
		exit(1);
	}
	waitpid(pid, 0, 0);
	free_matrix(command_splitted);
	free(path);
}

int	main(int size, char **args, char **env)
{
	int	input_file;
	int	output_file;
	int	p[2];

	if (size != 5)
		send_error(\
		"Usage: ./pipex <input file> <command1> <command2> <output file>\n");
	if (pipe(p) < 0)
		send_error("An error occured\n");
	input_file = open(args[1], O_RDWR);
	if (input_file == -1)
		send_error("Input file could not found\n");
	output_file = open(args[4], O_RDWR);
	if (output_file == -1)
		send_error("Output file could not found.\n");
	execute_command(args[2], env, p, 0, input_file);
	execute_command(args[3], env, p, 1, output_file);
	return (0);
}

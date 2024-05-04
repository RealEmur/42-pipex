/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emyildir <emyildir@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 23:30:27 by emyildir          #+#    #+#             */
/*   Updated: 2024/05/04 13:04:01 by emyildir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	send_error(char *str)
{
	ft_putstr_fd(str, STDERR_FILENO);
	exit(EXIT_FAILURE);
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
		path = ft_strappend(path, command);
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

void	exec_command(char *command, char **env)
{
	char	**command_splitted;
	char	*path;
	size_t	i;

	command_splitted = ft_split(command, ' ');
	if (!command_splitted[0])
		send_error(ERROR_EMPTY_COMMAND);
	path = get_path(command_splitted[0], env);
	if (execve(path, command_splitted, env) == -1)
	{
		i = 0;
		while (command_splitted[i])
		{
			free(command_splitted[i]);
			i++;
		}
		free(command_splitted);
		free(path);
		send_error(ERROR_COMMAND_NOT_FOUND);
	}
}

int	dup_io(int input_fd, int output_fd, int close_fd)
{
	close(close_fd);
	dup2(input_fd, STDIN_FILENO);
	dup2(output_fd, STDOUT_FILENO);
	return (1);
}

int	main(int size, char **args, char **env)
{
	int		input_file;
	int		output_file;
	int		p[2];
	pid_t	pid;

	if (size != 5)
		send_error(ERROR_INVALID_ARGS);
	if (pipe(p) < 0)
		send_error(ERROR_PIPE);
	input_file = open(args[1], O_RDONLY);
	if (input_file == -1)
		send_error(ERROR_INPUT_FILE);
	output_file = open(args[4], O_WRONLY);
	if (output_file == -1)
		send_error(ERROR_OUTPUT_FILE);
	pid = fork();
	if (pid == -1)
		send_error(ERROR_FORK);
	if (pid == 0 && dup_io(input_file, p[1], p[0]))
		exec_command(args[2], env);
	waitpid(pid, 0, 0);
	dup_io(p[0], output_file, p[1]);
	exec_command(args[3], env);
	return (EXIT_SUCCESS);
}

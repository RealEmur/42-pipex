/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emyildir <emyildir@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 23:30:27 by emyildir          #+#    #+#             */
/*   Updated: 2024/04/30 09:41:37 by emyildir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

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

void	first_process(char *command, char **env, int *p, int fd)
{
	char	**command_splitted;
	char	*path;
	pid_t	pid;

	command_splitted = ft_split(command, ' ');
	if (!command_splitted[0])
	{
		ft_putstr("Command is not valid.\n");
		return ;
	}
	path = get_path(command_splitted[0], env);
	if (!path)
		path = ft_strjoin("", command);
	pid = fork();
	if (pid == 0)
	{
		close(p[0]);
		dup2(fd, STDIN_FILENO);
		dup2(p[1], STDOUT_FILENO);
		if (execve(path, command_splitted, env) == -1)
			exit(1);
	}
	waitpid(pid, 0, 0);
	free_matrix(command_splitted);
	free(path);
}

int	second_process(char *command, char **env, int *p, int fd)
{
	char	**command_splitted;
	char	*path;
	int		status;
	pid_t	pid;

	command_splitted = ft_split(command, ' ');
	if (!command_splitted[0])
	{
		ft_putstr("Command is not valid.\n");
		return EXIT_FAILURE;
	}
	path = get_path(command_splitted[0], env);
	if (!path)
		path = ft_strjoin("", command);
	pid = fork();
	if (pid == 0)
	{
		close(p[1]);
		dup2(fd, STDOUT_FILENO);
		dup2(p[0], STDIN_FILENO);
		if (execve(path, command_splitted, env) == -1)
			exit(EXIT_FAILURE);
	}
	waitpid(pid, &status, 0);
	free_matrix(command_splitted);
	free(path);
	return (status);
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
	input_file = open(args[1], O_RDONLY);
	if (input_file == -1)
		send_error("Could't open input file.");
	output_file = open(args[4], O_WRONLY);
	if (output_file == -1)
		send_error("Couldn't open output file.");
	first_process(args[2], env, p, input_file);
	second_process(args[3], env, p, output_file);
	close(input_file);
	close(output_file);
	close(p[0]);
	close(p[1]);
	return (EXIT_SUCCESS);
}

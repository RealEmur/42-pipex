/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emyildir <emyildir@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 23:35:18 by emyildir          #+#    #+#             */
/*   Updated: 2024/05/04 13:03:55 by emyildir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdlib.h>
# include <sys/wait.h>
# include <fcntl.h>
# include "lib/libft/libft.h"
# include "lib/libftprintf/ft_printf.h"

# define ERROR_INPUT_FILE "Couldn't open input file.\n"
# define ERROR_OUTPUT_FILE "Couldn't open output file.\n"
# define ERROR_PIPE "An error occured while initializing the pipe.\n"
# define ERROR_COMMAND "An error occured while running the command.\n"
# define ERROR_EMPTY_COMMAND "You can't give empty string as command.\n"
# define ERROR_COMMAND_NOT_FOUND "Command is not found.\n"
# define ERROR_FORK "An error occured while opening the child process.\n"
# define ERROR_INVALID_ARGS \
"Usage: ./pipex <input file> <command1> <command2> <output file>\n"

#endif

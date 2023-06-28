/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angmarti <angmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 23:31:06 by angmarti          #+#    #+#             */
/*   Updated: 2023/06/15 23:54:19 by angmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/pipex.h"

/**
 * It opens the input file and returns the file descriptor
 *
 * @param infile the name of the file to open
 * @param flags O_RDONLY, O_RDWR
 *
 * @return The file descriptor of the input file.
 */
int	open_in(char *infile, int flags)
{
	int	fd_in;

	if (!infile)
		return (STDIN_FILENO);
	fd_in = open(infile, flags);
	if (fd_in == -1 && access(infile, F_OK) == -1)
	{
		pipex_print_stderr("pipex: ");
		pipex_print_stderr(infile);
		pipex_pf_exit(": No such file or directory", STDERR_FILENO);
	}
	if (fd_in == -1)
	{
		pipex_print_stderr("pipex: permission denied: ");
		pipex_pf_exit(infile, STDERR_FILENO);
	}
	return (fd_in);
}

/**
 * It opens the output file and returns the file descriptor
 *
 * @param outfile the name of the file to open
 * @param flags O_WRONLY, O_CREAT, O_TRUNC, O_APPEND
 * @param mode The mode is specified in octal, and is the same as the mode
 * argument to open(2).
 * @param pid if 0, can exit on open error. If != 0, can't exit on open error.
 *
 * @return The file descriptor of the output file.
 */
int	open_out(char *outfile, int flags, int mode, int pid)
{
	int	fd_out;

	if (!outfile)
		return (STDOUT_FILENO);
	fd_out = open(outfile, flags, mode);
	if (fd_out == -1)
	{
		if (pid)
			exit(EXIT_FAILURE);
		pipex_print_stderr("pipex: permission denied: ");
		pipex_pf_exit(outfile, STDERR_FILENO);
	}
	return (fd_out);
}

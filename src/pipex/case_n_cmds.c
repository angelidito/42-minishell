/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   case_n_cmds.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angmarti <angmarti@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 14:43:05 by angmarti          #+#    #+#             */
/*   Updated: 2023/06/12 18:30:51 by angmarti         ###   ########.fr       */
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
	int	fd_infile;

	fd_infile = open(infile, flags);
	if (fd_infile == -1 && access(infile, F_OK) == -1)
	{
		pipex_print_stderr("pipex: ");
		pipex_print_stderr(infile);
		pipex_pf_exit(": No such file or directory", STDERR_FILENO);
	}
	if (fd_infile == -1)
	{
		pipex_print_stderr("pipex: permission denied: ");
		pipex_pf_exit(infile, STDERR_FILENO);
	}
	return (fd_infile);
}

/**
 * It opens the output file and returns the file descriptor
 *
 * @param outfile the name of the file to open
 * @param flags O_WRONLY, O_CREAT, O_TRUNC, O_APPEND
 * @param mode The mode is specified in octal, and is the same as the mode
 * argument to open(2).
 *
 * @return The file descriptor of the output file.
 */
int	open_out(char *outfile, int flags, int mode, int pid)
{
	int	fd_of;

	fd_of = open(outfile, flags, mode);
	if (fd_of == -1)
	{
		if (pid)
			exit(EXIT_FAILURE);
		pipex_print_stderr("pipex: permission denied: ");
		pipex_pf_exit(outfile, STDERR_FILENO);
	}
	return (fd_of);
}
/**
 * Executes the first command in the pipeline and redirects the input from the
 * input file. It also redirects the output to the pipe that connects it to the
 * parent process.
 *
 * @param vars
 * @param pipe_fd
 */
void	n_child(t_vars *vars, int *pipe_fd)
{
	int	fd_infile;

	pipex_check_cmd(vars->cmds[0], vars->path);
	fd_infile = open_in(vars->infile, O_RDONLY);
	dup2(fd_infile, STDIN_FILENO);
	dup2(pipe_fd[1], STDOUT_FILENO);
	close(pipe_fd[0]);
	pipex_exec_cmd(vars->cmds[0], vars->path, vars->envp);
}

/**
 * Executes a command and redirects the output to the output file or to the pipe
 * that connects it to partent process.
 *
 * @param vars The variables used in the program.
 * @param pipe_fd The pipe.
 * @param fd_out The file descriptor of the output file or the parent's pipe.
 * @param cmd The command to execute.
 */
void	n_parent(t_vars *vars, int *pipe_fd, int fd_out, int cmd)
{
	pipex_check_cmd(vars->cmds[cmd], vars->path);
	dup2(pipe_fd[0], STDIN_FILENO);
	dup2(fd_out, STDOUT_FILENO);
	close(pipe_fd[1]);
	pipex_exec_cmd(vars->cmds[cmd], vars->path, vars->envp);
}
/**
 * It executes the commands in the pipeline and redirects the output to the
 * output file. It also redirects the input from the input file.
 * - It uses pipes to connect the commands.
 * - It uses fork to create new processes.
 * - This function is recursive.
 *
 * @param vars The variables used in the program.
 * @param prev_fd The pipes of the previous command. It is NULL if it is the
 * first command.
 * @param n_comands Number of commands in the pipeline.
 */
void	pipex_case_n_cmds(t_vars *vars, int *prev_fd, int n_comands)
{
	int		pipe_fd[2];
	pid_t	pid;
	int		fd_of;

	if (n_comands == 1)
	{
		n_child(vars, prev_fd);
		return ;
	}
	if (pipe(pipe_fd) == -1)
		pipex_my_perror("\033[1;31mPipe error: ");
	pid = fork();
	if (pid == -1)
		pipex_my_perror("\033[1;31mError while forking.");
	if (!prev_fd && vars->here_doc == 1)
		fd_of = open_out(vars->outfile, O_CREAT | O_RDWR | O_APPEND, 0644, pid);
	else if (!prev_fd)
		fd_of = open_out(vars->outfile, O_CREAT | O_RDWR | O_TRUNC, 0644, pid);
	// else if (!prev_fd)
	// 	fd_of = open_out(vars->outfile, O_CREAT | O_RDWR | vars->flag, 0644,
			// pid);
	// vars->flag = O_TRUNC;
	else
		fd_of = prev_fd[1];
	if (pid == 0)
		pipex_case_n_cmds(vars, pipe_fd, n_comands - 1);
	else
		n_parent(vars, pipe_fd, fd_of, n_comands - 1);
}

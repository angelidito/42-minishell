/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   case_n_cmds.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angmarti <angmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 14:43:05 by angmarti          #+#    #+#             */
/*   Updated: 2023/06/28 21:28:11 by angmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/pipex.h"

/**
 * Returns the file descriptor for the output file, either by opening a new
 * file or using the previous file descriptor.
 * 
 * @param vars A pointer to a struct of type t_vars.
 * @param prev_fd The file descriptors for the previous pipe.
 * @param pid The process ID of the current process.
 * 
 * @return the file descriptor `fd_out`.
 */
int	get_fd_out(t_vars *vars, int *prev_fd, pid_t pid)
{
	int	fd_out;

	if (!prev_fd)
		fd_out = open_out(vars->outfile, O_CREAT | O_RDWR | vars->output_flag,
				0644, pid);
	else
		fd_out = prev_fd[1];
	return (fd_out);
}

/**
 * Returns the process ID (pid) after forking, or 0 if it is a built-in command.
 * 
 * @param builtin 0 means the command is not a built-in; non-zero means it is
 * 
 * @return Current process ID
 */
pid_t	get_pid(int builtin)
{
	pid_t	pid;

	if (!builtin)
	{
		// printf("fork \n");
		pid = fork();
	}
	else
	{
		// printf("no fork \n");
		pid = 0;
	}
	if (pid == -1)
		pipex_my_perror("\033[1;31mError while forking.");
	return (pid);
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
	int		fd_out;
	int		builtin;

	builtin = is_builtin(vars, n_comands - 1);
	if (n_comands > 1 && pipe(pipe_fd) == -1)
		pipex_my_perror("\033[1;31mPipe error: ");
	pid = get_pid(builtin);
	fd_out = get_fd_out(vars, prev_fd, pid);
	if (builtin && n_comands == 1)
		n_child_builtin(vars, prev_fd);
	else if (builtin && n_comands > 1)
		n_parent_builtin(vars, pipe_fd, fd_out, n_comands - 1);
	else if (n_comands < 1)
		pipex_pf_exit("n_comands < 1", STDERR_FILENO);
	else if (pid == 0 && n_comands == 1)
		n_child(vars, prev_fd);
	else if (pid == 0 && n_comands > 1)
		pipex_case_n_cmds(vars, pipe_fd, n_comands - 1);
	else if (n_comands > 1)
		n_parent(vars, pipe_fd, fd_out, n_comands - 1);
	waitpid(pid, NULL, 0);
}

// void	pipex_case_n_cmds(t_vars *vars, int *prev_fd, int n_comands)
// {
// 	int		pipe_fd[2];
// 	pid_t	pid;
// 	int		fd_out;
// 	int		builtin;

// 	// if (n_comands == 0)
// 	// 	return ;
// 	// builtin = is_builtin(vars, n_comands - 1);
// 	builtin = 0;
// 	pid = get_pid(builtin);
// 	if (!builtin)
// 		if (pipe(pipe_fd) == -1)
// 			pipex_my_perror("\033[1;31mPipe error: ");
// 	if (pid == -1)
// 		pipex_my_perror("\033[1;31mError while forking.");
// 	else
// 		fd_out = get_fd_out(vars, prev_fd, pid);
// 	// if (builtin)
// 	// {
// 	// 	exec_builtin(vars, n_comands - 1);
// 	// 	if (n_comands > 1)
// 	// 		pipex_case_n_cmds(vars, pipe_fd, n_comands - 1);
// 	// }
// 	// else
// 	if (pid == 0 && n_comands > 1)
// 		pipex_case_n_cmds(vars, pipe_fd, n_comands - 1);
// 	else if (pid == 0)
// 		n_child(vars, pipe_fd);
// 	else if (n_comands > 1)
// 		n_parent(vars, pipe_fd, fd_out, n_comands - 1);
// 	waitpid(pid, NULL, 0);
// }
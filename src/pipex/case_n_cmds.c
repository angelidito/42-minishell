/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   case_n_cmds.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angmarti <angmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 14:43:05 by angmarti          #+#    #+#             */
/*   Updated: 2023/06/15 23:53:56 by angmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/pipex.h"

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
	int		fd_in;
	t_cmd	*command;

	command = get_t_cmd(vars, 0);
	if (!command)
		pipex_pf_exit("Malloc error.", STDERR_FILENO);
	pipex_check_cmd(command->cmd, command->file);
	fd_in = open_in(vars->infile, O_RDONLY);
	dup2(fd_in, STDIN_FILENO);
	dup2(pipe_fd[1], STDOUT_FILENO);
	close(pipe_fd[0]);
	pipex_exec_cmd(command, lst_to_arr(vars->_envp));
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
	t_cmd	*command;

	command = get_t_cmd(vars, cmd);
	if (!command)
		pipex_pf_exit("Malloc error.", STDERR_FILENO);
	pipex_check_cmd(command->cmd, command->file);
	dup2(pipe_fd[0], STDIN_FILENO);
	dup2(fd_out, STDOUT_FILENO);
	close(pipe_fd[1]);
	pipex_exec_cmd(command, lst_to_arr(vars->_envp));
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
	else if (!prev_fd)
		fd_out = open_out(vars->outfile,
				O_CREAT | O_RDWR | vars->output_flag, 0644, pid);
	else
		fd_out = prev_fd[1];
	if (pid == 0)
		pipex_case_n_cmds(vars, pipe_fd, n_comands - 1);
	else
		n_parent(vars, pipe_fd, fd_out, n_comands - 1);
}

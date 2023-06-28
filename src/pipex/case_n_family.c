/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   case_n_family.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angmarti <angmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 20:42:08 by angmarti          #+#    #+#             */
/*   Updated: 2023/06/28 21:45:21 by angmarti         ###   ########.fr       */
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

	printf("n_child\n");
	command = get_t_cmd(vars, 0);
	if (!command)
		pipex_pf_exit("Malloc error.", STDERR_FILENO);
	fd_in = open_in(vars->infile, O_RDONLY);
	dup2(fd_in, STDIN_FILENO);
	dup2(pipe_fd[1], STDOUT_FILENO);
	close(pipe_fd[0]);
	pipex_exec_cmd(command, lst_to_arr(vars->envp));
}

void	n_child_builtin(t_vars *vars, int *pipe_fd)
{
	int	fd_in;
	int	original_stdin;
	int	original_stdout;

	printf("n_child_builtin\n");
	original_stdin = dup(STDIN_FILENO);
	original_stdout = dup(STDOUT_FILENO);
	fd_in = open_in(vars->infile, O_RDONLY); // TODO: los builtins tienen input?
	dup2(fd_in, STDIN_FILENO);
	dup2(pipe_fd[1], STDOUT_FILENO);
	close(pipe_fd[0]);
	exec_builtin(vars, 0);
	dup2(original_stdin, STDIN_FILENO);
	dup2(original_stdout, STDOUT_FILENO);
	close(fd_in);
	close(pipe_fd[1]);
}

void	n_parent_builtin(t_vars *vars, int *pipe_fd, int fd_out, int cmd)
{
	int	original_stdin;
	int	original_stdout;

	printf("n_parent_builtin\n");
	original_stdin = dup(STDIN_FILENO);
	original_stdout = dup(STDOUT_FILENO);
	dup2(pipe_fd[0], STDIN_FILENO);
	dup2(fd_out, STDOUT_FILENO);
	exec_builtin(vars, cmd);
	dup2(original_stdin, STDIN_FILENO);
	dup2(original_stdout, STDOUT_FILENO);
	close(fd_out);
	close(pipe_fd[0]);
	pipex_case_n_cmds(vars, pipe_fd, cmd);
	// close(pipe_fd[1]); Cerrar esto mas arriba provoca fallos
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

	printf("n_parent\n");
	command = get_t_cmd(vars, cmd);
	// printf("cmd: %s\n", command->cmd);
	if (!command)
		pipex_pf_exit("Malloc error.", STDERR_FILENO);
	pipex_check_cmd(command->cmd, command->file);
	dup2(pipe_fd[0], STDIN_FILENO);
	dup2(fd_out, STDOUT_FILENO);
	close(pipe_fd[1]);
	close(pipe_fd[0]);
	close(fd_out);
	pipex_exec_cmd(command, lst_to_arr(vars->envp));
}

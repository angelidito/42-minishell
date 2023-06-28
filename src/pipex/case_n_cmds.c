/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   case_n_cmds.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angmarti <angmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 14:43:05 by angmarti          #+#    #+#             */
/*   Updated: 2023/06/28 18:01:57 by angmarti         ###   ########.fr       */
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
	fd_in = open_in(vars->infile, O_RDONLY);
	// printf("\nCHILD\n");
	// printf("fd_in: %d\n", fd_in);
	// printf("infile: %s\n", vars->infile);
	// pipex_check_cmd(command->cmd, command->file);
	// printf("command->file: %s\n", command->file);
	// ft_print_strarr_op(command->args, 0, "", "", "args");
	// printf("fd_out: %d\n", pipe_fd[1]);
	dup2(fd_in, STDIN_FILENO);
	dup2(pipe_fd[1], STDOUT_FILENO);
	close(pipe_fd[0]);
	// printf("n_child\n");
	pipex_exec_cmd(command, lst_to_arr(vars->envp));
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
	// printf("\nPARENT\n");
	// printf("fd_in: %d\n", pipe_fd[0]);
	// pipex_check_cmd(command->cmd, command->file);
	// printf("command->file: %s\n", command->file);
	// ft_print_strarr_op(command->args, 0, "", "", "args");
	// printf("outfile: %s\n", vars->outfile);
	// ft_putstr_fd("PRUEBA", STDOUT_FILENO);
	dup2(pipe_fd[0], STDIN_FILENO);
	dup2(fd_out, STDOUT_FILENO);
	close(pipe_fd[1]);
	pipex_exec_cmd(command, lst_to_arr(vars->envp));
}

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

pid_t	get_pid(int builtin, int n_comands)
{
	pid_t	pid;

	if (!builtin && n_comands > 1)
		pid = fork();
	else
		pid = 0;
	return (pid);
}

void	leaks(void)
{
	system("leaks  pipex");
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
	builtin = 0;
	if (pipe(pipe_fd) == -1)
		pipex_my_perror("\033[1;31mPipe error: ");
	pid = get_pid(builtin, n_comands);
	if (pid == -1)
		pipex_my_perror("\033[1;31mError while forking.");
	else
		fd_out = get_fd_out(vars, prev_fd, pid);
	if (builtin)
	{
		int fd_in; //
		if (n_comands == 1)
		{
			fd_in = open_in(vars->infile, O_RDONLY);
			dup2(fd_in, STDIN_FILENO);
			dup2(pipe_fd[1], STDOUT_FILENO);
			close(pipe_fd[0]);
		}
		else if (!prev_fd)
		{
			dup2(pipe_fd[0], STDIN_FILENO);
			dup2(fd_out, STDOUT_FILENO);
			close(pipe_fd[1]);
		}
		exec_builtin(vars, n_comands - 1);
		if (n_comands == 1)
		{
			dup2(STDIN_FILENO, fd_in);
			dup2(STDOUT_FILENO, pipe_fd[1]);
			close(pipe_fd[0]);
		}
		else if (!prev_fd)
		{
			dup2(STDIN_FILENO, pipe_fd[0]);
			dup2(STDOUT_FILENO, fd_out);
			close(pipe_fd[1]);
		}
		if (n_comands > 1)
			pipex_case_n_cmds(vars, pipe_fd, n_comands - 1);
	}
	else if (n_comands == 1)
		n_child(vars, prev_fd);
	else if (pid == 0)
		pipex_case_n_cmds(vars, pipe_fd, n_comands - 1);
	else
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
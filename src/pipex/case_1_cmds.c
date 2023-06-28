/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   case_1_cmds.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angmarti <angmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 14:43:05 by angmarti          #+#    #+#             */
/*   Updated: 2023/06/28 22:29:07 by angmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/pipex.h"

void	builtin_case(t_vars *vars, int fd_out, int fd_in)
{
	int	original_stdin;
	int	original_stdout;

	printf("pipex_case_1_cmd_builtin\n");
	original_stdin = dup(STDIN_FILENO);
	original_stdout = dup(STDOUT_FILENO);
	dup2(fd_in, STDIN_FILENO);
	dup2(fd_out, STDOUT_FILENO);
	exec_builtin(vars, 0);
	dup2(original_stdin, STDIN_FILENO);
	dup2(original_stdout, STDOUT_FILENO);
	close(fd_out);
	close(fd_in);
}

/**
 * It executes the commands in the pipeline and redirects the output to the
 * output file. It also redirects the input from the input file.
 * - It uses pipes to connect the commands.
 * - It uses fork to create new processes.
 * - This function is recursive.
 *
 * @param vars The variables used in the program.
 */
void	pipex_case_1_cmd(t_vars *vars)
{
	t_cmd	*command;
	int		fd_out;
	int		fd_in;

	fd_in = open_in(vars->infile, O_RDONLY);
	fd_out = open_out(vars->outfile, O_CREAT | O_RDWR | vars->output_flag, 0644,
			1);
	if (!is_builtin(vars, 0))
	{
		command = get_t_cmd(vars, 0);
		if (!command)
			pipex_pf_exit("Malloc error.", STDERR_FILENO);
		pipex_check_cmd(command->cmd, command->file);
		dup2(fd_in, STDIN_FILENO);
		dup2(fd_out, STDOUT_FILENO);
		pipex_exec_cmd(command, lst_to_arr(vars->envp));
	}
	else
		builtin_case(vars, fd_in, fd_out);
}

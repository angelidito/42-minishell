/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angmarti <angmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 14:43:05 by angmarti          #+#    #+#             */
/*   Updated: 2023/06/28 21:15:03 by angmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/minishell.h"
#include "../../incs/pipex.h"

int	is_builtin(t_vars *vars, int pos)
{
	char	**args;
	char	*name;

	args = pipex_get_cmd_args(vars->cmds[pos]);
	name = args[0];
	if (0 == ft_strcmp(name, "echo")      //
		|| 0 == ft_strcmp(name, "cd")     //
		|| 0 == ft_strcmp(name, "pwd")    //
		|| 0 == ft_strcmp(name, "export") //
		|| 0 == ft_strcmp(name, "unset")  //
		|| 0 == ft_strcmp(name, "env")    //
		|| 0 == ft_strcmp(name, "exit"))  //
	{
		// printf("builtin: %s\n", name);
		ft_freestrarr(args);
		return (1);
	}
	ft_freestrarr(args);
	return (0);
}

void	exec_builtin(t_vars *vars, int cmd)
{
	char	*name;
	t_cmd	*command;

	command = get_t_cmd(vars, cmd);
	if (!command)
		pipex_pf_exit("Malloc error.", STDERR_FILENO);
	name = command->args[0];
	if (!ft_strcmp(name, "echo"))
		ft_echo(command);
	if (!ft_strcmp(name, "cd"))
		;
	if (!ft_strcmp(name, "pwd"))
		ft_pwd(vars->envp);
	if (!ft_strcmp(name, "export"))
		;
	if (!ft_strcmp(name, "unset"))
		;
	if (!ft_strcmp(name, "env"))
		ft_env(vars->envp);
	if (!ft_strcmp(name, "exit"))
		;
	// free_t_cmd(command);
}

int	pipex(t_vars *vars)
{
	int	number_of_cmds;

	number_of_cmds = ft_strarrsize(vars->cmds);
	if (!vars->envp)
		return (0);
	if (vars->here_doc)
		vars->infile = TEMP_HERE_DOC;
	while (vars->here_doc_limiters && *(vars->here_doc_limiters))
		heredoc(*(vars->here_doc_limiters++));
	if (vars->output_flag != O_APPEND && vars->output_flag != O_TRUNC)
		print_stderr("Error: output flag not valid.");
	if (number_of_cmds == 1)
		pipex_case_1_cmd(vars);
	else if (number_of_cmds > 1)
		pipex_case_n_cmds(vars, NULL, number_of_cmds);
	else
		print_stderr("Error: number of commands < 1.");
	return (0);
}

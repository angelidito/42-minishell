/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built-in.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angmarti <angmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 14:50:57 by angmarti          #+#    #+#             */
/*   Updated: 2023/07/12 15:55:49 by angmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/pipex.h"

/**
 * Checks if a command is a built-in command in a shell program. 
 * We understand a command is built-in when its name matches any of this:
 * echo, cd, pwd, export, unset, env, exit.
 * 
 * @param vars 
 * @param pos The position of the command in the `vars->cmds` array.
 * 
 * @return Returns 1 if it's a built-in command. Otherwise, it returns 0.
 */
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

/**
 * Executes a built-in command based on the command name provided.
 * 
 * @param vars 
 * @param pos The position of the command in the `vars->cmds` array.
 */
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
	else if (!ft_strcmp(name, "cd"))
		print_stderr("TODO: built-in not implemented");
	else if (!ft_strcmp(name, "pwd"))
		ft_pwd(vars->envp);
	else if (!ft_strcmp(name, "export"))
		print_stderr("TODO: built-in not implemented");
	else if (!ft_strcmp(name, "unset"))
		print_stderr("TODO: built-in not implemented");
	else if (!ft_strcmp(name, "env"))
		ft_env(vars->envp);
	else if (!ft_strcmp(name, "exit"))
		print_stderr("TODO: built-in not implemented");
	else
		print_stderr("Error: not a built-in");
	// free_t_cmd(command);
}

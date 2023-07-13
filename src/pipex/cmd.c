/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angmarti <angmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 10:21:15 by angmarti          #+#    #+#             */
/*   Updated: 2023/06/30 15:05:36 by angmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/pipex.h"

/**
 * Creates and returns a `t_cmd` struct with information about a command,
 * including its arguments and file path.
 *
 * TODO: fix for script names inside quotes, and for relative/absolute paths.
 *
 * @param vars The pipex variables struct
 * @param pos The number of the command to get
 *
 * @return A `t_cmd` structure.
 */
t_cmd	*get_t_cmd(t_vars *vars, int pos)
{
	t_cmd	*command;

	command = ft_calloc(1, sizeof(t_cmd));
	if (!command)
		return (NULL);
	command->cmd = vars->cmds[pos];
	command->args = pipex_get_cmd_args(command->cmd);
	vars->path = ft_split(my_getenv("PATH", vars->envp), ':');
	command->file = pipex_get_cmd_file(command->cmd, vars->path);
	return (command);
}

void	free_t_cmd(t_cmd *command)
{
	// ! TODO: con esto peta. no sé ni por qué, ni si dará leaks sin ello
	// free(command->cmd);
	ft_freestrarr(command->args);
	free(command->file);
	free(command);
	// command++;
	// command--;
}

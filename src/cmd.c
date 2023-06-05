/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angmarti <angmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 10:21:15 by angmarti          #+#    #+#             */
/*   Updated: 2023/06/05 12:10:29 by angmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/minishell.h"

char	**get_path_arr(void);

// TODO: fix for comands inside quotes and spaces in its name, and for relative/absolute paths.
t_cmd	*get_t_cmd(char *str)
{
	t_cmd *cmd;
	cmd = malloc(sizeof(t_cmd));
	if (!cmd)
		return (cmd);
	cmd->cmd = str;
	cmd->executable = pipex_get_cmd_file(str, get_path_arr());
	cmd->args = pipex_get_cmd_args(str);

	return (cmd);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checking_setting.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angmarti <angmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 18:31:18 by angmarti          #+#    #+#             */
/*   Updated: 2023/06/14 23:35:40 by angmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/pipex.h"

/**
 * It checks if a command exists in the path
 * 
 * @param cmd the command to check
 * @param vars Variables of the program
 */
void	pipex_check_cmd(char *cmd, char *file)
{
	if (access(cmd, F_OK) == 0 && !file)
	{
		pipex_print_stderr("pipex: permission denied: ");
		pipex_print_stderr(cmd);
		pipex_print_stderr("\n");
	}
	else if (!file)
	{
		pipex_print_stderr("pipex: command not found: ");
		pipex_print_stderr(cmd);
		pipex_print_stderr("\n");
	}
	free(file);
}

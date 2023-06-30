/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angmarti <angmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 14:43:05 by angmarti          #+#    #+#             */
/*   Updated: 2023/06/30 14:51:19 by angmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/minishell.h"
#include "../../incs/pipex.h"


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

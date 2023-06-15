/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_main.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angmarti <angmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 14:43:05 by angmarti          #+#    #+#             */
/*   Updated: 2023/06/15 23:16:03 by angmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/pipex.h"

int main(int argc, char const **argv, char **envp)
{
	t_vars vars;
	char *cmds[] = {"ls", NULL};
	vars.cmds = cmds;
	vars.infile = NULL;
	vars.outfile = NULL;
	vars._envp = get_env_lst(argc, argv, envp);
	vars.here_doc = 0;
	vars.here_doc_limiters = NULL;
	vars.output_flag = O_TRUNC;
	pipex(&vars);
	return 0;
}

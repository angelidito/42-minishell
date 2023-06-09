/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_main.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angmarti <angmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 14:43:05 by angmarti          #+#    #+#             */
/*   Updated: 2023/07/13 15:46:01 by angmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/pipex.h"

int	main(int argc, char const **argv, char **envp)
{
	t_vars	vars;
	char	**cmds;
	int		i;

	cmds = ft_calloc(55, sizeof(char *));
	// cmds[i++] = ft_strdup("echo hola");
	i = 0;
	cmds[i++] = ft_strdup("env");
	cmds[i++] = ft_strdup("cat -b");
	cmds[i++] = ft_strdup("cat -b");
	cmds[i++] = 0;
	/* 	cmds[i++] = ft_strdup("wc");
	cmds[i++] = ft_strdup("  ls ");
	cmds[i++] = ft_strdup("echo HOLA QUE TAL");
	cmds[i++] = ft_strdup("cat ");
	cmds[i++] = ft_strdup("cat");
	cmds[i++] = ft_strdup("cat -be");
	cmds[i++] = ft_strdup("  pwd ");
	cmds[i++] = ft_strdup("ls -l");
	cmds[i++] = ft_strdup("echo xsdfsf sfds afa");
	cmds[i++] = 0; */
	vars.cmds = cmds;
	vars.infile = "special_cases.txt";
	vars.outfile = "out";
	vars.envp = get_env_lst(argc, argv, envp);
	vars.here_doc = 0;
	vars.here_doc_limiters = NULL;
	vars.output_flag = O_TRUNC;
	pipex(&vars); // Ehi! // ! EJECUTANDO PIPEX !!!
	i = 0;
	cmds[i++] = ft_strdup("env");
	cmds[i++] = 0;
	vars.outfile = "out2";
	pipex(&vars); // Ehi! // ! EJECUTANDO PIPEX !!!
	ft_printf("main end\n");
	free(cmds[1]);
	free(cmds[0]);
	return (0);
}

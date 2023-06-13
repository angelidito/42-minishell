/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_main.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angmarti <angmarti@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 14:43:05 by angmarti          #+#    #+#             */
/*   Updated: 2023/06/12 20:08:05 by angmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/pipex.h"

int	pipex(t_vars *vars)
{
	t_vars	vars;
	int		i;
	int		i;
	char	*tmp;

	// pipex_check_errors(argc, argv, envp, &vars);
	vars->here_doc = 0;
	// if (argc > 1)
	// 	if (ft_strlen(argv[1]) == 8 && ft_strncmp(argv[1], "here_doc", 8) == 0)
	// 		vars->here_doc = 1;
	// i = argc;
	// while (--i > 1)
	// {
	// 	tmp = ft_strtrim(argv[i], " \t\v\f\r");
	// 	if (!tmp || !*tmp)
	// 		pipex_pf_exit("Wrong arguments.", 1);
	// 	free(tmp);
	// }
	// if (argc < 5 + vars->here_doc)
	// {
	// 	ft_printf("Usage ->  %s infile cmd1 cmd2 [... cmdN] outfile\n",
	// 		argv[0]);
	// 	ft_printf("   or ->  %s here_doc LIMITER", argv[0]);
	// 	pipex_pf_exit(" cmd1 cmd2 [... cmdN] outfile", 1);
	// }
	i = 0;
	while (vars->_envp && vars->_envp[i] && ft_strncmp(vars->_envp[i], "PATH=", 5))
		i++;
	if (!vars->_envp || !vars->_envp[i])
		exit(0);
	// set_vars(argc, argv, vars->_envp, &vars);

	vars->path = pipex_get_path(vars->_envp);
	// if (vars->here_doc)
	// {
	// 	vars->infile = TEMP_HERE_DOC;
	// 	pipex_heredoc(argv[2], argc - 5);
	// }

	pipex_case_n_cmds(&vars, NULL, ft_strarrsize(vars->cmds));
	return (0);
}

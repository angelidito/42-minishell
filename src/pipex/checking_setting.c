/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checking_setting.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angmarti <angmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 18:31:18 by angmarti          #+#    #+#             */
/*   Updated: 2023/06/04 16:55:21 by angmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/pipex.h"

/**
 * It checks if a command exists in the path
 * 
 * @param cmd the command to check
 * @param path the path to the command
 */
void	check_cmd(char *cmd, char **path)
{
	char	*file;

	file = get_cmd_file(cmd, path);
	if (access(cmd, F_OK) == 0 && !file)
	{
		print_stderr("pipex: permission denied: ");
		print_stderr(cmd);
		print_stderr("\n");
	}
	else if (!file)
	{
		print_stderr("pipex: command not found: ");
		print_stderr(cmd);
		print_stderr("\n");
	}
	free(file);
}

/**
 * The function sets various variables based on 
 * the input arguments and environment variables
 * 
 * @param argc Number of arguments passed to the program
 * @param argv Arguments passed to the program
 * @param envp Environment variables
 * @param vars Variables used in the program.
 */
void	set_vars(int argc, char **argv, char **envp, t_vars *vars)
{
	int	i;

	vars->path = get_path(envp);
	vars->envp = envp;
	if (vars->here_doc)
	{
		vars->infile = TEMP_HERE_DOC;
		heredoc(argv[2], argc - 5);
	}
	else
		vars->infile = argv[1];
	vars->outfile = argv[argc - 1];
	vars->cmds = ft_calloc(argc - (2 + vars->here_doc), sizeof(char *));
	if (!vars->cmds)
		pf_exit("Malloc error", STDERR_FILENO);
	i = 1 + vars->here_doc;
	while (++i < argc - 1)
		vars->cmds[i - (2 + vars->here_doc)] = argv[i];
}

/**
 * It checks:
 * 		the number of arguments, 
 * 		and if the environment variables are set.
 * Also sets:
 * 		the vars path, 
 * 		infile, 
 * 		outfile, 
 * 		and cmds.
 * @param argc Number of arguments passed to the program
 * @param argv Arguments passed to the program
 * @param envp Environment variables
 * @param vars Variables used in the program.
 */
void	check_errors(int argc, char **argv, char **envp, t_vars *vars)
{
	int		i;
	char	*tmp;

	vars->here_doc = 0;
	if (argc > 1)
		if (ft_strlen(argv[1]) == 8 && ft_strncmp(argv[1], "here_doc", 8) == 0)
			vars->here_doc = 1;
	i = argc;
	while (--i > 1)
	{
		tmp = ft_strtrim(argv[i], " \t\v\f\r");
		if (!tmp || !*tmp)
			pf_exit("Wrong arguments.", 1);
		free(tmp);
	}
	if (argc < 5 + vars->here_doc)
	{
		ft_printf("Usage ->  %s infile cmd1 cmd2 [... cmdN] outfile\n", argv[0]);
		ft_printf("   or ->  %s here_doc LIMITER", argv[0]);
		pf_exit(" cmd1 cmd2 [... cmdN] outfile", 1);
	}
	i = 0;
	while (envp && envp[i] && ft_strncmp(envp[i], "PATH=", 5))
		i++;
	if (!envp || !envp[i])
		exit(0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nucieda- <nucieda-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 21:44:32 by nucieda-          #+#    #+#             */
/*   Updated: 2023/06/23 09:38:37 by nucieda-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/minishell.h"

// test with: ./script\ of\ four\ words arg1 "arg number 2" ' arg #3'  " arg 'number 4' this is \"bad\" ..."
// TODO: pipex_get_cmd_args gets properly the arguments, but not the command.
// TODO: ft_split_not_escaped gets properly the command, but not the arguments.

int	parse(char *str, t_list **env)
{
	t_vars	*vars;
	int		status;

	// printf("Parsing: %s\n", str);
	vars = get_t_vars(str, env);
	if (!vars)
	{
		printf("malloc error\n");
		return (-1);
	}
	status = execute_cmd(vars, env);
	return (status);
	// printf("status: %d\n", status);
}

int	prompt(t_list **env)
{
	char	*str;
	int		i;

	str = readline("minishell> ");
	i = -1;
	while (str[++i])
	{
		if (ft_isspace(str[i]))
			continue ;
		;
		add_history(str);
		break ;
	}
	if (!ft_strcmp(str, "exit"))
		return (1);
	parse(str, env);
	free(str);
	return (0);
}
/*
int	main(int argc, char const *argv[], char **envp)
{
	int	exit;

	t_list **env; // ? should this be a global variable?
	env = get_env_lst(argc, argv, envp);
	if (!env)
		return (1);
	// ft_lstiter(*env, lst_print_content);
	exit = 0;
	while (!exit)
	{
		exit = prompt(env);
	}
	printf("%sMinishell has finished%s\n", TEXT_BG_YELLOW, TEXT_RESET);
	return (0);
}
*/
int	main(int argc, char const *argv[], char **envp)
{
	int			exit;
	t_mini_vars	*vars;
	t_list 		**env; // ? should this be a global variable? | Nah
	char		*str;
	
	env = get_env_lst(argc, argv, envp);
	if (!env)
		return (1);
	// ft_lstiter(*env, lst_print_content);
	while (1)
	{
		str = readline("Minishell> ");
		vars = get_t_vars(str, env);
		for (int i = 0; vars->cmds[i]; i++)
			printf("%s | ");
		printf("\n");
		printf("infile: %s\n", vars->infile);
		printf("outfile: %s\n", vars->outfile);
		printf("heredoc: %d\n", vars->here_doc);
		printf("\n");
	}
	
	printf("%sMinishell has finished%s\n", TEXT_BG_YELLOW, TEXT_RESET);
	return (0);
}
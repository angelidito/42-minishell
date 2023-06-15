/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angmarti <angmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 21:44:32 by nucieda-          #+#    #+#             */
/*   Updated: 2023/06/14 22:40:19 by angmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/minishell.h"

// test with: ./"script of four words" arg1 "arg number 2" ' arg #3'  " arg 'number 4' this is \"bad\" ..."
int	parse(char *str, t_list **env)
{
	t_cmd	*cmd;
	int		status;

	cmd = get_t_cmd(str, env);
	if (!cmd)
	{
		printf("malloc error\n");
		return (-1);
	}
	status = execute_cmd(cmd, env);
	return (status);
}

void	lst_print_content(void *content)
{
	ft_printf("%s\n", (char *)content);
}

int	prompt(t_list **env)
{
	char	*str;
	int		i;

	str = readline("(>'-')> ");
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
/**
 * Creates a Minishell.
 * 
 * @param argc Number of arguments passed to the minishell. It should be:
 * one (1), if it was called from the terminal;
 * and more, if it was called from another minishell.
 * @param argv If argc >= 2, argv is used as the list of environment variables.
 * @param envp If argc == 1, envp is used as the list of environment variables.
 * 
 * @return The main function is returning an integer value, which is 0 if the program runs successfully
 * and 1 if there is an error.
 */
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

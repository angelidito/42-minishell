/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angmarti <angmarti@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 21:44:32 by nucieda-          #+#    #+#             */
/*   Updated: 2023/06/09 18:10:09 by angmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/minishell.h"

t_cmd	*get_t_cmd(char *str);

// test with: ./script\ of\ four\ words arg1 "arg number 2" ' arg #3'  " arg 'number 4' this is \"bad\" ..."
// TODO: pipex_get_cmd_args gets properly the arguments, but not the command.
// TODO: ft_split_not_escaped gets properly the command, but not the arguments.

void	parse(char *str)
{
	t_cmd	*cmd;

	printf("Parsing: %s\n", str);
	cmd = get_t_cmd(str);
	if (!cmd)
	{
		printf("malloc error\n");
		return ;
	}
	printf("cmd: %s\n", cmd->cmd);
	printf("executable: %s\n", cmd->executable);
	if (cmd->args)
	{
		ft_print_strarr_op(cmd->args, 2, TEXT_BG_BLUE, TEXT_RESET, "cmd->args");
		ft_freestrarr(cmd->args);
	}
	if (cmd->executable)
		free(cmd->executable);
	free(cmd);
	// char	**tokens;
	// printf("\n%spipex_get_cmd_args%s\n", TEXT_RED, TEXT_RESET);
	// tokens = pipex_get_cmd_args(str);
	// i = 0;
	// while (tokens[i])
	// {
	// 	printf("%s%s%s\n", TEXT_BG_CYAN, tokens[i], TEXT_RESET);
	// 	i++;
	// }
	// ft_freestrarr(tokens);
	// printf("\n%sft_split_not_escaped%s\n", TEXT_RED, TEXT_RESET);
	// tokens = ft_split_not_escaped(str, ' ');
	// i = 0;
	// while (tokens[i])
	// {
	// 	printf("%s%s%s\n", TEXT_BG_CYAN, tokens[i], TEXT_RESET);
	// 	i++;
	// }
}



void	lst_print_content(void *content)
{
	ft_printf("node content: %s\n", (char *)content);
}

int	main(int argc, char const *argv[], char **envp)
{
	char	*str;
	int		exit;
	t_list	**env; // ? should this be a global variable?

	env = get_env_lst(argc, argv, envp);
	if (!env)
	return (1);
	ft_lstiter(*env, lst_print_content);
	exit = 0;
	while (!exit)
	{
		str = readline("minishell> ");
		parse(str);
		add_history(str);
		if (!ft_strcmp(str, "exit"))
			exit = 1;
		free(str);
	}
	printf("%sMinishell has finished\n", TEXT_BG_YELLOW);
	return (0);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angmarti <angmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 21:44:32 by nucieda-          #+#    #+#             */
/*   Updated: 2023/06/03 21:51:37 by angmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/minishell.h"

// test with: ./script\ of\ four\ words arg1 "arg number 2" ' arg #3'  " arg 'number 4' this is \"bad\" ..."
// TODO: get_cmd_args gets properly the arguments, but not the command.
// TODO: ft_split_not_escaped gets properly the command, but not the arguments.
void	parse(char *str)
{
	char	**tokens;
	int		i;

	printf("\n%sget_cmd_args%s\n", TEXT_RED, TEXT_RESET);
	tokens = get_cmd_args(str);
	i = 0;
	while (tokens[i])
	{
		printf("%s%s%s\n", TEXT_BG_CYAN, tokens[i], TEXT_RESET);
		i++;
	}
	ft_freechararr(tokens);
	printf("\n%sft_split_not_escaped%s\n", TEXT_RED, TEXT_RESET);
	tokens = ft_split_not_escaped(str, ' ');
	i = 0;
	while (tokens[i])
	{
		printf("%s%s%s\n", TEXT_BG_CYAN, tokens[i], TEXT_RESET);
		i++;
	}
}

int	main(void)
{
	char	*str;

	while (ft_strcmp(str, "exit"))
	{
		str = readline("minishell> ");
		add_history(str);
		parse(str);
		free(str);
	}
	return (0);
}

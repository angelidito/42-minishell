/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angmarti <angmarti@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 11:30:24 by angmarti          #+#    #+#             */
/*   Updated: 2023/06/09 18:12:53 by angmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/minishell.h"

/**
 * TODO: MUST receive the char **envp and not use getenv() because it wont work
 * properly if a minisheel is executed inside another minishell.
 *
 * @param envp
 * @return char**
 */
char	**get_path_arr(void)
{
	char	**path_arr;

	path_arr = ft_split(getenv("PATH"), ':');
	return (path_arr);
}

char *my_getenv(const char *name, t_list **env)
{
	t_list	*node;

	node = *env;
	while (node)
	{
		if (ft_strncmp(node->content, name, ft_strlen(name)) == 0)
			return (node->content + ft_strlen(name) + 1);
		node = node->next;
	}
	return (NULL);
}

/**
 * Creates a linked list of environment variables from the command line
 * arguments or the environment variables passed to the program.
 *
 *  \br
 * ? Why this function is needed?
 * ? Because the minishell can call itself recursively, and the environment
 * ? variables should be the same that in the parent process, not the
 * ? environment vars of the terminal where the fist minishell was executed.
 *
 * @param argc
 * @param argv
 * @param envp
 *
 * @return List of environment variables.
 */
t_list	**get_env_lst(int argc, char const *argv[], char **envp)
{
	int		i;
	t_list	**env;
	char	**aux;

	env = ft_calloc(1, sizeof(t_list *));
	if (!env)
		return (NULL);
	if (argc > 1)
		aux = (char **)argv;
	else
		aux = envp;
	i = -1;
	while (aux[++i])
		ft_lstadd_back(env, ft_lstnew(ft_strdup(aux[i])));
	return (env);
}

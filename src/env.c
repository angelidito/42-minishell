/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angmarti <angmarti@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 11:30:24 by angmarti          #+#    #+#             */
/*   Updated: 2023/06/10 14:35:08 by angmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/minishell.h"



/**
 * Obtains the current value of the environment variable required.
 * Do NOT modify the string returned by this function.
 *
 * @param name Name of the environment variable.
 * @param env List of environment variables.
 *
 * @return The value of the environment variable as a NULL-terminated string.
 * If the variable name is not in the current environment, NULL is returned.
 */
char	*my_getenv(const char *name, t_list **env)
{
	int		len;
	char	*var;
	t_list	*node;

	node = *env;
	while (node)
	{
		var = node->content;
		len = ft_strlen(name);
		if (ft_strncmp(name, var, len) == 0 && var[len] == '=')
			return (var + len + 1);
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

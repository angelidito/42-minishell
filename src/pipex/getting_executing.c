/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getting_executing.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angmarti <angmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 14:44:42 by angmarti          #+#    #+#             */
/*   Updated: 2023/06/15 17:01:13 by angmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/pipex.h"

char	*pipex_find_file(char **words, t_vars *vars)
{
	char	*file;
	int		i;
	char	*aux;
	char	**path;
	int		path_size;

	i = -1;
	path = ft_split(my_getenv("PATH", vars->_envp), ':');
	// TODO: my_getenv hace leak siempre al juntar con split
	path_size = ft_strarrsize(path);
	while (++i < path_size)
	{
		aux = ft_strjoin("/", words[0]);
		file = ft_strjoin(path[i], aux);
		free(aux);
		if (access(file, X_OK) == 0)
			break ;
		free(file);
	}
	ft_freestrarr(path);
	return (file);
}

/**
 * It takes a command and a path, and returns the path to the command
 * 
 * @param cmd the command to be executed
 * @param vars Variables of the program
 * 
 * @return The path of the command.
 */
char	*pipex_get_cmd_file(char *cmd, t_vars *vars)
{
	char	**words;
	char	*file;

	if (!cmd)
		return (NULL);
	// cmd = str_remove_escapes(cmd);
	if ((*cmd == '/' || (*cmd == '.' && cmd[1] == '/')) && access(cmd,
			X_OK) == 0)
		return ((char *)cmd);
	words = ft_split(cmd, ' ');
	file = pipex_find_file(words, vars);
	ft_freestrarr(words);
	return (file);
}

/**
 * It takes a command, a path variable and an environment variable, 
 * and returns an array of strings with the command and its arguments
 * 
 * @param cmd the command to be executed.
 * @param envp is the environment variables.
 * 
 * @return The array of arguments.
 */
void	pipex_exec_cmd(t_cmd *cmd, char *envp[])
{
	execve(cmd->file, cmd->args, envp);
	exit(127);
}

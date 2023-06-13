/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getting_executing.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angmarti <angmarti@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 14:44:42 by angmarti          #+#    #+#             */
/*   Updated: 2023/06/10 14:56:58 by angmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/pipex.h"

char	*pipex_find_file(char **words, char **path)
{
	char	*file;
	int		i;
	char	*aux;

	i = -1;
	file = NULL;
	while (++i < 6)
	{
		aux = ft_strjoin("/", words[0]);
		file = ft_strjoin(path[i], aux);
		free(aux);
		if (access(file, X_OK) == 0)
			break ;
		free(file);
		file = NULL;
	}
	return (file);
}

/**
 * It takes a command and a path, and returns the path to the command
 * 
 * @param cmd the command to be executed
 * @param path The path to the command.
 * 
 * @return The path of the command.
 */
char	*pipex_get_cmd_file(char *cmd, char **path)
{
	char	**words;
	char	*file;

	if (!cmd)
		return (NULL);
	cmd = str_remove_escapes(cmd);
	if ((*cmd == '/' || (*cmd == '.' && cmd[1] == '/')) && access(cmd,
			X_OK) == 0)
		return ((char *)cmd);
	words = ft_split_not_escaped(cmd, ' ');
	file = pipex_find_file(words, path);
	free(cmd);
	ft_freestrarr(words);
	return (file);
}

/**
 * It takes an environment variable array and returns an array of strings 
 * containing the paths in the PATH environment variable
 * 
 * @param envp The environment variables.
 * 
 * @return the path of the environment variable.
 */
char	**pipex_get_path(char *envp[])
{
	int	i;

	i = 0;
	while (envp && envp[i] && ft_strncmp(envp[i], "PATH=", 5))
		i++;
	return (ft_split(envp[i] + 5, ':'));
}

/**
 * It takes a command, a path variable and an environment variable, 
 * and returns an array of strings with the command and its arguments
 * 
 * @param cmd the command to be executed.
 * @param path the PATH variable, split by ':'
 * @param envp is the environment variables.
 * 
 * @return The array of arguments.
 */
void	pipex_exec_cmd(char *cmd, char **path, char *envp[])
{
	char	**args;
	char	*file;

	args = pipex_get_cmd_args(cmd);
	file = pipex_get_cmd_file(cmd, path);
	execve(file, args, envp);
	exit(127);
}

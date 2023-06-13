/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getting_executing.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angmarti <angmarti@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 14:44:42 by angmarti          #+#    #+#             */
/*   Updated: 2023/06/12 18:56:14 by angmarti         ###   ########.fr       */
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
/**
 * The function takes a command and a path, finds the corresponding executable file, and returns its
 * path.
 * 
 * @param cmd The command string that needs to be executed.
 * @param path The `path` parameter is a pointer to a null-terminated array of strings, where each
 * string represents a directory path. This array is used to search for the executable file specified
 * in the `cmd` parameter.
 * 
 * @return The function `pipex_get_cmd_file` returns a `char` pointer that points to the path of the
 * executable file corresponding to the command passed as an argument. If the command is a valid path
 * to an executable file, it returns the same path. If the command is not a valid path, it searches for
 * the executable file in the directories specified in the `path` array and returns the path
 */
char	*pipex_get_cmd_file(char *cmd, char **path)
{
	char	**words;
	char	*file;

	if (!cmd)
		return (NULL);
	// cmd = str_remove_escapes(cmd);
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

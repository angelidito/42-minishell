/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angmarti <angmarti@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 10:21:15 by angmarti          #+#    #+#             */
/*   Updated: 2023/06/10 16:11:59 by angmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/minishell.h"

char	*find_file(char **words, char **path)
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
char	*get_cmd_file(char *cmd, char **path)
{
	char	**words;
	char	*file;

	if (!cmd)
		return (NULL);
	cmd = str_remove_escapes(cmd);
	if (cmd[0] == '/' || (cmd[0] == '.' && cmd[1] == '/'))
	{
		if (access(cmd, F_OK) == 0)
			return ((char *)cmd);
		else
			return (NULL);
	}
	words = ft_split_not_escaped(cmd, ' ');
	file = find_file(words, path);
	free(cmd);
	ft_freestrarr(words);
	return (file);
}

// TODO: fix for comands inside quotes and spaces in its name,
// and for relative/absolute paths.
t_cmd	*get_t_cmd(char *str, t_list **env)
{
	t_cmd	*cmd;

	cmd = malloc(sizeof(t_cmd));
	if (!cmd)
		return (cmd);
	cmd->cmd = str;
	cmd->args = pipex_get_cmd_args(str);
	cmd->file = get_cmd_file(*cmd->args, ft_split(my_getenv("PATH", env), ':'));
	cmd->file_x_access = 1;
	if (cmd->file && access(cmd->file, X_OK) != 0)
		cmd->file_x_access = 0;
	printf("cmd: %s%s%s\n", TEXT_BG_GREEN, cmd->cmd, TEXT_RESET);
	printf("file: %s%s%s\n", TEXT_BG_MAGENTA, cmd->file, TEXT_RESET);
	printf("file_x_access: %s%d%s\n", TEXT_BG_CYAN, cmd->file_x_access, TEXT_RESET);
	ft_print_strarr_op(cmd->args, 2, TEXT_BG_BLUE, TEXT_RESET, "cmd->args");
	return (cmd);
}

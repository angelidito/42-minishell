
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

char	*get_next_element(char *str)
{
	char	quotes;
	char	*element;
	int		i;

	quotes = ' ';
	i = 0;
	if (str[i] == '\"' || str[i] == '\'')
	{
		quotes = str[i];
		str++;
	}
	while (str[i] && str[i] != quotes)
		i++;
	element = malloc((i * sizeof(char)) + 1);
	ft_strlcpy(element, str, i + 1);
	return (element);
}

char	*get_infile(char *str)
{
	char	*infile;
	int		i;

	infile = NULL;
	i = 0;
	while (str[i] && !infile)
	{
		if (str[i] == '<')
		{
			if (str[i + 1] == '<')
			{
				if (ft_strchr("!#&(<>`", str[i + 2]))
				{
					// Syntax Error
					return (NULL);
				}
				else
				{
					// infile = heredoc
					return (NULL);
				}
			}
			else
			{
				infile = get_next_element(str + 1);
			}
		}
		i++;
	}
	if (!infile)
		return (STDIN_FILENO);
	return (infile);
}

char	*get_outfile(char *str)
{
	char	*outfile;
	int		i;

	outfile = NULL;
	i = 0;
	while (str[i] && !outfile)
	{
		if (str[i] == '>')
		{
			if (str[i + 1] == '>')
			{
				if (ft_strchr("!#&(<>`", str[i + 2]))
				{
					// Syntax Error
					return (NULL);
				}
				else
				{
					// outfile = append
					return (NULL);
				}
			}
			else
			{
				outfile = get_next_element(str + 1);
			}
		}
		i++;
	}
	if (!outfile)
		return (STDOUT_FILENO);
	return (outfile);
}

int	get_here_doc(char *str)
{
	if (ft_strnstr(str, "<<", ft_strlen(str)))
		return (1);
	return (0);
}

int	get_output_flag(char *str)
{
	// Literal no me acuerdo de que era esto
	// TODO
	return (0);
}

/**
 * Creates and returns a `t_cmd` struct with information about a command,
 * including its arguments and file path.
 *
 *  TODO: fix for script names inside quotes, and for relative/absolute paths.
 *
 * @param str The command string that needs to be parsed and executed.
 * @param env Linked list with the environment variables
 *
 * @return A `t_cmd` structure.
 */
t_mini_vars	*get_t_mini_vars(char *str, t_list **env)
{
	t_mini_vars	*vars;

	vars = malloc(sizeof(t_mini_vars));
	if (!vars)
		return (NULL);
	vars->env = env;
	vars->cmds = ft_split(str, '|');
	vars->infile = get_infile(str);
	vars->outfile = get_outfile(str);
	vars->here_doc = get_here_doc(str);
	vars->output_flag = get_output_flag(str);


	/*
	cmd->cmd = str;
	cmd->args = pipex_get_cmd_args(str);
	cmd->built_in = check_builtins(str);
	cmd->file = get_cmd_file(*cmd->args, ft_split(my_getenv("PATH", env), ':'));
	cmd->file_x_access = 1;
	if (!cmd->file || access(cmd->file, X_OK) != 0)
		cmd->file_x_access = 0;
	*/
	// printf("cmd: %s%s%s\n", TEXT_BG_GREEN, cmd->cmd, TEXT_RESET);
	// printf("file: %s%s%s\n", TEXT_BG_MAGENTA, cmd->file, TEXT_RESET);
	// printf("file_x_access: %s%d%s\n", TEXT_BG_CYAN, cmd->file_x_access,
	// TEXT_RESET);
	// ft_print_strarr_op(cmd->args, 2, TEXT_BG_BLUE, TEXT_RESET, "cmd->args");
	return (vars);
}

/**
 * Executes a command
 *
 * @param cmd The command to be executed.
 * @param env Linked list with the environment variables
 *
 * @return The exit status of the command.
 */
int	execute_cmd(t_cmd *cmd, t_list **env)
{
	int		pid;
	int		status;

	status = 0;
	if (!cmd->file)
	{
		print_stderr("minishell: command not found: ");
		print_stderr(cmd->cmd);
		print_stderr("\n");
		return (127);
	}
	else if (cmd->file_x_access == 0)
	{
		print_stderr("minishell: permission denied: ");
		print_stderr(cmd->cmd);
		print_stderr("\n");
		return (127);
	}
	pid = fork();
	if (pid == 0)
	{
		if (execve(cmd->file, cmd->args, lst_to_arr(env)) == -1)
			ft_printf("minishell: %s: %s\n", cmd->cmd, strerror(errno));
		exit(1);
	}
	else if (pid < 0)
		ft_printf("minishell: %s: %s\n", cmd->cmd, strerror(errno));
	else
	{
		waitpid(pid, &status, 0);
	}
	return (status);
}

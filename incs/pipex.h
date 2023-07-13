/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angmarti <angmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 14:44:24 by angmarti          #+#    #+#             */
/*   Updated: 2023/06/30 15:00:03 by angmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H
# define _GNU_SOURCE
# include "../libs/mylibft/incs/libft.h"
# include "colors.h"
# include "minishell.h"
# include "pipex_structs.h"
# include "minishell_structs.h"
# include <fcntl.h> /* Open function */
# include <time.h>

# ifndef TEMP_HERE_DOC
#  define TEMP_HERE_DOC "/tmp/pipex_here_doc"
# endif

// BACKSLASHES

// void	remove_escapes(t_list **lst);
// char	*str_remove_escapes(char *str);

//	CASE _N_ CMDS

void	pipex_case_1_cmd(t_vars *vars);
void	pipex_case_n_cmds(t_vars *vars, int *prev_fd, int n_comands);
void	n_child(t_vars *vars, int *pipe_fd);
void	n_child_builtin(t_vars *vars, int *pipe_fd);
void	n_parent(t_vars *vars, int *pipe_fd, int fd_out, int cmd);
void	n_parent_builtin(t_vars *vars, int *pipe_fd, int fd_out, int cmd);

//	CHECKING_SETTING

void	pipex_check_cmd(char *cmd, char *file);
void	pipex_check_errors(int argc, char **argv, char **envp, t_vars *vars);
void	set_vars(int argc, char **argv, char **envp, t_vars *vars);

// CMD

t_cmd	*get_t_cmd(t_vars *vars, int cmd);
void	free_t_cmd(t_cmd *command);

//	ERRORS

void	pipex_my_perror(char *s);
void	pipex_print_stderr(char *str);
void	pipex_pf_exit(char *s, int fd);

//	GET COMAND ARGUMENTS

char	**pipex_get_cmd_args(char const *cmd);

//	GETTING_EXECUTING

void	pipex_exec_cmd(t_cmd *cmd, char *envp[]);
char	*pipex_get_cmd_file(char *cmd, char **path);
char	**pipex_get_path(char *envp[]);

// HERE_DOC

void	pipex_heredoc(char *limiter, int n_comands);
void	heredoc(char *limiter);

// OPEN

int		open_in(char *infile, int flags);
int		open_out(char *outfile, int flags, int mode, int pid);

//	BUILT-IN

int		is_builtin(t_vars *vars, int n);
void	exec_builtin(t_vars *vars, int cmd);

#endif

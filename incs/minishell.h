

#ifndef MINISHELL_H
# define MINISHELL_H
# include "../libs/mylibft/incs/libft.h"
# include "colors.h"
# include "minishell_structs.h"
# include "pipex_structs.h"
// # include "pipex.h"
# include <curses.h>            // tgetent, tgetflag, tgetnum, tgetstr, tgoto,
								// tputs
# include <dirent.h>            // opendir, readdir, closedir
# include <errno.h>             // perror
# include <fcntl.h>             // open
# include <readline/history.h>  // add_history
# include <readline/readline.h> // readline, rl_clear_history, rl_on_new_line,
								// rl_replace_line, rl_redisplay
# include <signal.h>            // sigaction, sigemptyset, sigaddset, kill
# include <stdio.h>             // printf
# include <stdlib.h>            // malloc, free, exit
# include <string.h>            // strerror
# include <sys/stat.h>          // stat, lstat, fstat
# include <sys/types.h>         // wait, waitpid, wait3, wait4, signal, getpid,
# include <sys/wait.h>			// getppid

# include <termios.h>           // isatty, tcsetattr, tcgetattr
# include <unistd.h>            // write, access, fork, execve, close, pipe,
								// dup, dup2, getpid, getppid, getcwd, chdir

// ENV

char	*my_getenv(const char *name, t_list **env);

t_list	**get_env_lst(int argc, char const *argv[], char **envp);

// CMD

int		execute_cmd(t_cmd *cmd, t_list **env);

t_mini_vars	*get_t_vars(char *str, t_list **env); // TODO: borrar? No exite esta funcion

// UTILS

char	**lst_to_arr(t_list **lst);
void	print_stderr(char *str);
void	put_str_fd_exit(char *s, int fd);

char	*get_next_element(char *str);
char	*get_infile(char *str);
char	*get_outfile(char *str);
int		get_here_doc(char *str);


// BUILT-INS

int		check_builtins(char *str);
void	ft_env(t_list **env);
void    ft_pwd(t_list **env);
void    ft_echo(t_cmd *cmd);

// PIPEX

int		pipex(t_vars *vars);
t_cmd	*get_t_cmd(t_vars *vars, int cmd);
void	free_t_cmd(t_cmd *command);


#endif

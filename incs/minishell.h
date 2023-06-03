/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angmarti <angmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/03 01:29:25 by angmarti          #+#    #+#             */
/*   Updated: 2023/06/03 01:30:26 by angmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef MINISHELL_H
# define MINISHELL_H
# include "../libs/mylibft/incs/libft.h"
# include "colors.h"
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
								// getppid
# include <termios.h>           // isatty, tcsetattr, tcgetattr
# include <unistd.h>            // write, access, fork, execve, close, pipe,
								//  dup, dup2, getpid, getppid, getcwd, chdir

#endif

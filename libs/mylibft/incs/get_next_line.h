/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nucieda- <nucieda-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 17:04:29 by angmarti          #+#    #+#             */
/*   Updated: 2023/06/12 16:57:21 by nucieda-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <fcntl.h> 	/* Open function */
# include <limits.h>	/* Macro defined OPEN_MAX */
# include <stdio.h>		/* BUFSIZ definition*/
# include <stdlib.h>	/* Malloc & Free functions */
# include <unistd.h> 	/* Write & Read functions */
# include <stdint.h>
// # include "libft.h"

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE BUFSIZ
# endif

# if BUFFER_SIZE > 9223372036854775806L /*Double long*/
#  undef BUFFER_SIZE
#  define BUFFER_SIZE 0
# endif

char	*get_next_line(int fd);
char	*gnl_cut_myline(char *myline);
char	*gnl_get_line2return(char *myline);
char	*gnl_read_and_add(int fd, char *myline);

//Utils
size_t	gnl_strlen(const char *s);

char	*gnl_strchr(const char *s, int c);
char	*gnl_strjoin(char *myline, char *buffer);

void	*gnl_calloc(size_t count, size_t size);

#endif

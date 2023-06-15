/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angmarti <angmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 19:44:51 by angmarti          #+#    #+#             */
/*   Updated: 2023/06/14 22:18:15 by angmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/pipex.h"

/**
 * Reads input from the user until a specified delimiter is reached and writes 
 * it to a temporary file.
 * 
 * @param limiterString that specifies the delimiter for the here-document.
 */
void	heredoc(char *limiter)
{
	int		fd;
	int		lim_len;
	int		l_len;
	char	*l;
	fd = open(TEMP_HERE_DOC, O_CREAT | O_RDWR | O_TRUNC, 0644);
	if (fd == -1)
		pipex_pf_exit("Error opening file", 1);
	lim_len = ft_strlen(limiter);
	ft_putstr_fd("> ", STDOUT_FILENO);
	l = get_next_line(STDIN_FILENO);
	l_len = ft_strlen(l) - 1;
	while (l_len != lim_len || ft_strncmp(l, limiter, ft_strlen(limiter)))
	{
		ft_putstr_fd(l, fd);
		free(l);
		ft_putstr_fd("> ", STDOUT_FILENO);
		l = get_next_line(STDIN_FILENO);
		l_len = ft_strlen(l) - 1;
	}
	close(fd);
}

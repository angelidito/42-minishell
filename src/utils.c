/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angmarti <angmarti@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 14:05:54 by angmarti          #+#    #+#             */
/*   Updated: 2023/06/11 16:07:24 by angmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/minishell.h"

/**
 * Converts a linked list of strings into an array of strings.
 *
 * @param lst Linked list of strings.
 *
 * @return An array of strings that is NULL-terminated. NULL if malloc fails.
 */
char	**lst_to_arr(t_list **lst)
{
	char	**arr;
	t_list	*node;
	int		i;
	int		size;

	size = ft_lstsize(*lst);
	arr = ft_calloc(size + 1, sizeof(char *));
	if (!arr)
		return (NULL);
	node = *lst;
	i = 0;
	while (i < size)
	{
		arr[i] = (char *)node->content;
		i++;
		node = node->next;
	}
	return (arr);
}

/**
 * Prints a given string to the standard error output in red color.
 * 
 * @param str String to be printed to stderr.
 */
void	print_stderr(char *str)
{
	ft_putstr_fd(TEXT_RED, STDERR_FILENO);
	ft_putstr_fd(str, STDERR_FILENO);
	ft_putstr_fd(TEXT_RESET, STDERR_FILENO);
}

/**
 * Prints a given string exits the program with a failure status.
 * 
 * @param s the error message to be printed
 */
void	put_str_fd_exit(char *s, int fd)
{
	if (fd == STDERR_FILENO)
	{
		print_stderr(s);
		print_stderr("\n");
	}
	else
	{
		ft_putstr_fd(s, fd);
		ft_putstr_fd("\n", fd);
	}
	exit(EXIT_FAILURE);
}

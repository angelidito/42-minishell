/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_strarr.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angmarti <angmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/04 17:09:29 by angmarti          #+#    #+#             */
/*   Updated: 2023/06/04 17:31:46 by angmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/libft.h"

/**
 * Prints each string in a char array with a given prefix and suffix followed by
 * a newline. If the array is NULL, it prints (null) instead.
 * Also prints a title before the array if it is set. 
 * 
 * @param arr String array.
 * @param list If 1, prints a dash list. If 2, it prints a indexed list.
 * @param prefix Sstring to print before each element of the array.
 * @param suffix String to print after each element of the array.
 * @param title String to print before the array.
 */
void	ft_print_strarr_op(char **arr, int list, char *prefix, char *suffix,
		char *title)
{
	int	i;

	if (title)
	{
		ft_putstr_fd(title, STDOUT_FILENO);
		ft_putstr_fd(":\n", STDOUT_FILENO);
	}
	i = -1;
	while (arr[++i])
	{
		if (list == 1)
			ft_putstr_fd(" - ", STDOUT_FILENO);
		else if (list == 2)
		{
			ft_putstr_fd(" ", STDOUT_FILENO);
			ft_putnbr_fd(i + 1, STDOUT_FILENO);
			ft_putstr_fd(". ", STDOUT_FILENO);
		}
		if (prefix)
			ft_putstr_fd(prefix, STDOUT_FILENO);
		ft_putstr_fd(arr[i], STDOUT_FILENO);
		if (suffix)
			ft_putstr_fd(suffix, STDOUT_FILENO);
		ft_putstr_fd("\n", STDOUT_FILENO);
	}
}

/**
 * The function prints a string array with a newline character as the separator.
 * 
 * @param arr a pointer to a pointer of characters,
	representing an array of strings.
 */
void	ft_print_strarr(char **arr)
{
	ft_print_strarr_op(arr, 0, "", "", NULL);
}

/**
 * It returns the number of elements in a char **
 * 
 * @param strarr The array of strings to be counted.
 * 
 * @return The number of elements in the array.
 */
int	ft_strarrsize(char **strarr)
{
	int	i;

	i = 0;
	while (strarr[i])
		i++;
	return (i);
}

/**
 * It frees an array of strings.
 * 
 * @param strarr The array of strings to be freed.
 */
void	ft_freestrarr(char **strarr)
{
	int	i;

	i = -1;
	while (strarr[++i])
		free(strarr[i]);
	free(strarr);
}

/**
 * It frees the strings from start to end position.
 * 
 * 
 * @param strarr The array of strings to be freed.
 * @param start The start position.
 * @param end The end position.
 */
void	ft_freestrarr_op(char **strarr, int start, int end)
{
	int i;

	i = start - 1;
	while (++i < end)
		free(strarr[i]);
	free(strarr);
}
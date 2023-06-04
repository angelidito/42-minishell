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
 * @param prefix Sstring to print before each element of the array.
 * @param suffix String to print after each element of the array.
 * @param title String to print before the array.
 */
void	ft_print_strarr_op(char **arr, char *prefix, char *suffix, char *title)
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
		ft_putstr_fd(prefix, STDOUT_FILENO);
		ft_putstr_fd(arr[i], STDOUT_FILENO);
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
	ft_print_strarr_op(arr, "", "\n", NULL);
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
	int i;

	i = -1;
	while (strarr[++i])
		free(strarr[i]);
	free(strarr);
}
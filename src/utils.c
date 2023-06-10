/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angmarti <angmarti@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 14:05:54 by angmarti          #+#    #+#             */
/*   Updated: 2023/06/10 14:10:39 by angmarti         ###   ########.fr       */
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

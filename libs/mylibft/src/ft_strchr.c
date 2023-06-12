/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angmarti <angmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 13:00:37 by angmarti          #+#    #+#             */
/*   Updated: 2023/06/03 21:11:45 by angmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/libft.h"

/**
 * Search for the first occurrence of the character c a string s and returns
 * a pointer to it, or NULL if the character is not found.
 * 
 * @param s The string to search in.
 * @param c The character to search for.
 * 
 * @return A pointer to the first occurrence of the character c.
 * NULL if the character is not found.
 */
char	*ft_strchr(const char *s, int c)
{
	unsigned long	i;

	i = 0;
	while (*(s + i))
	{
		if ((c % 256) == *(s + i))
			break ;
		i++;
	}
	if ((c % 256) == *(s + i))
		return ((char *)(s + i));
	return (NULL);
}

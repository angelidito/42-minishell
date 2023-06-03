/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_replace_dup_whitespaces.c                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angmarti <angmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 17:55:22 by angmarti          #+#    #+#             */
/*   Updated: 2023/06/03 01:23:46 by angmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/libft.h"

int	result_len(const char *str)
{
	size_t	i;
	int		j;
	int		prev_was_whitespace;

	i = -1;
	j = 0;
	prev_was_whitespace = 0;
	while (str[++i])
	{
		if (ft_isspace(str[i]))
		{
			if (!prev_was_whitespace)
			{
				j++;
				prev_was_whitespace = 1;
			}
		}
		else
		{
			j++;
			prev_was_whitespace = 0;
		}
	}
	return (j);
}

/**
 * Replaces consecutive whitespace characters with a single specified character
 * and returns a new string.
 * 
 * @param str The string to be processed.
 * @param c The character to replace the whitespaces with.
 * 
 * @return A newly allocated string
 */
char	*ft_str_replace_dup_whitespaces(const char *str, char c)
{
	char	*result;
	int		prev_was_whitespace;
	size_t	i;
	int		j;

	result = ft_calloc(result_len(str) + 1, sizeof(char));
	j = 0;
	i = -1;
	prev_was_whitespace = 0;
	while (str[++i])
	{
		if (ft_isspace(str[i]) && !prev_was_whitespace)
		{
			result[j++] = c;
			prev_was_whitespace = 1;
		}
		else if (!ft_isspace(str[i]))
		{
			result[j++] = str[i];
			prev_was_whitespace = 0;
		}
	}
	return (result);
}

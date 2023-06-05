/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angmarti <angmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 13:23:27 by angmarti          #+#    #+#             */
/*   Updated: 2023/06/05 11:11:59 by angmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/libft.h"

/**
 * It takes two strings, concatenates them, and returns the result
 * 
 * @param s1 The first string to be joined.
 * @param s2 The string to be appended to the end of s1.
 * 
 * @return A pointer to the first character of the string.
 */
char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*dst;
	size_t	dstsize;

	if (!s1)
		return (NULL);
	dstsize = ft_strlen(s1) + ft_strlen(s2) + 1;
	dst = malloc(dstsize * sizeof(char));
	if (!dst)
		return (NULL);
	ft_strlcpy(dst, s1, dstsize);
	ft_strlcat(dst, s2, dstsize);
	return (dst);
}

/**
 * It joins two strings and frees the memory of the two strings.
 * 
 * @param s1 The first string to be joined.
 * @param s2 the string to be appended to s1
 * 
 * @return A pointer to the newly allocated string.
 */
char	*ft_strjoin_n_free(const char *s1, const char *s2)
{
	char	*result;

	if (!s1)
		return (NULL);
	if (!s2)
	{
		result = ft_strjoin(s1, "");
		free((char *)s1);
		return (result);
	}
	result = ft_strjoin(s1, s2);
	free((char *)s1);
	free((char *)s2);
	return (result);
}

/**
 * It joins two strings and frees the memory of the strings if the flag is set.
 * 
 * @param s1 The first string to join.
 * @param s2 The string to be appended to s1.
 * @param f1 if not 0, free s1
 * @param f2 if not 0, free s2
 * 
 * @return A pointer to a string, NULL if it fails.
 */
char	*ft_strjoin_n_free_op(const char *s1, const char *s2, int f1, int f2)
{
	char	*result;

	if (!s1)
		return (NULL);
	if (!s2)
	{
		result = ft_strjoin(s1, "");
		free((char *)s1);
		return (result);
	}
	result = ft_strjoin(s1, s2);
	if (f1)
		free((char *)s1);
	if (f2)
		free((char *)s2);
	return (result);
}

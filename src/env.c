/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angmarti <angmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 11:30:24 by angmarti          #+#    #+#             */
/*   Updated: 2023/06/05 12:07:39 by angmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/minishell.h"
/**
 * TODO: MUST receive the char **envp and not use getenv() because it wont work 
 * properly if a minisheel is executed inside another minishell.
 * 
 * @param envp 
 * @return char** 
 */
char **get_path_arr()
{
	char **path_arr;

	path_arr = ft_split(getenv("PATH"), ':');
	return (path_arr);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angmarti <angmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 15:21:18 by nucieda-          #+#    #+#             */
/*   Updated: 2023/06/28 20:35:33 by angmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/minishell.h"

// TODO: no agregar un espacio al final
void    ft_echo(t_cmd   *cmd)
{
	int	i;

	i = 1;
	while (cmd->args[i])
	{
		printf("%s ", cmd->args[i]);
		i++;
	}
	printf("\n");
}
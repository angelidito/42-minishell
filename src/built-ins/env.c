/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angmarti <angmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 15:21:21 by nucieda-          #+#    #+#             */
/*   Updated: 2023/07/12 16:59:53 by angmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/minishell.h"

void	lst_print_content(void *content)
{
	ft_printf("%s\n", (char *)content);
}

void    ft_env(t_list **env)
{
	ft_lstiter(*env, lst_print_content);
}

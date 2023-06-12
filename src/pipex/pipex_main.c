/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_main.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angmarti <angmarti@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 14:43:05 by angmarti          #+#    #+#             */
/*   Updated: 2023/06/10 14:51:21 by angmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/pipex.h"

int	main(int argc, char **argv, char **envp)
{
	t_vars	vars;

	pipex_check_errors(argc, argv, envp, &vars);
	set_vars(argc, argv, envp, &vars);
	pipex_case_n_cmds(&vars, NULL, ft_strarrsize(vars.cmds));
	return (0);
}

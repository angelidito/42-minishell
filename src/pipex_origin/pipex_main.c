/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_main.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angmarti <angmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 14:43:05 by angmarti          #+#    #+#             */
/*   Updated: 2023/06/14 23:13:50 by angmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/pipex.h"

int	main(int argc, char **argv, char **envp)
{
	t_vars	vars;

	p_____check_errors(argc, argv, envp, &vars);
	set_vars(argc, argv, envp, &vars);
	p_____case_n_cmds(&vars, NULL, ft_strarrsize(vars.cmds));
	return (0);
}

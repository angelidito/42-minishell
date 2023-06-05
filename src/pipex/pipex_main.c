/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_main.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angmarti <angmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 14:43:05 by angmarti          #+#    #+#             */
/*   Updated: 2023/06/05 11:06:31 by angmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/pipex.h"

int	main(int argc, char **argv, char **envp)
{
	t_vars	vars;

	pipex_check_errors(argc, argv, envp, &vars);
	set_vars(argc, argv, envp, &vars);
	case_n_cmds(&vars, NULL, ft_strarrsize(vars.cmds));
	return (0);
}

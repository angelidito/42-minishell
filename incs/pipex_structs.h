/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_structs.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nucieda- <nucieda-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 18:11:45 by angmarti          #+#    #+#             */
/*   Updated: 2023/06/12 19:20:23 by nucieda-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_STRUCTS_H
# define PIPEX_STRUCTS_H

typedef struct s_vars
{
	char	*infile;
	char	**cmds;
	char	*outfile;
	t_list	**envp;
	int		here_doc;
	char	*here_doc_lim;
	int		output_flag;
}			t_vars;

#endif

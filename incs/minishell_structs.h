/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_structs.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angmarti <angmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 18:11:45 by angmarti          #+#    #+#             */
/*   Updated: 2023/06/26 16:39:14 by angmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_STRUCTS_H
# define MINISHELL_STRUCTS_H

typedef struct s_cmd
{
	char				*cmd;
	char				**args;
	char				*file;
	int					file_x_access;
	int					built_in;
}						t_cmd;

typedef	struct s_mini_vars
{
	char	**env;
	char	**cmds;
	char	*infile;
	char	*outfile;
	int		here_doc;
	int		output_flag;
}						t_mini_vars;

#endif

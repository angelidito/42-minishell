/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_structs.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nucieda- <nucieda-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 18:11:45 by angmarti          #+#    #+#             */
/*   Updated: 2023/06/23 09:38:01 by nucieda-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_STRUCTS_H
# define MINISHELL_STRUCTS_H

// ? Completar si es necesario
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


// ?
typedef struct s_tree_node
{
	void				*content;
	struct s_tree_node	**nodes;
}						t_tree_node;

#endif

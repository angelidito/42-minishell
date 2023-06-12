/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_structs.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angmarti <angmarti@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 18:11:45 by angmarti          #+#    #+#             */
/*   Updated: 2023/06/12 17:45:10 by angmarti         ###   ########.fr       */
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
}						t_cmd;

// ?
typedef struct s_tree_node
{
	void				*content;
	struct s_tree_node	**nodes;
}						t_tree_node;

#endif

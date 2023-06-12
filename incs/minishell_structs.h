/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_structs.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angmarti <angmarti@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 18:11:45 by angmarti          #+#    #+#             */
/*   Updated: 2023/06/10 15:33:46 by angmarti         ###   ########.fr       */
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
	char				*data;
	struct s_tree_node	*left;
	struct s_tree_node	*right;
}						t_tree_node;

#endif

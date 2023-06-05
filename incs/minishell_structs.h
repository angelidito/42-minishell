/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_structs.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angmarti <angmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 18:11:45 by angmarti          #+#    #+#             */
/*   Updated: 2023/06/05 10:51:30 by angmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_STRUCTS_H
# define MINISHELL_STRUCTS_H

// ? Completar si es necesario
typedef struct s_cmd
{
	char	*executable;
	char	*cmd;
	char	**args;
}			t_cmd;

// ? 
typedef struct s_tree_node
{
	char				*data;
	struct s_tree_node	*left;
	struct s_tree_node	*right;
}						t_tree_node;



#endif

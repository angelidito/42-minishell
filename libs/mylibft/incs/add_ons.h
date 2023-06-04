/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_ons.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angmarti <angmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 14:21:15 by angmarti          #+#    #+#             */
/*   Updated: 2023/06/04 17:46:33 by angmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ADD_ONS_H
# define ADD_ONS_H

//	PROJECTS

int		ft_printf(char const *str, ...);

char	*get_next_line(int fd);

//	FUNCTIONS

int		ft_isspace(char c);

char	*ft_str_replace_dup_whitespaces(const char *str, char c);

// FT_STRARR.c

int		ft_strarrsize(char **strarr);
void	ft_freestrarr(char **strarr);
void	ft_print_strarr_op(char **arr, char *prefix, char *suffix, char *title);
void	ft_print_strarr(char **arr);

#endif

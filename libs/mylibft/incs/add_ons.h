/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_ons.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angmarti <angmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 14:21:15 by angmarti          #+#    #+#             */
/*   Updated: 2023/06/05 11:54:42 by angmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ADD_ONS_H
# define ADD_ONS_H

//	PROJECTS

int		ft_printf(char const *str, ...);

char	*get_next_line(int fd);

//	FUNCTIONS

char	*ft_str_replace_dup_whitespaces(const char *str, char c);
char	*ft_strjoin_n_free(const char *s1, const char *s2);
char	*ft_strjoin_n_free_op(const char *s1, const char *s2, int f1, int f2);

char	**ft_split_not_escaped(char const *s, char c);

int		ft_isspace(char c);
int		ft_strarrsize(char **strarr);

void	ft_freestrarr(char **strarr);
void	ft_print_strarr_op(char **arr, int list, char *prefix, char *suffix,
			char *title);
void	ft_print_strarr(char **arr);

#endif

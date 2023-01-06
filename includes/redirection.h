/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkasmi <zkasmi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 15:37:02 by zkasmi            #+#    #+#             */
/*   Updated: 2022/10/05 12:22:43 by zkasmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REDIRECTION_H
# define REDIRECTION_H

# include "minishell.h"
# include "expansion.h"
# include "parsing.h"
# include "buildin.h"

char	*quotesremove(char *str);
int		check_rdr(char *str);
void	parsing_rdr_output(char *tmp, t_data *data, int k, int i);
char	*rdr_mark(char *str);
void	rdr_input(char *input, t_data *data, int k);
void	rdr_output(char *input, t_data *data, int k);
void	rdr_heredoc(t_data *data, int k);
void	create_rdr_output(t_data *data, int k);
void	create_rdr_heredoc(t_data *data, int k, int *fd);
void	create_rdr_input(t_data *data, int k, int *fd);
void	rdr_parse(t_data *data, int k);
void	heredoc(t_data *data);

#endif
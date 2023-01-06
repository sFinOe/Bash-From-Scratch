/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkasmi <zkasmi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 15:28:21 by zkasmi            #+#    #+#             */
/*   Updated: 2022/09/26 12:58:50 by zkasmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# include "minishell.h"
# include "redirection.h"
# include "expansion.h"
# include "buildin.h"

t_token	*create_tokens(char *line);
char	**parsing(char *line, t_data *data);
char	**cmd_lines(t_token *start);
char	*create_spaces(char *line);
void	type_separator(t_token *token);
char	**sep_modifier(t_token *token);
int		quotes(char *line, int pos);

#endif
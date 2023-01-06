/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expansion.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkasmi <zkasmi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 15:19:33 by zkasmi            #+#    #+#             */
/*   Updated: 2022/10/09 18:27:05 by zkasmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXPANSION_H
# define EXPANSION_H

# include "minishell.h"
# include "parsing.h"
# include "redirection.h"
# include "buildin.h"

typedef struct s_cmd
{
	char			*str;
	int				i;
	int				j;
}				t_cmd;

char	*expansion(char *cmd, t_data *data, int exit);
void	set_dollar_env(t_cmd *exp, char *arg, t_data *data);
int		copy_env_value(char *line, const char *env_value, int pos);
char	*get_env_value(const char *line, int pos, t_data *data);
int		exp_len(const char *line, int exit, t_data *data);
int		ft_is_char(int c);
char	*expansion_line(char *input, t_data *data);
int		expansion_len(const char *line, int pos, t_data *data, int exit);
int		next_exp(const char *line, int i);

#endif
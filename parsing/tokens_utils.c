/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokens_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkasmi <zkasmi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 15:11:12 by zkasmi            #+#    #+#             */
/*   Updated: 2022/10/09 18:10:12 by zkasmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/parsing.h"

void	cmd_herdoc(char **str, t_token *tmp, int i)
{
	str[i][0] = -str[i][0];
	str[i][1] = -str[i][1];
	if (tmp->next->str[0] == '$')
		g_code_status.h_exp = 1;
	if (tmp->next->str[0] == (int)-'$')
		tmp->next->str[0] = '$';
}

void	modifier_2(t_token *tmp, char **str, int i)
{
	if (tmp->cmd_type == TRUNC)
		str[i][0] = -str[i][0];
	else if (tmp->cmd_type == APPEND)
	{
		str[i][0] = -str[i][0];
		str[i][1] = -str[i][1];
	}
	else if (tmp->cmd_type == INPUT)
		str[i][0] = -str[i][0];
	else if (tmp->cmd_type == HEREDOC)
		cmd_herdoc(str, tmp, i);
	else if (tmp->cmd_type == PIPE)
	{
		str[i][0] = -str[i][0];
		str[i][1] = -str[i][1];
	}
	else
	{
		str[i] = ft_strjoin("\'", str[i]);
		str[i] = ft_strjoin(str[i], "\'");
	}
	check_last_pipe(tmp);
}

void	modifier(t_token *tmp, char **str, int i, int len)
{
	int	j;

	while (i < len)
	{
		j = 0;
		str[i] = ft_strdup(tmp->str);
		while (str[i][j])
		{
			if (str[i][j] < 0 && str[i][j] != (int)-'$')
				str[i][j] = str[i][j] * -1;
			j++;
		}
		modifier_2(tmp, str, i);
		j = 0;
		while (str[i][j] && tmp->cmd_type != 2)
		{
			if (str[i][j] == (int)-'$')
				str[i] = ft_strtrim(str[i], "\'");
			j++;
		}
		tmp = tmp->next;
		i++;
	}
	str[i] = NULL;
}

char	**sep_modifier(t_token *token)
{
	int		len;
	char	**str;
	t_token	*tmp;
	int		i;

	len = ft_lnksize(token);
	str = ft_calloc(sizeof(char *), len + 1);
	tmp = token;
	i = 0;
	modifier(tmp, str, i, len);
	return (str);
}

void	type_separator(t_token *token)
{
	if (ft_strcmp(token->str, "") == 0)
		token->cmd_type = EMPTY;
	else if (ft_strcmp(token->str, ">") == 0)
		token->cmd_type = TRUNC;
	else if (ft_strcmp(token->str, ">>") == 0)
		token->cmd_type = APPEND;
	else if (ft_strcmp(token->str, "<") == 0)
		token->cmd_type = INPUT;
	else if (ft_strcmp(token->str, "|") == 0)
		token->cmd_type = PIPE;
	else if (ft_strcmp(token->str, "<<") == 0)
		token->cmd_type = HEREDOC;
	else if (token->prev == NULL || token->prev->cmd_type >= TRUNC)
		token->cmd_type = CMD;
	else
		token->cmd_type = ARG;
}

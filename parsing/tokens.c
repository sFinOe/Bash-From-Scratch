/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokens.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkasmi <zkasmi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/10 20:52:45 by zkasmi            #+#    #+#             */
/*   Updated: 2022/09/28 18:14:20 by zkasmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/parsing.h"

void	skip_spaces(const char *str, int *i)
{
	while ((str[*i] == ' ' || str[*i] == '\t')
		|| (str[*i] == '\r' || str[*i] == '\v' || str[*i] == '\f'))
		(*i)++;
}

int	token_len(char *line, int i)
{
	int		len;
	int		j;
	char	c;

	len = 0;
	j = 0;
	c = ' ';
	while (line[i + j] && (line[i + j] != ' ' || c != ' '))
	{
		if (c == ' ' && (line[i + j] == '\'' || line[i + j] == '\"'))
			c = line[i + j++];
		else if (c != ' ' && line[i + j] == c)
		{
			len += 2;
			c = ' ';
			j++;
		}
		else
			j++;
	}
	return (j - len + 1);
}

t_token	*next_token(char *line, int *i)
{
	t_token	*token;
	int		j;
	char	c;

	j = 0;
	c = ' ';
	token = ft_calloc(sizeof(t_token), 1);
	token->str = ft_calloc(sizeof(char), token_len(line, *i));
	while (line[*i] && (line[*i] != ' ' || c != ' '))
	{
		if (c == ' ' && (line[*i] == '\'' || line[*i] == '\"'))
			c = line[(*i)++];
		else if (c != ' ' && line[*i] == c)
		{
			c = ' ';
			(*i)++;
		}
		else
			token->str[j++] = line[(*i)++];
	}
	token->str[j] = '\0';
	return (token);
}

t_token	*create_tokens(char *line)
{
	t_token	*prev;
	t_token	*next;
	int		i;

	prev = NULL;
	next = NULL;
	i = 0;
	skip_spaces(line, &i);
	while (line[i])
	{
		next = next_token(line, &i);
		next->prev = prev;
		if (prev)
			prev->next = next;
		prev = next;
		type_separator(next);
		skip_spaces(line, &i);
	}
	if (next)
		next->next = NULL;
	while (next && next->prev)
		next = next->prev;
	return (next);
}

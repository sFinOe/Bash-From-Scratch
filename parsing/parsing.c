/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkasmi <zkasmi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 15:29:12 by zkasmi            #+#    #+#             */
/*   Updated: 2022/10/09 19:07:03 by zkasmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/parsing.h"

char	*space_len(char *line)
{
	char	*str;
	int		len;
	int		i;

	len = 0;
	i = 0;
	while (line[i])
	{
		if (check_meta(line, i))
			len++;
		i++;
	}
	str = ft_calloc(sizeof(char), (i + 2 * len + 1));
	return (str);
}

char	*create_space(char *str, char *line, int j, int i)
{
	while (str && line[i])
	{
		if (quotes(line, i) != 2 && line[i] == '$')
			str[j++] = (char)(-line[i++]);
		else if (quotes(line, i) == 0 && check_meta(line, i))
		{
			str[j++] = ' ';
			str[j++] = line[i++];
			if ((quotes(line, i) == 0 && line[i] == '>')
				|| (quotes(line, i) == 0 && line[i] == '<'))
				str[j++] = line[i++];
			str[j++] = ' ';
		}
		else
		{
			if (quotes(line, i) != 0 && check_meta(line, i) == -1)
				line[i] = -line[i];
			str[j++] = line[i++];
		}
	}
	str[j] = '\0';
	return (str);
}

char	*create_spaces(char *line)
{
	char	*str;
	int		i;
	int		j;

	i = 0;
	j = 0;
	str = space_len(line);
	str = create_space(str, line, i, j);
	return (str);
}

char	**cmd_lines(t_token *start)
{
	t_token	*token;
	char	**cmd_lines;
	int		i;

	if (!start)
		return (NULL);
	token = start->next;
	i = 2;
	while (token)
	{
		token = token->next;
		i++;
	}
	cmd_lines = ft_calloc(sizeof(char *), i);
	token = start->next;
	cmd_lines[0] = start->str;
	i = 1;
	while (token)
	{
		cmd_lines[i++] = token->str;
		token = token->next;
	}
	cmd_lines[i] = NULL;
	return (cmd_lines);
}

char	**parsing(char *line, t_data *data)
{
	char	*str;
	char	**cmd;

	str = ft_strdup(line);
	str = create_spaces(str);
	data->tokens = create_tokens(str);
	cmd = cmd_lines(data->tokens);
	return (cmd);
}

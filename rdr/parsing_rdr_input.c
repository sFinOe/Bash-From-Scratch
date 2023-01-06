/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_rdr_input.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkasmi <zkasmi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 09:35:14 by zkasmi            #+#    #+#             */
/*   Updated: 2022/10/09 18:54:31 by zkasmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/redirection.h"

int	get_rdr_input(char *input1)
{
	int	i;

	i = -1;
	while (input1[++i])
	{
		if (input1[i] == (int)-'<'
			|| (input1[i] == (int)-'<' && input1[i + 1] == (int)-'<'))
			break ;
	}
	return (i);
}

char	*check_rdr_input(char *str)
{
	char	*str1;
	int		i;
	int		j;

	i = -1;
	j = 0;
	str1 = ft_strdup(str);
	while (str1[++i])
	{
		if (str1[i] == 34 || str1[i] == 39)
			j++;
		if (j % 2 != 0)
		{
			if (str1[i] == (int)-'<')
				str1[i] = (char)(-str1[i]);
		}
	}
	return (str1);
}

void	clean_rdr_input(t_data *data, int j)
{
	while (data->rdr_line[++j])
	{
		data->tmp_line_2 = ft_strjoin2((int)-' ', data->rdr_line[j]);
		data->tmp_line_3 = ft_strjoin(data->tmp_line_1, data->tmp_line_2);
		data->tmp_line_1 = ft_strdup(data->tmp_line_3);
	}
}

void	parsing_rdr_input(char *tmp, t_data *data, int k, int i)
{
	int	j;

	data->rdr_line = ft_split(tmp, (int)-' ');
	j = 0;
	if (data->rdr_line[0] && data->rdr_line[0][0] == (int)-'<')
		data->rdr_line[0] = NULL;
	if (data->rdr_line[0])
	{
		if (data->rdr_line[0][0] == 34)
			data->rdr_input = ft_strtrimplus(data->rdr_line[0], 34);
		else if (data->rdr_line[0][0] == 39)
			data->rdr_input = ft_strtrimplus(data->rdr_line[0], 39);
		else
			data->rdr_input = ft_strdup(data->rdr_line[0]);
	}
	else
	{
		ft_perror("minishell: ambiguous redirect\n");
		g_code_status.codestatus = 1;
		g_code_status.r_err = 1;
	}
	data->tmp_line_1 = ft_substr(data->cmd_line[k], 0, i);
	clean_rdr_input(data, j);
	data->cmd_line[k] = ft_strdup(data->tmp_line_1);
}

void	rdr_input(char *input, t_data *data, int k)
{
	char	*line;
	char	*tmp;
	int		len;
	int		i;

	line = ft_strdup(data->cmd_line[k]);
	data->rdr_output = NULL;
	len = ft_strlen(line);
	i = get_rdr_input(line);
	if (line[i] == (int)-'<')
	{
		if ((line[i] == (int)-'<' && line[i + 1] == (int)-'<'))
		{
			tmp = ft_substr(input, i + 2, len);
			parsing_rdr_input(tmp, data, k, i);
		}
		else
		{
			tmp = ft_substr(input, i + 1, len);
			parsing_rdr_input(tmp, data, k, i);
		}
	}
	rdr_heredoc(data, k);
	if (check_rdr(data->cmd_line[k]) == 2)
		rdr_input(data->cmd_line[k], data, k);
}

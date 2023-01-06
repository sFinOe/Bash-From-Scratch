/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_rdr_output.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkasmi <zkasmi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 16:28:14 by zkasmi            #+#    #+#             */
/*   Updated: 2022/10/09 18:54:04 by zkasmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/redirection.h"

char	*rdr_mark(char *str)
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
			if (str1[i] == (int)-'>')
				str1[i] = (char)(-str1[i]);
		}
	}
	return (str1);
}

void	cparsing_rdr_input(t_data *data, int j)
{
	while (data->rdr_line[++j])
	{
		data->tmp_line_2 = ft_strjoin2((int)-' ', data->rdr_line[j]);
		data->tmp_line_3 = ft_strjoin(data->tmp_line_1, data->tmp_line_2);
		data->tmp_line_1 = ft_strdup(data->tmp_line_3);
	}
}

void	parsing_rdr_output(char *tmp, t_data *data, int k, int i)
{
	int	j;

	data->rdr_line = ft_split(tmp, (int)-' ');
	j = 0;
	if (data->rdr_line[0] && data->rdr_line[0][0] == (int)-'>')
		data->rdr_line[0] = NULL;
	if (data->rdr_line[0])
	{
		if (data->rdr_line[0][0] == 34)
			data->rdr_output = ft_strtrimplus(data->rdr_line[0], 34);
		else if (data->rdr_line[0][0] == 39)
			data->rdr_output = ft_strtrimplus(data->rdr_line[0], 39);
		else
			data->rdr_output = ft_strdup(data->rdr_line[0]);
	}
	else
	{
		ft_perror("minishell: ambiguous redirect\n");
		g_code_status.r_err = 1;
		g_code_status.codestatus = 1;
	}
	data->tmp_line_1 = ft_substr(data->cmd_line[k], 0, i);
	cparsing_rdr_input(data, j);
	data->cmd_line[k] = ft_strdup(data->tmp_line_1);
}

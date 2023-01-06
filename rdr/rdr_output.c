/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rdr_output.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkasmi <zkasmi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 09:35:14 by zkasmi            #+#    #+#             */
/*   Updated: 2022/10/05 12:23:40 by zkasmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/redirection.h"

int	get_rdr_output(char *input1)
{
	int	i;

	i = -1;
	while (input1[++i])
	{
		if (input1[i] == (int)-'>'
			|| (input1[i] == (int)-'>' && input1[i + 1] == (int)-'>'))
			break ;
	}
	return (i);
}

int	rdr_checker(char *input, int i)
{
	int	j;

	if (input[i] == (int)-'>' && input[i + 1] == (int)-'>')
		i++;
	j = ft_strlen(input);
	j--;
	while (j > i)
	{
		if (input[j] != 32)
			return (1);
		j--;
	}
	return (0);
}

void	rdr_output(char *input, t_data *data, int k)
{
	char	*line;
	char	*tmp;
	int		i;

	line = ft_strdup(input);
	data->rdr_output = NULL;
	i = get_rdr_output(line);
	if (line[i] == (int)-'>')
	{
		if ((line[i] == (int)-'>' && line[i + 1] == (int)-'>'))
		{
			tmp = ft_substr(data->cmd_line[k], i + 2, ft_strlen(line));
			parsing_rdr_output(tmp, data, k, i);
		}
		else
		{
			tmp = ft_substr(data->cmd_line[k], i + 1, ft_strlen(line));
			parsing_rdr_output(tmp, data, k, i);
		}
	}
	if (g_code_status.h_lock == 0)
		open(data->rdr_output, O_RDWR | O_CREAT | O_APPEND, 0644);
	if (check_rdr(data->cmd_line[k]) == 1)
		rdr_output(data->cmd_line[k], data, k);
}

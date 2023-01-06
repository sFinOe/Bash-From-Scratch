/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkasmi <zkasmi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 14:50:04 by sayar             #+#    #+#             */
/*   Updated: 2022/09/28 13:26:36 by zkasmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"
#include "../includes/expansion.h"
#include "../includes/parsing.h"
#include "../includes/redirection.h"
#include "../includes/buildin.h"

char	*get_line(t_data *data, char *line)
{
	data->tmp = ft_strdup(line);
	line = ft_strtrimplus(data->tmp, '"');
	data->tmp = ft_strdup(line);
	line = ft_strtrimplus(data->tmp, 39);
	data->bin_path = NULL;
	data->path_exec = NULL;
	return (line);
}

void	check_path(t_data *data, int l, char *line)
{
	int	i;

	i = 0;
	while (i < l)
	{
		data->bin_path[i] = ft_strdup("");
		data->tmp_line = ft_strjoin(data->bin_path[i], data->tmp_path[i]);
		data->tmp_line_1 = ft_strjoin(data->tmp_line, "/");
		data->bin_path[i] = ft_strjoin(data->tmp_line_1, line);
		i++;
	}
	data->bin_path[i] = NULL;
	i = 0;
	while (i < l)
	{
		if ((access(data->bin_path[i], X_OK)) == 0)
		{
			data->path_exec = ft_strdup(data->bin_path[i]);
			break ;
		}
		i++;
	}
}

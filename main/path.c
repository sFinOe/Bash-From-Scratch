/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkasmi <zkasmi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 10:19:54 by zkasmi            #+#    #+#             */
/*   Updated: 2022/10/10 10:40:40 by zkasmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"
#include "../includes/expansion.h"
#include "../includes/parsing.h"
#include "../includes/redirection.h"
#include "../includes/buildin.h"

int	ft_space(char *input)
{
	int	i;

	i = 0;
	while (input[i])
	{
		if (input[i] == 32)
			i++;
		else if (input[i] != 32)
			return (1);
	}
	return (0);
}

char	**new_str(char *str)
{
	char	**new;
	int		j;

	j = 0;
	new = ft_split(str, (int)-' ');
	while (new[j])
	{
		new[j] = ft_strtrim(new[j], "\'");
		j++;
	}
	return (new);
}

char	*space_qoutes(char *str)
{
	char	*tmp;
	char	**new;
	int		i;
	int		j;

	new = new_str(str);
	tmp = ft_split_add(new);
	if (tmp == NULL)
	{
		tmp = ft_strdup(str);
		return (tmp);
	}
	j = -1;
	while (tmp[++j])
		if (tmp[j] == '\'' || tmp[j] == '\"')
			return (tmp);
	i = 0;
	while (tmp[i])
	{
		if (quotes(tmp, i) == 0)
			if (tmp[i] == ' ')
				tmp[i] = -tmp[i];
		i++;
	}
	return (tmp);
}

void	bin_path(t_data *data, int k)
{
	int		j;
	char	*tmp;

	j = 0;
	data->cmd_echo = ft_strdup(data->cmd_line[k]);
	tmp = space_qoutes(data->cmd_line[k]);
	j = 0;
	data->line = ft_split(tmp, (int)-' ');
	while (data->line[j])
	{
		data->line[j] = ft_strtrim(data->line[j], "\'");
		j++;
	}
	data->file_path = NULL;
	if (!(data->line[0] == 0))
		data->file_path = path_exec(data, data->line[0]);
	if (data->file_path == NULL && data->cmd_line[k + 1] == NULL)
	{
		g_code_status.plock = 1;
		g_code_status.codestatus = 127;
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expansion_utils_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkasmi <zkasmi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 14:32:15 by sayar             #+#    #+#             */
/*   Updated: 2022/10/07 13:06:50 by zkasmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/expansion.h"

int	ft_is_char(int c)
{
	if (ft_isalnum(c) == 1 || c == '_')
		return (1);
	return (0);
}

int	exit_size(int exit)
{
	char	*tmp;
	int		ret_len;

	tmp = ft_itoa(exit);
	ret_len = ft_strlen(tmp);
	return (ret_len);
}

int	expansion_len(const char *line, int pos, t_data *data, int exit)
{
	char	var_name[BUFF_SIZE];
	char	*var_value;
	int		i;

	i = 0;
	if (line[pos] == '?')
		return (exit_size(exit));
	if (ft_isdigit(line[pos]))
		return (0);
	while (line[pos] && ft_is_char(line[pos]) == 1 && i < BUFF_SIZE)
	{
		var_name[i] = line[pos];
		pos++;
		i++;
	}
	var_name[i] = '\0';
	data->tmp_line = ft_strdup(var_name);
	data->tmp_line_1 = ft_strjoin("$", data->tmp_line);
	var_value = expansion_line(data->tmp_line_1, data);
	i = ft_strlen(var_value);
	return (i);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expansion_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkasmi <zkasmi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 15:22:17 by zkasmi            #+#    #+#             */
/*   Updated: 2022/10/09 18:26:50 by zkasmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/expansion.h"

char	*expansion_line(char *input, t_data *data)
{
	char	*line;
	char	*str;

	if (ft_strcmp(input, "$?") == 0)
	{
		if (data->k != 0)
			g_code_status.codestatus = 0;
		input = ft_itoa(g_code_status.codestatus);
		return (input);
	}
	str = ft_substr(input, 1, ft_strlen(input));
	line = ft_get_env(data, str);
	input = ft_strdup(line);
	return (input);
}

int	next_exp(const char *line, int i)
{
	if (line[i + 1] && ft_is_char(line[i])
		&& line[i + 1] != (int)-'$')
		return (1);
	return (0);
}

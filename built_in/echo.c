/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkasmi <zkasmi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/10 21:35:49 by zkasmi            #+#    #+#             */
/*   Updated: 2022/10/09 18:52:46 by zkasmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/buildin.h"

char	*new_line(char *line, char *str, int i, int *type)
{
	char	**new;

	new = ft_split(line, (int)-' ');
	i = 0;
	while (new[i])
	{
		if (ft_strcmp("''", new[i]) == 0)
			new[i] = ft_strdup("");
		new[i] = ft_strtrim(new[i], "\'");
		i++;
	}
	i = 1;
	while (new[i] && ft_strncmp(new[i], "-n", 2) == 0
		&& ft_check_n(new[i]) == 0)
	{
		*type = 1;
		i++;
	}
	str = ft_split_join(new + i);
	return (str);
}

int	ft_echo(char *line, t_data *data)
{
	int		i;
	int		type;
	char	*str;

	i = 0;
	str = NULL;
	type = 0;
	str = new_line(line, str, i, &type);
	write(1, str, ft_strlen(str));
	if (type == 0)
		write(1, "\n", 1);
	if (data->elock == 0)
		exit(0);
	g_code_status.codestatus = 0;
	return (0);
}

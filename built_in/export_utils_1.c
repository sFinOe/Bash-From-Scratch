/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_utils_1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkasmi <zkasmi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 14:37:56 by sayar             #+#    #+#             */
/*   Updated: 2022/10/09 18:35:01 by zkasmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/buildin.h"

int	export_bool(char *name, char *str)
{
	char	*s;
	char	*s1;

	s = ft_substr(str, 11, get_eq(str) - 11);
	s1 = ft_substr(name, 0, get_eq(name));
	if (ft_strcmp(s, s1) == 0)
		return (1);
	return (0);
}

int	export_with_plus_2(t_data *data, t_export *tmp)
{
	if (export_bool(data->name, tmp->data) == 1)
	{
		if (check_eq(data) == 1)
		{
			data->s2 = ft_strjoin(ft_substr(tmp->data, 0,
						ft_strlen(tmp->data) - 1), data->value);
			tmp->data = ft_strjoin3(data->s2, '\"');
		}
		return (1);
	}
	return (0);
}

int	export_with_plus(t_data *data, t_export *tmp)
{
	int	i;

	i = 0;
	while (data->name[i])
	{
		if (ft_strchr("+", data->name[i]) && ft_strchr("=", data->name[i + 1]))
		{
			data->name = ft_strjoin(ft_substr(data->name, 0,
						ft_strlen(data->name) - 2), "=");
			while (tmp)
			{
				if (export_with_plus_2(data, tmp))
					return (1);
				tmp = tmp->next;
			}
		}
		i++;
	}
	return (0);
}

int	check_export(t_data *data)
{
	t_export	*tmp;
	int			i;

	tmp = data->exp;
	while (tmp)
	{
		i = get_eq(tmp->data);
		if (export_with_plus(data, tmp))
			return (1);
		if (export_bool(data->name, tmp->data) == 1)
		{
			if (check_eq(data) == 1)
			{
				data->s = ft_strjoin3(data->value, '"');
				data->s2 = ft_strjoin2('"', data->s);
				data->tmp_line = ft_strjoin(data->name, data->s2);
				tmp->data = ft_strjoin("declare -x ", data->tmp_line);
			}
			return (1);
		}
		tmp = tmp->next;
	}
	return (0);
}

char	*ft_split_join(char **cmd)
{
	char	*s1;
	char	*s2;
	char	*s3;
	int		i;

	i = -1;
	s3 = ft_strdup("");
	while (cmd[++i])
	{
		if (ft_strcmp(cmd[i], "") == 0)
			continue ;
		if (cmd[i + 1] == NULL)
			s1 = ft_strdup(cmd[i]);
		else
			s1 = ft_strjoin(cmd[i], " ");
		s2 = ft_strdup(s3);
		s3 = ft_strjoin(s2, s1);
	}
	return (s3);
}

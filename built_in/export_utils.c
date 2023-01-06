/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkasmi <zkasmi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 14:35:10 by sayar             #+#    #+#             */
/*   Updated: 2022/09/27 17:50:48 by zkasmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/buildin.h"

int	check_env_name(char *name, char *str)
{
	char	*s;
	char	*s1;

	s = ft_substr(str, 0, get_eq(str));
	s1 = ft_substr(name, 0, get_eq(name));
	if (ft_strcmp(s, s1) == 0)
	{
		return (1);
	}
	return (0);
}

int	check_env(t_data *data)
{
	t_env		*tmp;
	int			i;

	tmp = data->env;
	while (tmp)
	{
		i = get_eq(tmp->data);
		if (check_env_name(data->name, tmp->data) == 1)
		{
			if (check_eq(data) == 1)
				tmp->data = ft_strjoin(data->name, data->value);
			return (1);
		}
		tmp = tmp->next;
	}
	return (0);
}

int	get_eq(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		if (str[i] == '=')
		{
			return (i);
		}
		i++;
	}
	return (i);
}

void	change_export_value(t_data *data, int i, int j, char *str)
{
	int		l;
	char	*s1;
	char	*s2;

	l = -1;
	while (str[++l])
	{
		if (str[l] == '=')
			break ;
	}
	if (str[l] == '=')
	{
		s1 = ft_substr(str, l + 1, ft_strlen(str));
		if (ft_strcmp(s1, "") == 0)
			data->value = ft_strdup("");
		if (!(ft_strcmp(s1, "") == 0))
		{
			s2 = change_value(s1);
			data->value = ft_strdup(s2);
		}
	}
	else
		data->value = ft_substr(str, i + 1, (j - 1) - i);
	data->name = ft_substr(str, 0, l + 1);
}

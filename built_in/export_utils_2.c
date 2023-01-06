/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_utils_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkasmi <zkasmi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 20:38:16 by sayar             #+#    #+#             */
/*   Updated: 2022/09/28 13:12:16 by zkasmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/buildin.h"

void	export_value(t_data *data, char *str)
{
	int	i;
	int	j;

	i = -1;
	while (str[++i])
	{
		if (str[i] == '=')
		{
			if (str[i] == '=' && (str[i + 1] == '"' || str[i + 1] == 39))
			{
				i++;
				break ;
			}
			break ;
		}
	}
	j = i + 1;
	while (str[++j])
	{
	}
	change_export_value(data, i, j, str);
}

int	expo_checker(char *str)
{
	int		i;

	if (str[0] == '=')
		return (3);
	if (str[0] >= '0' && str[0] <= '9')
		return (4);
	if (!(str[0] == '_' || (str[0] >= '0' && str[0] <= '9')
			|| (str[0] >= 'A' && str[0] <= 'Z')
			|| (str[0] >= 'a' && str[0] <= 'z')))
		return (4);
	i = -1;
	while (str[++i])
	{
		if (str[i] == '=' && str[i + 1] == '=')
			return (4);
		if (str[i] == '=')
			break ;
		if (!((str[i] >= '0' && str[i] <= '9')
				|| (str[i] >= 'A' && str[i] <= 'Z')
				|| (str[i] >= 'a' && str[i] <= 'z')
				|| (str[i] == '+' && str[i + 1] == '=')))
			return (4);
	}
	return (0);
}

char	*change_value(char *str)
{
	char	*str1;

	str1 = ft_strdup(str);
	return (str1);
}

int	check_eq(t_data *data)
{
	int	i;

	i = -1;
	if (!data->name)
		return (0);
	while (data->name[++i])
	{
		if (data->name[i] == '=')
			return (1);
	}
	return (0);
}

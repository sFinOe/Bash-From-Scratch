/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkasmi <zkasmi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 11:32:57 by zkasmi            #+#    #+#             */
/*   Updated: 2022/10/09 18:30:38 by zkasmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/buildin.h"

t_export	*ft_export_2(t_data *data, t_export *tmp)
{
	tmp->next = ft_calloc(sizeof(struct s_export), 1);
	tmp = tmp->next;
	data->tmp_line = ft_strjoin3(data->value, '"');
	data->tmp_line_1 = ft_strjoin2('"', data->tmp_line);
	data->tmp_line_2 = ft_strjoin(data->name, data->tmp_line_1);
	tmp->data = ft_strjoin("declare -x ", data->tmp_line_2);
	tmp->next = NULL;
	return (tmp);
}

void	ft_export_1(t_data *data, t_export *tmp, int i)
{
	while (tmp->next)
		tmp = tmp->next;
	i = 0;
	while (data->cmd[++i])
	{
		if (expo_checker(data->cmd[i]) != 0)
		{
			data->msg = data->cmd[i];
			ft_strerror(data, expo_checker(data->cmd[i]));
			continue ;
		}
		export_value(data, data->cmd[i]);
		if ((check_eq(data) == 1) && (check_export(data)) == 0)
			tmp = ft_export_2(data, tmp);
		else if (check_eq(data) == 0 && (check_export(data)) == 0)
		{
			tmp->next = ft_calloc(sizeof(struct s_export), 1);
			tmp = tmp->next;
			tmp->data = ft_strjoin("declare -x ", data->name);
			tmp->next = NULL;
		}
		if (check_env(data) == 0)
			all_env(data);
	}
}

void	ft_export(t_data *data)
{
	t_export	*tmp;
	int			i;

	tmp = data->exp;
	i = 0;
	ft_export_1(data, tmp, i);
	ft_shlvl(data);
}

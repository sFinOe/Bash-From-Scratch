/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkasmi <zkasmi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 15:35:49 by zkasmi            #+#    #+#             */
/*   Updated: 2022/10/07 18:22:53 by zkasmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/buildin.h"

int	unset_checker(char *str)
{
	int		i;

	if (str[0] == '=')
		return (3);
	if (str[0] >= 48 && str[0] <= 57)
		return (4);
	if (!(str[0] == 95 || (str[0] >= 48 && str[0] <= 57)
			|| (str[0] >= 65 && str[0] <= 90)
			|| (str[0] >= 97 && str[0] <= 122)))
		return (4);
	i = -1;
	while (str[++i])
	{
		if (str[i] == '=')
			return (4);
		if (str[i] == '=')
			break ;
		if (!((str[i] >= 48 && str[i] <= 57)
				|| (str[i] >= 65 && str[i] <= 90)
				|| (str[i] >= 97 && str[i] <= 122)))
			return (4);
	}
	return (0);
}

void	ft_unset(char **cmd, t_data *data)
{
	int		i;

	i = 0;
	while (cmd[++i])
	{
		if (unset_checker(cmd[i]) != 0)
		{
			data->msg = cmd[i];
			ft_strerror(data, unset_checker(cmd[i]));
			continue ;
		}
		delete_lst(data, cmd[i]);
	}
}

void	unset_export(t_data *data, char *name, int i)
{
	t_export	*tmp;
	t_export	*delete;

	tmp = data->exp;
	while (tmp)
	{
		if (!tmp->next)
			break ;
		i = get_eq(tmp->next->data);
		if (ft_strncmplus(tmp->next->data, name, 11, i - 11) == 0)
		{
			delete = tmp->next;
			tmp = expo_delt(tmp);
		}
		tmp = tmp->next;
	}
}

void	unset_env(t_data *data, char *name, int i)
{
	t_env		*tmp;

	tmp = data->env;
	while (tmp)
	{
		if (!tmp->next)
			break ;
		i = get_eq(tmp->next->data);
		if (ft_strncmplus(tmp->next->data, name, 0, i) == 0)
		{
			tmp = env_delt(tmp);
			break ;
		}
		tmp = tmp->next;
	}
}

void	delete_lst(t_data *data, char *name)
{
	int			i;

	i = 0;
	unset_export(data, name, i);
	unset_env(data, name, i);
	ft_env(data);
}

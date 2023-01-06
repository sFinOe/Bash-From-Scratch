/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkasmi <zkasmi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 15:03:23 by sayar             #+#    #+#             */
/*   Updated: 2022/09/25 15:43:02 by zkasmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/buildin.h"

void	ft_set_pwd_export(t_data *data)
{
	t_export	*tmp;
	char		pwd[100];

	tmp = data->exp;
	data->s = NULL;
	data->s2 = NULL;
	data->s3 = NULL;
	getcwd(pwd, 100);
	while (tmp)
	{
		set_export_old_pwd(tmp, data, pwd);
		tmp = tmp->next;
	}
	tmp = data->exp;
	while (tmp)
	{
		set_export_pwd(tmp, data, pwd);
		tmp = tmp->next;
	}
}

void	ft_set_pwd(t_data *data)
{
	char	*s;
	char	pwd[100];
	t_env	*tmp;

	tmp = data->env;
	getcwd(pwd, 100);
	s = NULL;
	while (tmp)
	{
		env_old_pwd(tmp, s, pwd);
		tmp = tmp->next;
	}
	tmp = data->env;
	while (tmp)
	{
		if (check_env_name("PWD", tmp->data) == 1)
		{
			s = ft_strdup("PWD=");
			tmp->data = ft_strjoin(s, pwd);
		}
		tmp = tmp->next;
	}
	ft_set_pwd_export(data);
}

void	ft_change_pwd_export(t_data *data)
{
	char		pwd[100];
	t_export	*tmp;
	t_export	*tmp2;

	tmp = data->exp;
	tmp2 = NULL;
	data->s = NULL;
	data->s2 = NULL;
	data->s3 = NULL;
	getcwd(pwd, 100);
	while (tmp)
	{
		change_export_old_pwd(tmp, tmp2, data);
		tmp = tmp->next;
	}
	tmp = data->exp;
	while (tmp)
	{
		change_export_pwd(tmp, data, pwd);
		tmp = tmp->next;
	}
}

void	ft_change_pwd(t_data *data)
{
	char	pwd[100];
	t_env	*tmp;
	t_env	*tmp2;

	tmp = data->env;
	tmp2 = NULL;
	getcwd(pwd, 100);
	while (tmp)
	{
		if (check_env_name("OLDPWD", tmp->data) == 1)
		{
			change_env_old_pwd(tmp, tmp2, data);
			break ;
		}
		tmp = tmp->next;
	}
	tmp = data->env;
	change_env_pwd(tmp, data, pwd);
}

char	*ft_get_env(t_data *data, char *name)
{
	t_env	*tmp;
	char	*path;
	int		i;
	int		len;

	tmp = data->env;
	path = NULL;
	while (tmp)
	{
		if (check_env_name(name, tmp->data) == 1)
		{
			i = ft_strlen(name) + 1;
			len = ft_strlen(tmp->data);
			path = ft_substr(tmp->data, i, len);
			break ;
		}
		tmp = tmp->next;
	}
	return (path);
}

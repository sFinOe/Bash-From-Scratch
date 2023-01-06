/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_utils_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkasmi <zkasmi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 16:00:33 by sayar             #+#    #+#             */
/*   Updated: 2022/10/04 08:40:59 by zkasmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/buildin.h"

void	change_env_old_pwd(t_env *tmp, t_env *tmp2, t_data *data)
{
	tmp2 = data->env;
	while (tmp2)
	{
		if (check_env_name("PWD", tmp2->data) == 1)
		{
			data->s = ft_strdup("OLDPWD=");
			data->s2 = ft_substr(tmp2->data, 4, ft_strlen(tmp2->data));
			tmp->data = ft_strjoin(data->s, data->s2);
			break ;
		}
		tmp2 = tmp2->next;
	}
}

void	get_pwd(t_env *tmp, t_data *data, char *pwd)
{
	data->s = ft_strdup("PWD=");
	tmp->data = ft_strjoin(data->s, pwd);
}

void	cd_utils(t_data *data, DIR *dir)
{
	char	pwd[100];

	if (dir)
		closedir(dir);
	if (getcwd(pwd, 100))
	{
		ft_change_pwd(data);
		ft_change_pwd_export(data);
	}
	if (!(getcwd(pwd, 100)))
	{
		ft_perror("error retrieving current directory\n");
		g_code_status.codestatus = 1;
	}
}

void	change_env_pwd(t_env *tmp, t_data *data, char *pwd)
{
	while (tmp)
	{
		if (check_env_name("PWD", tmp->data) == 1)
		{
			get_pwd(tmp, data, pwd);
			break ;
		}
		tmp = tmp->next;
	}
}

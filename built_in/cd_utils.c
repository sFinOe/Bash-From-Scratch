/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkasmi <zkasmi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 15:07:49 by sayar             #+#    #+#             */
/*   Updated: 2022/09/30 16:45:25 by zkasmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/buildin.h"

void	set_export_old_pwd(t_export *tmp, t_data *data, char *pwd)
{
	if (export_bool("OLDPWD", tmp->data) == 1)
	{
		data->s = ft_strdup("declare -x ");
		data->s2 = ft_strdup("OLDPWD=");
		data->s3 = ft_strjoin(data->s, data->s2);
		data->s = ft_strjoin3(data->s3, 34);
		data->s2 = ft_strjoin3(pwd, 34);
		tmp->data = ft_strjoin(data->s, data->s2);
	}
}

void	set_export_pwd(t_export *tmp, t_data *data, char *pwd)
{
	if (export_bool("PWD", tmp->data) == 1)
	{
		data->s = ft_strdup("declare -x ");
		data->s2 = ft_strdup("PWD=");
		data->s3 = ft_strjoin(data->s, data->s2);
		data->s = ft_strjoin3(data->s3, 34);
		data->s2 = ft_strjoin3(pwd, 34);
		tmp->data = ft_strjoin(data->s, data->s2);
	}
}

void	env_old_pwd(t_env *tmp, char *s, char *pwd)
{
	if (check_env_name("OLDPWD", tmp->data) == 1)
	{
		s = ft_strdup("OLDPWD=");
		tmp->data = ft_strjoin(s, pwd);
	}
}

void	change_export_old_pwd(t_export *tmp, t_export *tmp2, t_data *data)
{
	if (export_bool("OLDPWD", tmp->data) == 1)
	{
		tmp2 = data->exp;
		while (tmp2)
		{
			if (export_bool("PWD", tmp2->data) == 1)
			{
				data->s = ft_strdup("declare -x ");
				data->s2 = ft_strdup("OLDPWD=");
				data->s3 = ft_strjoin(data->s, data->s2);
				data->s = ft_substr(tmp2->data, 15, ft_strlen(tmp2->data));
				tmp->data = ft_strjoin(data->s3, data->s);
				break ;
			}
			tmp2 = tmp2->next;
		}
	}
}

void	change_export_pwd(t_export *tmp, t_data *data, char *pwd)
{
	if (export_bool("PWD", tmp->data) == 1)
	{
		data->s = ft_strdup("declare -x ");
		data->s2 = ft_strdup("PWD=");
		data->s3 = ft_strjoin(data->s, data->s2);
		data->s = ft_strjoin3(data->s3, 34);
		data->s2 = ft_strjoin3(pwd, 34);
		tmp->data = ft_strjoin(data->s, data->s2);
	}
}

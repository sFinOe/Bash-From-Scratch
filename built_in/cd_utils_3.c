/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_utils_3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkasmi <zkasmi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 17:06:58 by sayar             #+#    #+#             */
/*   Updated: 2022/10/05 12:14:45 by zkasmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/buildin.h"

void	home_not_found(t_data *data)
{
	data->home = ft_get_env(data, "HOME");
	if (!(data->home))
		write(1, "HOME not set\n", 13);
	data->s = ft_strjoin("/", data->home);
}

void	ft_chdir(t_data *data, DIR *dir, char *path)
{
	if (data->cmd[1] == NULL)
		home_not_found(data);
	else if (dir != NULL && !path)
		data->s = ft_strjoin("./", data->cmd[1]);
	else if (!path)
		data->s = ft_strjoin("/", data->cmd[1]);
	if (chdir(data->s) < 0)
	{
		g_code_status.codestatus = 1;
		ft_perror("Directory not found\n");
	}
	cd_utils(data, dir);
	if (ft_strcmp(data->s, "./.") != 0)
		pwd(data);
}

void	ft_cd(t_data *data)
{
	DIR		*dir;
	char	*path;

	dir = NULL;
	data->s = NULL;
	data->home = NULL;
	path = NULL;
	data->s = ft_strjoin("./", data->cmd[1]);
	if (ft_strcmp(data->cmd[1], "-") == 0 && !data->cmd[2])
	{
		path = ft_get_env(data, "OLDPWD");
		data->s = path;
	}
	if (data->cmd[1] != NULL && data->s)
		dir = opendir(data->s);
	ft_chdir(data, dir, path);
}

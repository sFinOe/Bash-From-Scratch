/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkasmi <zkasmi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 18:51:57 by zkasmi            #+#    #+#             */
/*   Updated: 2022/10/05 12:13:25 by zkasmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/buildin.h"

void	shlvl_2(t_data *data)
{
	t_export	*tmp2;

	tmp2 = data->exp;
	while (tmp2)
	{
		if (export_bool("SHLVL", tmp2->data) == 1)
		{
			data->tmp_line = ft_strdup("declare -x SHLVL=");
			data->tmp_line_3 = ft_strjoin3(data->tmp_line, 34);
			data->tmp_line_4 = ft_strjoin3(data->tmp_line_2, 34);
			tmp2->data = ft_strjoin(data->tmp_line_3, data->tmp_line_4);
			break ;
		}
		tmp2 = tmp2->next;
	}
}

void	ft_shlvl(t_data *data)
{
	t_env		*tmp;
	int			total;

	tmp = data->env;
	while (tmp)
	{
		if (check_env_name("SHLVL", tmp->data) == 1)
		{
			data->tmp_line = ft_substr(tmp->data, 6, ft_strlen(tmp->data));
			total = ft_atoi(data->tmp_line);
			if (data->shlvl == 0)
				total++;
			if (total < 0)
				total = 0;
			data->tmp_line = ft_strdup("SHLVL=");
			data->tmp_line_2 = ft_itoa(total);
			tmp->data = ft_strjoin(data->tmp_line, data->tmp_line_2);
			data->shlvl = 1;
			break ;
		}
		tmp = tmp->next;
	}
	shlvl_2(data);
}

void	pwd(t_data *data)
{
	char	*pwd;
	char	pwd2[100];

	pwd = NULL;
	pwd = ft_get_env(data, "PWD");
	if (pwd == NULL)
	{
		getcwd(pwd2, 100);
		data->pwd = ft_strdup(pwd2);
	}
	else
		data->pwd = ft_strdup(pwd);
}

void	print_pwd(t_data *data)
{
	printf("%s\n", data->pwd);
}

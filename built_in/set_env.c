/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_env.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkasmi <zkasmi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 17:07:50 by zkasmi            #+#    #+#             */
/*   Updated: 2022/09/26 12:40:42 by zkasmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/buildin.h"

char	**empty_env(char **envp)
{
	char	pwd[100];

	getcwd(pwd, 100);
	if (envp[0] == NULL)
	{
		envp = ft_calloc(sizeof(char *), 4);
		envp[0] = ft_strjoin("PWD=", pwd);
		envp[1] = ft_strdup("SHLVL=0");
		envp[2] = ft_strdup("_=/usr/bin/env");
		envp[3] = NULL;
	}
	return (envp);
}

struct s_env	*set_env(t_data *data, char **envp)
{
	struct s_env	*head;
	struct s_env	*tail;
	int				i;

	envp = empty_env(envp);
	head = ft_calloc(sizeof(struct s_env), 1);
	head->data = ft_strdup(envp[0]);
	tail = head;
	i = 0;
	while (envp[++i])
	{
		tail->next = ft_calloc(sizeof(struct s_env), 1);
		tail = tail->next;
		tail->data = ft_strdup(envp[i]);
		tail->next = NULL;
	}
	data->env = head;
	return (head);
}

void	set_export_2(t_data *data, int len, t_export *tail)
{
	int	i;

	i = 0;
	while (data->envp[++i])
	{
		len = ft_strlen(data->envp[i]) + 1;
		tail->next = ft_calloc(sizeof(struct s_export), 1);
		tail = tail->next;
		data->tmp_line_1 = ft_substr2(data->envp[i], 0,
				get_eq(data->envp[i]) + 1);
		data->tmp_line_2 = ft_substr2(data->envp[i],
				get_eq(data->envp[i]) + 1, len);
		data->tmp_export_1 = ft_strjoin(data->tmp_line_1, data->tmp_line_2);
		data->tmp_export = ft_strdup(data->tmp_export_1);
		tail->data = ft_strjoin("declare -x ", data->tmp_export);
		tail->next = NULL;
	}
}

struct s_export	*set_export(t_data *data)
{
	struct s_export	*head;
	struct s_export	*tail;
	int				len;

	len = ft_strlen(data->envp[0]) + 1;
	head = ft_calloc(sizeof(struct s_export), 1);
	data->tmp_line_1 = ft_substr2(data->envp[0], 0, get_eq(data->envp[0]) + 1);
	data->tmp_line_2 = ft_substr2(data->envp[0],
			get_eq(data->envp[0]) + 1, len);
	data->tmp_export_1 = ft_strjoin(data->tmp_line_1, data->tmp_line_2);
	data->tmp_export = ft_strdup(data->tmp_export_1);
	head->data = ft_strjoin("declare -x ", data->tmp_export);
	tail = head;
	set_export_2(data, len, tail);
	return (head);
}

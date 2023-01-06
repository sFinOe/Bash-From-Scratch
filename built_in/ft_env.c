/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkasmi <zkasmi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 10:41:35 by zkasmi            #+#    #+#             */
/*   Updated: 2022/10/09 18:10:08 by zkasmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/buildin.h"

void	print_export(t_data *data)
{
	t_export	*tmp;

	tmp = data->exp;
	while (tmp)
	{
		printf("%s\n", tmp->data);
		tmp = tmp->next;
	}
}

void	print_env(t_data *data)
{
	int	i;

	i = 0;
	while (data->envp[i])
	{
		printf("%s\n", data->envp[i]);
		i++;
	}
}

void	ft_env(t_data *data)
{
	struct s_env	*tmp;
	int				i;

	tmp = data->env;
	i = 0;
	while (tmp)
	{
		i++;
		tmp = tmp->next;
	}
	tmp = data->env;
	data->envp = ft_calloc(sizeof(char *), i + 1);
	i = 0;
	while (tmp)
	{
		data->envp[i] = ft_strdup(tmp->data);
		tmp = tmp->next;
		i++;
	}
	data->envp[i] = NULL;
}

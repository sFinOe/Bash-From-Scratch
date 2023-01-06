/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_env.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkasmi <zkasmi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 09:43:02 by zkasmi            #+#    #+#             */
/*   Updated: 2022/09/25 17:56:59 by zkasmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/buildin.h"

void	all_env(t_data *data)
{
	struct s_env	*tmp;

	tmp = data->env;
	if (check_eq(data) == 1)
	{
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = ft_calloc(sizeof(struct s_env), 1);
		tmp = tmp->next;
		tmp->data = ft_strjoin(data->name, data->value);
		tmp->next = NULL;
	}
	tmp = data->env;
}

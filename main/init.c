/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkasmi <zkasmi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 17:21:34 by sayar             #+#    #+#             */
/*   Updated: 2022/09/28 17:59:48 by zkasmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"
#include "../includes/expansion.h"
#include "../includes/parsing.h"
#include "../includes/redirection.h"
#include "../includes/buildin.h"

void	ft_readline(t_data *data)
{
	data->inpt = readline("minishell> ");
	collect_adr(data->inpt);
	if (data->inpt)
		data->tocheck = ft_strdup(data->inpt);
	if (data->inpt == NULL || ft_strcmp(data->inpt, "exit") == 0)
	{
		printf("exit\n");
		free_adr();
		exit(g_code_status.codestatus);
	}
}

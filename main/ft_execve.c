/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_execve.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkasmi <zkasmi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 15:24:37 by zkasmi            #+#    #+#             */
/*   Updated: 2022/10/08 18:54:39 by zkasmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"
#include "../includes/expansion.h"
#include "../includes/parsing.h"
#include "../includes/redirection.h"
#include "../includes/buildin.h"

int	exec_buildin(t_data *data)
{
	if ((ft_strcmp(data->line[0], "echo") == 0))
		ft_echo(data->cmd_echo, data);
	else if ((ft_strcmp(data->line[0], "exit") == 0))
		exit(0);
	else if ((ft_strcmp(data->line[0], "env") == 0))
	{
		print_env(data);
		exit(0);
	}
	else if ((ft_strcmp(data->line[0], "export") == 0))
	{
		print_export(data);
		exit(0);
	}
	else if ((ft_strcmp(data->line[0], "pwd") == 0))
	{
		print_pwd(data);
		exit(0);
	}
	return (1);
}

void	ft_execve(t_data *data)
{
	if (exec_buildin(data))
		if (execve(data->file_path, data->line, data->envp) < 0)
			if (data->line[0])
				ft_handle_error(data);
	exit(1);
}

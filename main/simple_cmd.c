/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_cmd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkasmi <zkasmi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 22:53:08 by zkasmi            #+#    #+#             */
/*   Updated: 2022/10/05 15:57:43 by zkasmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"
#include "../includes/expansion.h"
#include "../includes/parsing.h"
#include "../includes/redirection.h"
#include "../includes/buildin.h"

int	ft_pipecheck(char *str)
{
	int	i;
	int	j;

	i = -1;
	j = 0;
	while (str[++i])
	{
		if (str[i] == 34 || str[i] == 39)
			j++;
		if (j % 2 == 0)
		{
			if (str[i] == '|')
				return (1);
		}
	}
	return (0);
}

void	do_echo(char *line, t_data *data)
{
	data->elock = 1;
	ft_echo(line, data);
	data->elock = 0;
}

void	simple_cmd(char *input, char **cmd, t_data *data)
{
	if (ft_strcmp(cmd[0], "echo") == 0)
		do_echo(input, data);
	else if (ft_strcmp(cmd[0], "env") == 0 && cmd[1] == NULL)
		print_env(data);
	else if (ft_strcmp(cmd[0], "pwd") == 0 && cmd[1] == NULL)
		print_pwd(data);
	else if (ft_strcmp(cmd[0], "export") == 0 && cmd[1] == NULL)
		print_export(data);
	else if (ft_strcmp(cmd[0], "export") == 0)
		ft_export(data);
	else if (ft_strcmp(cmd[0], "unset") == 0)
		ft_unset(cmd, data);
	else if (ft_strcmp(cmd[0], "cd") == 0)
		ft_cd(data);
}

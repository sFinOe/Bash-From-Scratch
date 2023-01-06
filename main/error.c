/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkasmi <zkasmi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 16:44:58 by sayar             #+#    #+#             */
/*   Updated: 2022/10/05 12:13:00 by zkasmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"
#include "../includes/expansion.h"
#include "../includes/parsing.h"
#include "../includes/redirection.h"
#include "../includes/buildin.h"

void	ft_strerror(t_data *data, int check)
{
	if (check == 0)
		ft_perror("%s: command not found\n", data->line[0]);
	if (check == 1)
		ft_perror("%s: No such file or directory\n", data->rdr_input);
	if (check == 2)
		ft_perror("%s: No such file or directory\n", data->rdr_output);
	if (check == 3)
		ft_perror("Export: '=': not a valid identifier\n");
	if (check == 4)
		ft_perror("Export: '%s': not a valid identifier\n", data->msg);
	if (check == 5)
		ft_perror("unset: '%s': not a valid identifier\n", data->msg);
	g_code_status.codestatus = 1;
}

int	parsing_check(char *str)
{
	int	i;
	int	j;

	i = -1;
	j = 0;
	while (str[++i])
	{
		if (str[i] == '\'' || str[i] == '\"')
			j++;
		if (j % 2 == 0)
		{
			if (str[i] == '>' || str[i] == '<')
			{
				while (str[i])
				{
					if (ft_isalnum2(str[i]) == 1)
						return (0);
					i++;
				}
				return (1);
			}
		}
	}
	return (0);
}

int	ft_get_error(char *str)
{
	int	i;
	int	j;
	int	k;

	i = -1;
	j = 0;
	k = 0;
	if (str[0] == '|')
		return (1);
	i = -1;
	if (ft_get_str(str, i, j, k) == 1)
		return (1);
	i = 0;
	if (str_check(str, i) == 1)
		return (1);
	if (parsing_check(str) == 1)
		return (1);
	else
		return (0);
}

void	build_incheck(t_data *data)
{
	if (expo_checker(data->line[1]) != 0)
	{
		data->msg = data->line[1];
		ft_strerror(data, expo_checker(data->line[1]));
	}
}

void	ft_handle_error(t_data *data)
{
	if (ft_strcmp(data->line[0], "exit") == 0)
		return ;
	if (ft_strcmp(data->line[0], "unset") == 0)
		return ;
	if (ft_strcmp(data->line[0], "cd") == 0)
		return ;
	if (ft_strcmp(data->line[0], "export") == 0)
	{
		build_incheck(data);
		return ;
	}
	ft_strerror(data, 0);
}

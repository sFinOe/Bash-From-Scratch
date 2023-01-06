/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkasmi <zkasmi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 10:33:41 by zkasmi            #+#    #+#             */
/*   Updated: 2022/10/05 16:09:19 by zkasmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/buildin.h"

int	ft_exit1(char **plit)
{
	long long	code;

	if (plit[1] && plit[2] == NULL)
	{
		if (plit[1][0] == '\"')
			plit[1] = ft_strtrim(plit[1], "\"");
		code = ft_atoi(plit[1]);
		free_adr();
		exit(code);
	}
	ft_perror("exit: too many arguments\n");
	return (1);
}

int	ft_exit(t_data *data)
{
	char	**plit;
	int		i;

	plit = NULL;
	i = -1;
	plit = ft_split(data->inpt, ' ');
	while (plit[1][++i])
	{
		if (ft_isalpha(plit[1][i]) == 1)
		{
			ft_perror("exit\nnumeric argument required\n");
			free_adr();
			exit(255);
		}
	}
	return (ft_exit1(plit));
}

int	check_rdr_empty(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (quotes(str, i) == 0)
		{
			if (str[i] == '>' || str[i] == '<')
			{
				if (str[i + 1] == '>' || str[i + 1] == '<')
					i++;
				i++;
				while (str[i] == ' ')
					i++;
				if (str[i] == '>' || str[i] == '<')
					return (1);
			}
		}
		i++;
	}
	return (0);
}

int	check_exit(char *input, t_data *data)
{
	if (ft_strncmp(input, "exit ", 5) == 0 && pipecheck(input) == 0)
		if (ft_exit(data) == 1)
			return (1);
		g_code_status.plock = 0;
	if (quotes(input, ft_strlen(input)) != 0
		|| check_rdr_empty(input) || ft_get_error(input))
	{
		ft_perror("minishell: syntax error: unexpected token\n");
		g_code_status.codestatus = 1;
		return (2);
	}
	return (0);
}

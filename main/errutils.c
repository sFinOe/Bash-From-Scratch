/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errutils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkasmi <zkasmi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 16:48:28 by sayar             #+#    #+#             */
/*   Updated: 2022/10/05 12:12:56 by zkasmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"
#include "../includes/expansion.h"
#include "../includes/parsing.h"
#include "../includes/redirection.h"
#include "../includes/buildin.h"

void	check_last_pipe(t_token *tmp)
{
	if (tmp->next == NULL && tmp->cmd_type == PIPE)
		g_code_status.err = 1;
}

int	ft_get_str(char *str, int i, int j, int k)
{
	while (str[++i])
	{
		if (str[i] == 39)
			j++;
		if (str[i] == 34)
			k++;
		if (k % 2 == 0 && j % 2 == 0)
		{
			if (str[i] == '<' && str[i + 1] == '<' && str[i + 2] == '<')
				return (1);
			if (str[i] == '>' && str[i + 1] == '>' && str[i + 2] == '>')
				return (1);
			if (str[i] == '<' && str[i + 1] == '>')
				return (1);
			if (str[i] == '>' && str[i + 1] == '<')
				return (1);
			if (str[i] == '|' && str[i + 1] == '|')
				return (1);
			if (str[i] == 92 || str[i] == ';')
				return (1);
		}
	}
	return (0);
}

int	str_check(char *str, int i)
{
	while (str[i])
	{
		if (str[i] == 32)
			i++;
		if (str[i] != 32 && str[i] != '|')
			break ;
		if (str[i] == '|')
			return (1);
	}
	return (0);
}

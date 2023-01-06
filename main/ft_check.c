/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkasmi <zkasmi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 10:43:26 by zkasmi            #+#    #+#             */
/*   Updated: 2022/10/09 18:05:24 by zkasmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"
#include "../includes/expansion.h"
#include "../includes/parsing.h"
#include "../includes/redirection.h"
#include "../includes/buildin.h"

int	check_output(char *str)
{
	int	i;

	i = -1;
	while (str[++i])
		if (str[i] == (int)-'>' && str[i + 1] == (int)-'>')
			return (1);
	return (0);
}

int	check_heredoc(char *str)
{
	int	i;

	i = -1;
	while (str[++i])
		if (str[i] == (int)-'<' && str[i + 1] == (int)-'<')
			return (1);
	return (0);
}

int	ft_lnksize(t_token *lst)
{
	t_token	*tmp;
	int		i;

	tmp = lst;
	i = 0;
	if (!tmp)
		return (0);
	while (tmp)
	{
		tmp = tmp->next;
		i++;
	}
	return (i);
}

int	ft_check_n(char *str)
{
	int		i;

	i = 0;
	while (str[++i])
	{
		if (str[i] != 'n')
			return (1);
	}
	return (0);
}

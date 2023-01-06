/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkasmi <zkasmi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 16:39:51 by sayar             #+#    #+#             */
/*   Updated: 2022/09/30 13:15:00 by zkasmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"
#include "../includes/expansion.h"
#include "../includes/parsing.h"
#include "../includes/redirection.h"
#include "../includes/buildin.h"

int	check_doc(char *str)
{
	int	i;

	i = -1;
	while (str[++i])
		if (str[i] == (int)-'<' && str[i + 1] == (int)-'<')
			return (1);
	return (0);
}

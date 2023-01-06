/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkasmi <zkasmi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 12:06:07 by zkasmi            #+#    #+#             */
/*   Updated: 2022/10/09 19:07:33 by zkasmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/parsing.h"

int	check_meta(char *line, int i)
{
	if (ft_strchr("<>|", line[i]) && quotes(line, i) == 0)
		return (1);
	else if (ft_strchr("<>|", line[i]))
		return (-1);
	else
		return (0);
}

int	quotes(char *line, int pos)
{
	int	i;
	int	status;

	i = 0;
	status = 0;
	while (line[i] && i != pos)
	{
		if (status == 0 && line[i] == '\"')
			status = 1;
		else if (status == 1 && line[i] == '\"')
			status = 0;
		else if (status == 0 && line[i] == '\'')
			status = 2;
		else if (status == 2 && line[i] == '\'')
			status = 0;
		i++;
	}
	return (status);
}

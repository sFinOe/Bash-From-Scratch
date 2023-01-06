/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkasmi <zkasmi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 18:03:13 by zkasmi            #+#    #+#             */
/*   Updated: 2022/10/09 18:53:52 by zkasmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/redirection.h"

int	check_rdr(char *str)
{
	int	i;

	i = -1;
	while (str[++i])
	{
		if (str[i] == (int)-'>')
			return (1);
		if (str[i] == (int)-'<')
			return (2);
	}
	return (0);
}

char	*unqouted(char *str1, int i, int j)
{
	while (str1[++i])
	{
		if (str1[i] == ' ')
			str1[i] = -str1[i];
		if (str1[i] == '\"' || str1[i] == '\'')
			j++;
		if (j % 2 != 0 && j != 0)
		{
			while (str1[++i])
			{
				if (str1[i] == '\"' || str1[i] == '\'')
				{
					j++;
					break ;
				}
			}
		}
	}
	return (str1);
}

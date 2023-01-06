/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkasmi <zkasmi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/07 17:39:57 by zkasmi            #+#    #+#             */
/*   Updated: 2022/10/09 18:54:23 by zkasmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_toupper(int c)
{
	if (c >= 'a' && c <= 'z')
	{
		c = c - 32;
	}
	return (c);
}

char	*ft_split_add(char **cmd)
{
	char	*line;
	char	*tmp;
	int		i;

	i = 0;
	tmp = ft_strdup("");
	while (cmd[i + 1] != NULL)
	{
		line = ft_strjoin3(cmd[i], (int)-' ');
		tmp = ft_strjoin(tmp, line);
		i++;
	}
	tmp = ft_strjoin(tmp, cmd[i]);
	return (tmp);
}

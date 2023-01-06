/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkasmi <zkasmi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/07 17:42:02 by zkasmi            #+#    #+#             */
/*   Updated: 2022/09/25 15:36:29 by zkasmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "../includes/minishell.h"

char	*ft_strdup(const char *s1)
{
	int		i;
	char	*tap;
	char	*ss1;

	if (!s1)
		return (NULL);
	ss1 = (char *)s1;
	i = 0;
	tap = (char *)s1;
	tap = ft_calloc(sizeof(char), ft_strlen(ss1)+1);
	if (tap == NULL)
		return (NULL);
	while (ss1[i])
	{
		tap[i] = ss1[i];
		i++;
	}
	tap[i] = '\0';
	return (tap);
}

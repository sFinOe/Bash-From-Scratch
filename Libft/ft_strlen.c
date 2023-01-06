/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkasmi <zkasmi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 11:19:43 by zkasmi            #+#    #+#             */
/*   Updated: 2022/09/25 15:36:31 by zkasmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "../includes/minishell.h"

size_t	ft_strlen(const char	*s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
	{
		i++;
	}
	return (i);
}

char	*ft_strjoin2(int c, char const *s2)
{
	char	*tab;

	if (!s2)
		return (0);
	tab = ft_calloc(sizeof(char), ft_strlen(s2) + 1 + 1);
	if (tab == NULL)
		return (NULL);
	tab[0] = c;
	tab = ft_strcpy2(tab, s2);
	return (tab);
}

char	*ft_strjoin3(char const *s1, int c)
{
	char	*tab;
	int		i;

	if (!s1)
		return (0);
	i = ft_strlen(s1);
	tab = ft_calloc(sizeof(char), ft_strlen(s1) + 1 + 1);
	if (tab == NULL)
		return (NULL);
	tab = ft_strcpy(tab, s1);
	tab[i] = c;
	tab[i + 1] = '\0';
	return (tab);
}

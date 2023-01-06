/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkasmi <zkasmi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 11:38:43 by zkasmi            #+#    #+#             */
/*   Updated: 2022/09/25 15:36:31 by zkasmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "../includes/minishell.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*tab;
	size_t	i;

	i = 0;
	if (!s)
		return (NULL);
	if (ft_strlen(s) < start)
	{
		start = ft_strlen(s);
		len = 0;
	}
	if (len > ft_strlen(s))
		len = ft_strlen(s) - start;
	tab = ft_calloc(sizeof(char), len + 1);
	if (tab == NULL)
		return (NULL);
	while (i < len)
	{
		tab[i] = s[start + i];
		i++;
	}
	tab[i] = '\0';
	return (tab);
}

char	*ft_substr2(char const *s, size_t start, size_t len)
{
	char	*tab;
	size_t	i;

	i = 0;
	if (!s)
		return (NULL);
	if (ft_strlen(s) < start)
	{
		start = ft_strlen(s);
		len = 0;
	}
	if (len > ft_strlen(s))
		len = ft_strlen(s) - start;
	tab = ft_calloc(sizeof(char), len + 2);
	if (tab == NULL)
		return (NULL);
	while (i < len)
	{
		tab[i] = s[start + i];
		i++;
	}
	tab[i] = '"';
	tab[i + 1] = '\0';
	return (tab);
}

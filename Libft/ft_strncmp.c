/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sayar <sayar@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/07 17:41:31 by zkasmi            #+#    #+#             */
/*   Updated: 2022/04/01 17:33:09 by sayar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *str1, const char *str2, size_t n)
{
	unsigned char	*p;
	unsigned char	*s;
	size_t			i;

	p = (unsigned char *)str1;
	s = (unsigned char *)str2;
	i = 0;
	while (i < n)
	{
		if (p[i] != s[i] || p[i] == 0 || s[i] == 0)
		{
			return (p[i] - s[i]);
		}
		i++;
	}
	return (0);
}

int	ft_strncmplus(const char *str1, const char *str2, size_t start, size_t len)
{
	char			*p;
	unsigned char	*s;
	size_t			i;

	if (!str1)
		return (4);
	if (!str2)
		return (4);
	p = ft_substr(str1, start, len);
	s = (unsigned char *)str2;
	i = 0;
	while (i < len)
	{
		if (p[i] != s[i] || p[i] == 0 || s[i] == 0)
			return (p[i] - s[i]);
		i++;
	}
	return (0);
}

int	ft_strncmplus2(const char *str1, const char *str2, size_t start, size_t len)
{
	char	*p;
	char	*s;
	size_t	i;

	if (!str1)
		return (4);
	if (!str2)
		return (4);
	p = ft_substr(str1, start, len);
	s = (char *)str2;
	if (ft_strlen(s) > ft_strlen(p))
		return (1);
	i = 0;
	while (i < len)
	{
		if (p[i] != s[i] || p[i] == 0 || s[i] == 0)
			return (p[i] - s[i]);
		i++;
	}
	return (0);
}

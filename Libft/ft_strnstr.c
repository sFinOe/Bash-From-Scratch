/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sayar <sayar@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/07 17:41:19 by zkasmi            #+#    #+#             */
/*   Updated: 2022/04/07 11:15:16 by sayar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strstr(char *str, char *to_find)
{
	int	i;
	int	j;

	i = 0;
	while (str[i] != '\0')
	{
		j = 0;
		while (to_find[j] == str[i + j])
		{
			if (to_find[j + 1] == '\0')
			{
				return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	char	*myp;
	char	*beman;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (!haystack || !needle)
		return (NULL);
	myp = (char *)haystack;
	beman = (char *)needle;
	if (ft_strlen(needle) == 0 || haystack == needle)
		return (myp);
	while (myp[i] && i < len)
	{
		while (myp[i + j] == beman[j] && beman[j])
			j++;
		if (i + j > len)
			return (0);
		else if (beman[j] == '\0')
			return (myp + i);
		j = 0;
		i++;
	}
	return (NULL);
}

char	*ft_strnstrplus(const char *haystack, const char *needle, size_t len)
{
	char	*myp;
	char	*beman;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (!haystack || !needle)
		return (NULL);
	myp = ft_strdup((char *)haystack);
	beman = (char *)needle;
	if (ft_strlen(needle) == 0 || haystack == needle)
		return (myp);
	while (myp[i] && i < len)
	{
		while (myp[i + j] == beman[j] && beman[j])
			j++;
		if (i + j > len)
			return (0);
		else if (beman[j] == '\0')
			return (myp + i);
		j = 0;
		i++;
	}
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkasmi <zkasmi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/07 17:41:09 by zkasmi            #+#    #+#             */
/*   Updated: 2021/11/17 18:58:01 by zkasmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	*holder;

	holder = NULL;
	i = 0;
	while (s[i])
	{
		if (s[i] == (char)c)
		{
			holder = (char *)s + i;
		}
		i++;
	}
	if (s[i] == (char)c)
	{
		holder = (char *)s + i;
	}
	return (holder);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkasmi <zkasmi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 16:18:36 by zkasmi            #+#    #+#             */
/*   Updated: 2022/09/25 15:36:28 by zkasmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "../includes/minishell.h"

int	tab_sizer(long int n)
{
	int			sizer;
	long int	num;

	num = n;
	sizer = 0;
	while (num > 0)
	{
		num = num / 10;
		sizer ++;
	}
	return (sizer);
}

char	*ifpos(long int num)
{
	int		i;
	char	*tab;

	i = tab_sizer(num);
	tab = ft_calloc(sizeof(char), i + 1);
	if (tab == NULL)
	{
		return (NULL);
	}
	tab[i] = '\0';
	i--;
	while (num > 0 && i >= 0)
	{
		tab[i] = num % 10 + '0';
		num = num / 10;
		i--;
	}
	return (tab);
}

char	*ifnega(long int num)
{
	int		i;
	char	*tab;

	num = num * (-1);
	i = tab_sizer(num);
	tab = ft_calloc(sizeof(char), i + 2);
	if (tab == NULL)
	{
		return (NULL);
	}
	tab[i + 1] = '\0';
	tab[0] = '-';
	while (num > 0 && i >= 0)
	{
		tab[i] = num % 10 + '0';
		num = num / 10;
		i--;
	}
	return (tab);
}

char	*ft_itoa(int n)
{
	long int	num;
	char		*tab;

	num = n;
	if (num == -0 || num == 0)
	{
		tab = ft_calloc(sizeof(char), 2);
		if (tab == NULL)
		{
			return (NULL);
		}
		tab[0] = 0 + '0';
		tab[1] = '\0';
		return (tab);
	}
	else if (num < 0)
		return (ifnega(num));
	else if (num > 0)
		return (ifpos(num));
	return (0);
}

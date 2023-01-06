/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hex.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sayar <sayar@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 20:12:48 by zkasmi            #+#    #+#             */
/*   Updated: 2022/04/01 17:29:32 by sayar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_perror.h"

int	puthexlow(unsigned int nb, int *len)
{
	char	*s;

	s = "0123456789abcdef";
	if (nb < 16)
	{
		ft_putchar(s[nb]);
		(*len)++;
	}
	else
	{
		puthexlow(nb / 16, len);
		puthexlow(nb % 16, len);
	}
	return (0);
}

int	puthexup(unsigned int nb, int *len)
{
	char	*s;

	s = "0123456789ABCDEF";
	if (nb < 16)
	{
		ft_putchar(s[nb]);
		(*len)++;
	}
	else
	{
		puthexup(nb / 16, len);
		puthexup(nb % 16, len);
	}
	return (0);
}

int	hexpointer(long unsigned int nb, int *len)
{
	char	*s;

	s = "0123456789abcdef";
	if (nb < 16)
	{
		ft_putchar(s[nb]);
		(*len)++;
	}
	else
	{
		hexpointer(nb / 16, len);
		hexpointer(nb % 16, len);
	}
	return (0);
}

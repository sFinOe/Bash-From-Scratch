/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkasmi <zkasmi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 20:10:16 by zkasmi            #+#    #+#             */
/*   Updated: 2021/11/30 14:57:26 by zkasmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_perror.h"

int	ft_putnbr(int nb, int *len)
{
	long	num;

	num = nb;
	if (num < 0)
	{
		ft_putchar('-');
		(*len)++;
		num = num * (-1);
	}
	if (num >= 0 && num <= 9)
	{
		ft_putchar(num + '0');
		(*len)++;
	}
	if (num >= 10)
	{
		ft_putnbr(num / 10, len);
		ft_putchar((num % 10) + '0');
		(*len)++;
	}
	return (0);
}

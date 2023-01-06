/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_u.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkasmi <zkasmi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 20:09:47 by zkasmi            #+#    #+#             */
/*   Updated: 2022/09/28 17:32:05 by zkasmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_perror.h"

int	ft_putnbr_u(unsigned int nb, int *len)
{
	unsigned int	num;

	num = nb;
	if ((int)num < 0)
	{
		ft_putchar('-');
		(*len)++;
		num = num * (-1);
	}
	if ((int)num >= 0 && (int)num <= 9)
	{
		ft_putchar(num + '0');
		(*len)++;
	}
	if (num >= 10)
	{
		ft_putnbr_u(num / 10, len);
		ft_putchar((num % 10) + '0');
		(*len)++;
	}
	return (0);
}

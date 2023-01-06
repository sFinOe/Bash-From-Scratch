/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkasmi <zkasmi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 20:07:26 by zkasmi            #+#    #+#             */
/*   Updated: 2021/11/30 14:59:40 by zkasmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_perror.h"

void	selector(const char *format, va_list ap, size_t i, int *len)
{
	if (format[i] == 'd' || format[i] == 'i')
		(*len) += ft_putnbr(va_arg(ap, int), len);
	if (format[i] == 's')
		(*len) += ft_putstr(va_arg(ap, char *));
	if (format[i] == 'c')
		(*len) += ft_putchar(va_arg(ap, int));
	if (format[i] == 'u')
		(*len) += ft_putnbr_u(va_arg(ap, unsigned int), len);
	if (format[i] == 'x')
		(*len) += puthexlow(va_arg(ap, unsigned int), len);
	if (format[i] == 'X')
		(*len) += puthexup(va_arg(ap, unsigned int), len);
	if (format[i] == '%')
		(*len) += ft_putchar('%');
	if (format[i] == 'p')
	{
		ft_putstr("0x");
		(*len)++;
		(*len)++;
		hexpointer(va_arg(ap, long unsigned int), len);
	}
}

int	ft_perror(const char *format, ...)
{
	size_t	i;
	int		len;
	va_list	ap;

	if (!format)
		return (0);
	va_start(ap, format);
	i = 0;
	len = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			selector(format, ap, i, &len);
		}
		else
		{
			ft_putchar(format[i]);
			len++;
		}
		i++;
	}
	va_end(ap);
	return (len);
}

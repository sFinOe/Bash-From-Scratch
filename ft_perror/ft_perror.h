/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkasmi <zkasmi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 20:10:31 by zkasmi            #+#    #+#             */
/*   Updated: 2021/11/30 14:59:56 by zkasmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PERROR_H
# define FT_PERROR_H

# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

size_t	ft_strlen(const char	*s);
int		ft_putnbr(int nb, int *len);
int		ft_putchar(char c);
int		ft_putstr(char *str);
int		ft_putnbr_u(unsigned int nb, int *len);
int		puthexlow(unsigned int nb, int *len);
int		puthexup(unsigned int nb, int *len);
int		hexpointer(long unsigned int nb, int *len);
int		ft_perror(const char *format, ...);

#endif
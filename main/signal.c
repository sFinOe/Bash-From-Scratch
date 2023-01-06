/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkasmi <zkasmi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 15:51:01 by zkasmi            #+#    #+#             */
/*   Updated: 2022/10/04 17:37:56 by zkasmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"
#include "../includes/expansion.h"
#include "../includes/parsing.h"
#include "../includes/redirection.h"
#include "../includes/buildin.h"

void	handler2(int arg)
{
	(void)arg;
	rl_redisplay();
}

void	handler(int arg)
{
	(void)arg;
	ft_putstr_fd("\n", 1);
	rl_replace_line("", 0);
	rl_on_new_line();
	rl_redisplay();
	g_code_status.codestatus = 1;
}

void	signalinit(void)
{
	signal(SIGINT, handler);
	signal(SIGQUIT, handler2);
}

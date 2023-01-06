/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fork.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkasmi <zkasmi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 15:53:46 by zkasmi            #+#    #+#             */
/*   Updated: 2022/10/04 18:09:27 by zkasmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"
#include "../includes/expansion.h"
#include "../includes/parsing.h"
#include "../includes/redirection.h"
#include "../includes/buildin.h"

void	ft_parent(t_data *data, int *fd)
{
	signal(SIGINT, SIG_IGN);
	close(fd[1]);
	if (data->fdd)
		close(data->fdd);
	data->fdd = fd[0];
	g_code_status.r_err = 0;
}

int	ft_fork(t_data *data, int k, int *fd)
{
	data->pid[k] = fork();
	if (data->pid[k] == -1)
	{
		perror("fork");
		exit(1);
	}
	else if (data->pid[k] == 0)
	{
		if (g_code_status.r_err == 1)
			exit(1);
		create_rdr_heredoc(data, k, fd);
		create_rdr_output(data, k);
		create_rdr_input(data, k, fd);
		close(fd[0]);
		ft_execve(data);
	}
	else
	{
		ft_parent(data, fd);
		k++;
	}
	return (k);
}

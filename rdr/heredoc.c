/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkasmi <zkasmi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 09:44:07 by zkasmi            #+#    #+#             */
/*   Updated: 2022/10/04 19:04:05 by zkasmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/redirection.h"

void	heredoc_handler(int sig)
{
	(void)sig;
	rl_done = 1;
	g_code_status.h_lock = 1;
}

int	event(void)
{
	return (0);
}

char	*heredoc_expansion(char *str, t_data *data)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '$')
			str[i] = -str[i];
		i++;
	}
	str = expansion(str, data, g_code_status.codestatus);
	return (str);
}

int	rl_loop(t_data *data, char *str)
{
	str = readline("> ");
	collect_adr(str);
	if (g_code_status.h_lock == 1)
	{
		data->filefd = open("/tmp/hererdoc",
				O_CREAT | O_RDWR | O_TRUNC, 0644);
		return (1);
	}
	if (!str || ft_strcmp(str, data->rdr_input) == 0)
		return (1);
	if (ft_strcmp(str, data->rdr_input) != 0)
	{
		if (g_code_status.h_exp == 0)
			str = heredoc_expansion(str, data);
		write(data->filefd, str, strlen(str));
		write(data->filefd, "\n", 1);
	}
	return (0);
}

void	heredoc(t_data *data)
{
	char	*str;

	str = NULL;
	rl_event_hook = event;
	signal(SIGINT, heredoc_handler);
	wait(0);
	data->filefd = open("/tmp/hererdoc", O_CREAT | O_RDWR | O_TRUNC, 0644);
	if (data->filefd < 0)
		ft_strerror(data, 1);
	while (1)
	{
		if (rl_loop(data, str))
			break ;
	}
	g_code_status.h_exp = 0;
	close(data->filefd);
}

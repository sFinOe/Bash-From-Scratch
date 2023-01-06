/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_rdr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkasmi <zkasmi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 15:48:58 by zkasmi            #+#    #+#             */
/*   Updated: 2022/10/03 12:33:18 by zkasmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/redirection.h"

void	rdr_parse(t_data *data, int k)
{
	data->k = k;
	while (check_rdr(data->cmd_line[k]) == 2
		|| check_rdr(data->cmd_line[k]) == 1)
	{
		if (check_rdr(data->cmd_line[k]) == 2)
			rdr_input(data->cmd_line[k], data, k);
		if (check_rdr(data->cmd_line[k]) == 1)
			rdr_output(data->cmd_line[k], data, k);
	}
}

void	create_rdr_input(t_data *data, int k, int *fd)
{
	if (ft_strchr(data->tmp_input[k], (int)-'<') != 0 && data->rdr_input)
	{
		if (!(check_heredoc(data->tmp_input[k]) == 1))
		{
			dup2(fd[0], 0);
			close(fd[0]);
			data->filefd = open(data->rdr_input, O_RDONLY, 0666);
			if (data->filefd < 0)
			{
				ft_strerror(data, 1);
				exit(1);
			}
			dup2(data->filefd, 0);
			close(data->filefd);
			data->rdr_input = NULL;
		}
	}
}

void	create_rdr_heredoc(t_data *data, int k, int *fd)
{
	if (ft_strchr(data->tmp_input[k], (int)-'<') != 0 && data->rdr_input)
	{
		if ((check_heredoc(data->tmp_input[k])) == 1)
		{
			data->filefd = open("/tmp/hererdoc", O_RDONLY, 0666);
			if (data->filefd < 0)
				ft_strerror(data, 1);
			dup2(fd[0], 0);
			dup2(data->filefd, 0);
		}
	}
	if (!(data->tmp_input[k + 1] == NULL
			&& check_doc(data->tmp_input[k]) == 1))
	{
		dup2(data->fdd, 0);
		if (data->cmd_line[k + 1] != NULL)
		{
			dup2(fd[1], 1);
			close(fd[1]);
		}
	}
}

void	create_rdr_output(t_data *data, int k)
{
	if (ft_strchr(data->tmp_input[k], (int)-'>') != 0 && data->rdr_output)
	{
		if ((check_output(data->tmp_input[k])) == 1)
		{
			data->filefd = open(data->rdr_output, O_RDWR
					| O_CREAT | O_APPEND, 0666);
			if (data->filefd < 0)
				ft_strerror(data, 1);
		}
		else
			data->filefd = open(data->rdr_output, O_RDWR
					| O_CREAT | O_TRUNC, 0666);
		if (data->filefd < 0)
			ft_strerror(data, 1);
		dup2(data->filefd, 1);
		close(data->filefd);
		data->rdr_output = NULL;
	}
}

void	rdr_heredoc(t_data *data, int k)
{
	if (ft_strchr(data->tmp_input[k], (int)-'<') != 0 && data->rdr_input)
		if ((check_heredoc(data->tmp_input[k])) == 1)
			heredoc(data);
}

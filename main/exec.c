/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkasmi <zkasmi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 17:06:11 by sayar             #+#    #+#             */
/*   Updated: 2022/10/04 17:43:32 by zkasmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"
#include "../includes/expansion.h"
#include "../includes/parsing.h"
#include "../includes/redirection.h"
#include "../includes/buildin.h"

int	pipecheck(char *input)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (input[i])
	{
		if (input[i] == '|')
			j++;
		i++;
	}
	return (j);
}

t_data	*init(int ac, char **av)
{
	t_data	*data;

	(void)ac;
	(void)av;
	data = ft_calloc(sizeof(t_data), 1);
	data->shlvl = 0;
	g_code_status.h_lock = 0;
	g_code_status.err = 0;
	g_code_status.r_err = 0;
	g_code_status.h_exp = 0;
	return (data);
}

int	path_count(char *str)
{
	int	i;
	int	j;

	i = -1;
	j = 0;
	while (str[++i])
	{
		if (str[i] == ':')
			j++;
	}
	return (j);
}

char	*path_exec(t_data *data, char *line)
{
	int		i;
	int		l;

	line = get_line(data, line);
	if ((access(line, X_OK)) == 0)
	{
		data->path_exec = ft_strdup(line);
		return (data->path_exec);
	}
	if (ft_isalnum(line[0]) == 0)
		return (NULL);
	i = -1;
	while (data->envp[++i])
		if (ft_strncmp(data->envp[i], "PATH=", 5) == 0)
			break ;
	if (data->envp[i] == NULL)
	{
		data->path_exec = NULL;
		return (data->path_exec);
	}
	data->tmp_path = ft_split(data->envp[i], ':');
	l = path_count(data->envp[i]) + 1;
	data->bin_path = ft_calloc(sizeof(char *), l + 1);
	check_path(data, l, line);
	return (data->path_exec);
}

void	exec(char *input, t_data *data)
{
	int		fd[2];
	int		k;

	data->fdd = 0;
	data->pid = ft_calloc(sizeof(pid_t), pipecheck(input) + 1);
	if (ft_get_error(input) == 1 || g_code_status.err == 1)
	{
		g_code_status.err = 0;
		ft_perror("syntax error near unexpected token\n");
		g_code_status.codestatus = 2;
		return ;
	}
	data->cmd_line = ft_split(data->inpt, (int)-'|');
	data->tmp_input = ft_split(data->inpt, (int)-'|');
	k = 0;
	while (data->cmd_line[k] != NULL)
	{
		rdr_parse(data, k);
		bin_path(data, k);
		if (g_code_status.h_lock == 1)
			break ;
		pipe(fd);
		k = ft_fork(data, k, fd);
	}
}

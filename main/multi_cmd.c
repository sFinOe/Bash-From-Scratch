/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   multi_cmd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkasmi <zkasmi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 10:08:04 by zkasmi            #+#    #+#             */
/*   Updated: 2022/10/09 18:02:13 by zkasmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"
#include "../includes/expansion.h"
#include "../includes/parsing.h"
#include "../includes/redirection.h"
#include "../includes/buildin.h"

void	multi_cmd(char *input, t_data *data)
{
	int	i;

	data->rdr_output = NULL;
	data->rdr_input = NULL;
	exec(input, data);
	i = 0;
	while (data->pid[i] && data->pid[0] != 0)
	{
		waitpid(data->pid[i], &g_code_status.wstatus, 0);
		i++;
	}
	if (WTERMSIG(g_code_status.wstatus) == SIGINT)
	{
		g_code_status.codestatus = 130;
		write(1, "\n", 1);
	}
	if (WTERMSIG(g_code_status.wstatus) == SIGQUIT)
	{
		g_code_status.codestatus = 131;
		write(1, "Quit: 3\n", 8);
	}
	else if (WIFEXITED(g_code_status.wstatus)
		&& g_code_status.plock == 0 && data->pid[0] != 0)
		g_code_status.codestatus = WEXITSTATUS(g_code_status.wstatus);
	g_code_status.plock = 0;
}

int	check_pipe(t_data *data)
{
	t_token	*tmp;

	tmp = data->tokens;
	while (tmp)
	{
		if (tmp->cmd_type == 6)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

int	buidin(t_data *data)
{
	int	i;

	i = 0;
	while (data->inpt[i])
	{
		if (data->inpt[i] == (int)-'<' || data->inpt[i] == (int)-'>')
			return (0);
		i++;
	}
	if (ft_strcmp(data->cmd[0], "echo") == 0)
		return (1);
	else if (ft_strcmp(data->cmd[0], "pwd") == 0)
		return (1);
	else if (ft_strcmp(data->cmd[0], "export") == 0)
		return (1);
	else if (ft_strcmp(data->cmd[0], "env") == 0)
		return (1);
	else if (ft_strcmp(data->cmd[0], "unset") == 0)
		return (1);
	else if (ft_strcmp(data->cmd[0], "cd") == 0)
		return (1);
	return (0);
}

void	minishell(char *input, t_data *data)
{
	char	**line;
	int		i;

	i = 0;
	if (ft_strcmp(input, "") != 0 && input != NULL && ft_isspace(input))
	{
		if (check_exit(input, data))
			return ;
		data->cmd = parsing(input, data);
		line = sep_modifier(data->tokens);
		while (line[i])
		{
			line[i] = expansion(line[i], data, g_code_status.codestatus);
			i++;
		}
		data->inpt = ft_split_add(line);
		if (data->cmd[0])
		{
			if (check_pipe(data) == 0 && buidin(data))
				simple_cmd(data->inpt, data->cmd, data);
			else
				multi_cmd(input, data);
		}
		g_code_status.h_lock = 0;
	}
}

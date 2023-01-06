/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expansion.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkasmi <zkasmi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 15:02:06 by zkasmi            #+#    #+#             */
/*   Updated: 2022/10/09 18:26:45 by zkasmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/expansion.h"

int	exp_len(const char *line, int exit, t_data *data)
{
	int		i;
	int		size;

	i = -1;
	size = 0;
	while (line[++i])
	{
		if (line[i] == (int)-'$')
		{
			i++;
			if ((line[i] == '\0' || ft_isalnum(line[i]) == 0) && line[i] != '?')
				size++;
			else
				size += expansion_len(line, i, data, exit);
			if (ft_isdigit(line[i]) == 0)
			{
				while (next_exp(line, i))
					i++;
			}
			else
				size--;
		}
		size++;
	}
	return (size);
}

char	*get_env_value(const char *line, int pos, t_data *data)
{
	char	var_name[BUFF_SIZE];
	char	*var_value;
	int		i;

	i = 0;
	if (line[pos] == '?')
	{
		var_value = ft_itoa(g_code_status.codestatus);
		return (var_value);
	}
	if (ft_isdigit(line[pos]))
		return (NULL);
	while (line[pos] && ft_is_char(line[pos]) == 1 && i < BUFF_SIZE)
	{
		var_name[i] = line[pos];
		pos++;
		i++;
	}
	var_name[i] = '\0';
	data->tmp_line = ft_strdup(var_name);
	data->tmp_line_1 = ft_strjoin("$", data->tmp_line);
	var_value = expansion_line(data->tmp_line_1, data);
	return (var_value);
}

int	copy_env_value(char *line, const char *value, int pos)
{
	int		i;

	i = 0;
	while (value[i])
		line[pos++] = value[i++];
	return (i);
}

void	set_dollar_env(t_cmd *exp, char *line, t_data *data)
{
	char	*env_value;

	env_value = get_env_value(line, exp->j, data);
	if (env_value)
		exp->i += copy_env_value(exp->str, env_value, exp->i);
	else
		exp->i += 0;
	if (line[exp->j] == '?')
		exp->j++;
	if (ft_isdigit(line[exp->j]) == 0)
	{
		while (ft_is_char(line[exp->j]) == 1)
			exp->j++;
	}
}

char	*expansion(char *cmd, t_data *data, int exit)
{
	t_cmd	exp;
	int		len;

	len = exp_len(cmd, exit, data);
	exp.str = ft_calloc(sizeof(char), len + 1);
	exp.i = 0;
	exp.j = 0;
	while (exp.i < len && cmd[exp.j])
	{
		while (cmd[exp.j] == (int)-'$')
		{
			exp.j++;
			if ((cmd[exp.j] == '\0' || ft_isalnum(cmd[exp.j]) == 0)
				&& cmd[exp.j] != '?')
				exp.str[exp.i++] = '$';
			else
				set_dollar_env(&exp, cmd, data);
		}
		exp.str[exp.i++] = cmd[exp.j++];
	}
	exp.str[exp.i] = '\0';
	return (exp.str);
}

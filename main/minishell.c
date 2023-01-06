/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkasmi <zkasmi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 18:57:00 by zkasmi            #+#    #+#             */
/*   Updated: 2022/10/08 18:12:57 by zkasmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"
#include "../includes/expansion.h"
#include "../includes/parsing.h"
#include "../includes/redirection.h"
#include "../includes/buildin.h"

t_code_status	g_code_status;

void	arg_error(void)
{
	ft_perror("Only 1 arg required\n");
	exit (1);
}

int	main(int ac, char **av, char **envp)
{
	t_data	*data;
	t_env	*env;

	if (ac > 1)
		arg_error();
	rl_catch_signals = 0;
	data = init(ac, av);
	env = set_env(data, envp);
	ft_env(data);
	data->exp = set_export(data);
	ft_set_pwd(data);
	ft_shlvl(data);
	pwd(data);
	signalinit();
	while (1)
	{
		signalinit();
		ft_env(data);
		ft_readline(data);
		if (data->inpt && ft_strcmp(data->inpt, "") != 0
			&& ft_space(data->inpt) == 1)
			add_history(data->inpt);
		minishell(data->inpt, data);
	}
	return (free_adr(), 0);
}

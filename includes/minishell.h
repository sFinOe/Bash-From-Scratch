/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkasmi <zkasmi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 16:02:44 by zkasmi            #+#    #+#             */
/*   Updated: 2022/10/05 16:04:26 by zkasmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# define BUFF_SIZE 4096
# define INTMAX 2147483647
# define NINTMAX -2147483648
# define EMPTY 0
# define CMD 1
# define ARG 2
# define TRUNC 3
# define APPEND 4
# define INPUT 5
# define HEREDOC 7
# define PIPE 6
# define QUOTED_S 8
# define QUOTED_D 9
# define UNQUOTED 10

# include <dirent.h>
# include <stdio.h>
# include <signal.h>
# include <fcntl.h>
# include <sys/wait.h>
# include <readline/readline.h>
# include <readline/history.h>
# include "../Libft/libft.h"
# include "../ft_perror/ft_perror.h"

typedef struct s_token
{
	char			*str;
	int				cmd_type;
	struct s_token	*prev;
	struct s_token	*next;
}				t_token;

typedef struct s_env
{
	char			*data;
	struct s_env	*next;
}	t_env;

typedef struct s_export
{
	char			*data;
	struct s_export	*next;
}	t_export;

typedef struct s_adr
{
	char			*ptr;
	struct s_adr	*next;
}	t_adr;

typedef struct s_data
{
	pid_t				*pid;
	char				**cmd;
	char				**path;
	char				**line;
	char				**cmd_line;
	char				**envp;
	char				**rdr_line;
	char				**tmp_path;
	char				**bin_path;
	char				**tmp_input;
	char				*inpt;
	char				*pwd;
	char				*rdr_output;
	char				*rdr_input;
	char				*tocheck;
	char				*value;
	char				*name;
	char				*msg;
	char				*cmd_echo;
	char				*tmp_line;
	char				*tmp_line_1;
	char				*tmp_line_2;
	char				*tmp_line_3;
	char				*tmp_line_4;
	char				*quotes_line;
	char				*tmp_export;
	char				*tmp_export_1;
	char				*s;
	char				*s2;
	char				*s3;
	char				*home;
	char				*path_exec;
	char				*tmp;
	char				*file_path;
	int					*fd;
	int					fdd;
	int					filefd;
	int					elock;
	int					k;
	int					shlvl;
	int					echohere;
	struct s_token		*tokens;
	struct s_export		*exp;
	struct s_env		*env;

}	t_data;

typedef struct s_code_status
{
	int					codestatus;
	int					wstatus;
	int					plock;
	int					err;
	int					r_err;
	int					h_lock;
	int					h_exp;
	struct s_adr		*adr;
}	t_code_status;

t_data				*init(int ac, char **av);
void				exec(char *input, t_data *data);
void				minishell(char *input, t_data *data);
void				signalinit(void);
void				check_path(t_data *data, int l, char *line);
void				ft_execve(t_data *data);
void				ft_parent(t_data *data, int *fd);
void				export_value(t_data *data, char *str);
void				ft_strerror(t_data *data, int check);
void				env_old_pwd(t_env *tmp, char *s, char *pwd);
void				change_env_pwd(t_env *tmp, t_data *data, char *pwd);
void				simple_cmd(char *input, char **cmd, t_data *data);
void				multi_cmd(char *input, t_data *data);
void				ft_readline(t_data *data);
void				print_pwd(t_data *data);
void				ft_handle_error(t_data *data);
void				collect_adr(void *ptr);
void				free_adr(void);
void				*ft_calloc(size_t count, size_t size);
void				check_last_pipe(t_token *tmp);
void				bin_path(t_data *data, int k);
char				*path_exec(t_data *data, char *line);
char				*get_line(t_data *data, char *line);
int					check_output(char *str);
int					pipecheck(char *input);
int					check_heredoc(char *str);
int					ft_space(char *input);
int					check_doc(char *str);
int					ft_get_error(char *str);
int					ft_get_str(char *str, int i, int j, int k);
int					str_check(char *str, int i);
int					get_rdr_output(char *input1);
int					ft_fork(t_data *data, int k, int *fd);
int					check_meta(char *line, int i);
int					check_exit(char *input, t_data *data);
int					ft_lnksize(t_token *lst);
int					ft_check_n(char *str);

extern t_code_status	g_code_status;

#endif
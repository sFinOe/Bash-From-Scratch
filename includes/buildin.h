/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buildin.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkasmi <zkasmi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 15:52:00 by zkasmi            #+#    #+#             */
/*   Updated: 2022/09/30 13:02:05 by zkasmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILDIN_H
# define BUILDIN_H

# include "minishell.h"
# include "expansion.h"
# include "parsing.h"
# include "redirection.h"

char				*ft_get_env(t_data *data, char *name);
void				ft_change_pwd(t_data *data);
void				ft_change_pwd_export(t_data *data);
void				ft_set_pwd(t_data *data);
void				ft_set_pwd_export(t_data *data);
void				change_export_pwd(t_export *tmp, t_data *data,
						char *pwd);
void				change_export_old_pwd(t_export *tmp,
						t_export *tmp2, t_data *data);
void				set_export_pwd(t_export *tmp, t_data *data, char *pwd);
void				set_export_old_pwd(t_export *tmp, t_data *data, char *pwd);
void				cd_utils(t_data *data, DIR *dir);
void				get_pwd(t_env *tmp, t_data *data,
						char *pwd);
void				change_env_old_pwd(t_env *tmp, t_env *tmp2,
						t_data *data);
void				ft_cd(t_data *data);
int					ft_echo(char *line, t_data *data);
char				*ft_split_join(char **cmd);
int					check_eq(t_data *data);
int					check_export(t_data *data);
int					export_bool(char *name, char *str);
char				*change_value(char *str);
int					expo_checker(char *str);
void				export_value(t_data *data, char *str);
void				change_export_value(t_data *data, int i, int j, char *str);
int					get_eq(char *str);
int					check_env(t_data *data);
int					check_env_name(char *name, char *str);
void				ft_export(t_data *data);
void				ft_env(t_data *data);
void				print_env(t_data *data);
void				print_export(t_data *data);
int					ft_exit(t_data *data);
void				all_env(t_data *data);
void				pwd(t_data *data);
void				ft_shlvl(t_data *data);
struct s_export		*set_export(t_data *data);
struct s_env		*set_env(t_data *data, char **envp);
t_env				*env_delt(t_env *etmp);
t_export			*expo_delt(t_export *xtmp);
void				delete_lst(t_data *data, char *name);
void				ft_unset(char **cmd, t_data *data);

#endif
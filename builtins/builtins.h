/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhasmi <lhasmi@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 17:48:35 by lhasmi            #+#    #+#             */
/*   Updated: 2023/08/04 23:40:29 by lhasmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTINS_H
# define BUILTINS_H

# include "../include/minishell.h"

// Built-in command function pointer type
typedef int			(*t_builtin_func)(char **);

// Built-in command struct
typedef struct s_builtin
{
	char			*name;
	t_builtin_func	func;
}					t_builtin;

char				**get_builtins(void);

int					is_builtin(char *cmd);

int					ft_echo(int argc, ...);
int					ft_cd(int argc, t_env *env, ...);
void				ft_pwd(void);
int					ft_export(char **args);
int					ft_unset(char **args);
void				ft_env(char **args);
void				ft_exit(char **args, int *exit_status);

#endif

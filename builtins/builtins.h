/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhasmi <lhasmi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 17:48:35 by lhasmi            #+#    #+#             */
/*   Updated: 2023/08/06 22:00:23 by lhasmi           ###   ########.fr       */
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

int					is_builtin(t_list *node);
// iterates over the argv array looking for command-line options (specifically,
// the -n option for echo).
int					parse_echo_options(char **argv, int *i);
int					ft_echo(t_piper *pip, t_node *node);
int					ft_cd(t_piper *pip, t_node *node);
// void				ft_pwd(void);
// int					ft_export(char **args);
// int					ft_unset(char **args);
int					ft_exit(t_piper *pip, t_node *node);
void				ft_env(t_piper *pip);
// int					ft_export(t_piper *pip, t_node *node);
// int					ft_unset(t_piper *pip, t_node *node);
// int					ft_pwd(t_piper *pip, t_node *node);

#endif

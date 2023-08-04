/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   envtable.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhasmi <lhasmi@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 21:45:24 by lhasmi            #+#    #+#             */
/*   Updated: 2023/08/04 10:24:57 by lhasmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENVTABLE_H
# define ENVTABLE_H

# include "../include/minishell.h"

// I need to create a linked list to store the env variables,
// each node having the name of the variable (name) and the value of the variable (value) and
// a flag to know if the variable is owned by me (is_owned) meaning allocated by me
// also a flag to know if the variable is exported or not (is_exported) because
// I need to know if I can printit in the table or not
typedef struct s_env
{
	char			*name;
	char			*value;
	int				is_owned;
	int				is_exported;
	struct s_env	*next;
}					t_env;

// Returns the name of the environment variable.
char				*get_env_name(char *env);
// Returns the value of the environment variable.
char				*get_env_value(char *env);
t_env				*init_env_table(char **envp);
void				print_env_table(t_env *env);
t_env				*add_env_var(t_env *head, char *name, char *value, int is_owned, int is_exported);
t_env				*env_lookup(char *str, t_env *env);
void				env_update(t_env *env, char *new_val, char *name);

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   envtable_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhasmi <lhasmi@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 21:32:46 by lhasmi            #+#    #+#             */
/*   Updated: 2023/08/04 09:51:07 by lhasmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

// The get_env_name and get_env_value functions:
// I need to implement these functions such that they correctly split the
// environment string (in the form of key=value) into key and value respectively.
// I also need to make sure that they correctly handle the case where there is no
// 		value (i.e. the environment variable is not assigned a value).
// 		key (i.e. the environment variable is not assigned a key).
// 		equal sign (i.e. the environment variable is not assigned a value).
// 		environment variable (i.e. the environment variable is not assigned a key or a value).

// Returns the name of the environment variable.
char *get_env_name(char *env)
{
	int i;
	char *name;

	if (env == NULL)
		return NULL;
	i = 0;
	while (env[i] != '\0' && env[i] != '=')
		i++;
	if (i == 0)
		return NULL;
	name = ft_substr(env, 0, i);
	return (name);
}

// Returns the value of the environment variable.
char *get_env_value(char *env)
{
	int i;
	char *value;

	if (env == NULL)
		return NULL;
	i = 0;
	while (env[i] != '\0' && env[i] != '=')
		i++;

	if (env[i] != '=' || env[i+1] == '\0')
		return NULL;
	value = ft_substr(env, i + 1, ft_strlen(env) - i - 1);
	return (value);
}

t_env *env_lookup(char *str, t_env *env)
{
	if (!str || !env)
		return (NULL);
	while (env)
	{
		if (ft_strcmp(env->name, str) == 0)
			return (env);
		// Move to the next environment variable in the list.
		env = env->next;
	}
	// If no match is found, return NULL.
	return (NULL);
}

void env_update(t_env *env, char *new_val, char *name)
{
    // Look up the environment variable by its name
    env = env_lookup(name, env);
    // If the environment variable does not exist in the list, create a new node
    // and append it to the end. Here, 0 and 1 are default values for is_owned and is_exported
    if (!env)//here add only is_exported and decide for is_owned
        env = add_env_var(env, name, new_val, 0, 1);
    else // If it does exist, update the value of the environment variable
    {
        // Free the old value if it is owned by the structure
        if (env->is_owned)
            free(env->value);
        // Replace the old value with the new one
        env->value = new_val;
    }
}


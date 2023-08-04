/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   envtable.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhasmi <lhasmi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 21:47:03 by lhasmi            #+#    #+#             */
/*   Updated: 2023/08/01 21:45:13 by lhasmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"
#include "../include/minishell.h"

// Initializes the environment table by looping over the env variables and
// assigning them as values to each node of the linked list.
t_env *init_env_table(char **envp)
{
	int i;
	char *name;
	char *value;
	int is_owned;
	int is_exported;
	t_env *head = NULL;

	i = 0;
	while (envp[i])
	{
		name = get_env_name(envp[i]);
		value = get_env_value(envp[i]);
		is_owned = 0;
		is_exported = 1;
		head = add_env_var(head, name, value, is_owned, is_exported);
		i++;
	}
	return head;
}

// Creates a new environment variable node and returns it.
t_env *create_env_node(char *name, char *value, int is_owned, int is_exported)
{
	t_env *env;

	env = (t_env *)malloc(sizeof(t_env));
	if (!env)
		return (NULL);
	env->name = name;
	env->value = value;
	env->is_owned = is_owned;
	env->is_exported = is_exported;
	env->next = NULL;
	return (env);
}

// Appends a new environment variable to the linked list.
t_env *add_env_var(t_env *head, char *name, char *value, int is_owned, int is_exported)
{
	t_env *env;
	t_env *new_node;

	// Create a new node for the new environment variable
	new_node = create_env_node(name, value, is_owned, is_exported);
	if (!new_node)
		return head;

	if (head == NULL)// If the list is empty, new_node is the head.
		head = new_node;
	else// Find the end of the linked list and append the new node.
	{
		env = head;
		while (env->next)
			env = env->next;
		env->next = new_node;
	}
	return head;
}

// Prints the environment table to the standard output.
void print_env_table(t_env *env)
{
	while (env)
	{
		if (env->is_exported)
		{
			ft_putstr_fd(env->name, STDOUT_FILENO);
			ft_putchar_fd('=', STDOUT_FILENO);
			ft_putstr_fd(env->value, STDOUT_FILENO);
			ft_putchar_fd('\n', STDOUT_FILENO);
		}
		env = env->next;
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhasmi <lhasmi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 17:48:58 by lhasmi            #+#    #+#             */
/*   Updated: 2023/08/06 18:33:26 by lhasmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	print_export(t_piper *node)
{
	// For each entry in the environment linked list
	while (node->envp)
	{
		// Print out each entry in a format similar to bash's "declare
		// -x" command
		ft_printf_fd(STDERR_FILENO, "declare -x %s=%s\n", node->envp->name,
			node->envp->value);
		// Proceed to next entry
		node->envp = node->envp->next;
	}
	return (0);
}

// appends a new value to an existing environment variable 's value if the variable name exists,
// and if it doesn' t, it will attempt to create a new variable with the given name and value.
// The function also validates the variable name and prints an error message if it's not valid.
int process_plus_equal(t_piper *pip, t_node *node, char *name)
{
	char			*value;
	char			*old_value;
	t_env			*entry;
	char			*new_value;

	old_value = "";
	// Here we assume you have a function called is_valid_variable_name that checks if the variable name is valid
	// If the name is not valid, we print an error and return 1
	if (!name || /*!is_valid_variable_name(name)*/)
	{
		ft_printf_fd(STDERR_FILENO, "minishell: export: `%s': not a valid identifier\n", name);
		return (1);
	}
	// Assuming that your node->commands->content points to a command with a format like "VAR+=VALUE", we use ft_strtok to split the command into VAR and VALUE
	value = ft_strtok((node->commands->content)->start, "+=");
	// Using env_lookup function to get the existing environment variable entry
	entry = env_lookup(name, pip->envp);
	if (entry)
		old_value = entry->value;
	// Create a new value by concatenating the old and new values
	new_value = malloc(strlen(old_value) + strlen(value) + 1);
	ft_strcpy(new_value, old_value);
	ft_strcat(new_value, value);
	// Update the existing environment variable with the new value
	env_update(entry, new_value, name);
	free(new_value);
	return (0);
}


int	process_equal(char *name, char **argv)
{
	// Checks if the variable name is valid
	if (is_valid_variable_name(name))
	{
		// If valid, add the variable to the symbol table
		string_to_symtab(argv[1]);
		return (0);
	}
	else
	{
		// If invalid, print error message
		ft_printf_fd(STDERR_FILENO,
			"minishell: export: `%s': not a valid identifier\n", name);
		return (1);
	}
}

int	check_input_arguments(char **argv, struct s_symtab *symtab, char *name)
{
	struct s_symtab_entry	*entry;

	// Check if the first argument is a flag (-)
	if (argv[1][0] == '-')
		return (ft_printf_fd(STDERR_FILENO, EXPORT), 2);
	// Get the variable name from the argument
	name = get_varname(argv[1]);
	if (!name)
		name = argv[1];
	// If the argument contains "+=", process it accordingly
	if (strstr(argv[1], "+=") != NULL)
	{
		name = ft_strtok(argv[1], "+=");
		return (process_plus_equal(name, symtab, argv));
	}
	// If the argument contains "=", process it accordingly
	else if (strchr(argv[1], '=') != NULL)
		return (process_equal(name, argv));
	else
	{
		// Lookup the variable in the symbol table
		entry = do_lookup(argv[1], symtab);
		if (entry)
			return (ft_printf_fd(STDERR_FILENO, "declare -x %s=%s\n",
					entry->name, entry->val), 0);
		else if (!is_valid_variable_name(name))
			return (ft_printf_fd(STDERR_FILENO,
					"minishell: export: `%s': not a valid identifier\n",
					argv[1]), 1);
		return (0);
	}
}

int	ft_export(int argc, ...)
{
	struct s_symtab_entry	*entry;
	struct s_symtab			*symtab;
	char					**argv;
	char					*name;
	va_list					args;

	entry = NULL;
	name = NULL;
	symtab = shell.s_symtab_stack.local_symtab;
	va_start(args, argc);
	argv = va_arg(args, char **);
	entry = symtab->first;
	va_end(args);
	// If no arguments are given, print out the export variables
	if (argc == 1)
	{
		return (print_export(entry));
	}
	else
	{
		va_start(args, argc);
		argv = va_arg(args, char **);
		va_end(args);
		// Check the input arguments and process them accordingly
		return (check_input_arguments(argv, symtab, name));
	}
	return (0);
}

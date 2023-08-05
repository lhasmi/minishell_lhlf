/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution_helpers.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhasmi <lhasmi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 12:18:38 by lhasmi            #+#    #+#             */
/*   Updated: 2023/08/05 23:13:04 by lhasmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] == s2[i] && s1[i] != '\0' && s2[i] != '\0')
		i++;
	return (s1[i] - s2[i]);
}

char	*my_getenv(char *name, t_env *envp)
{
	while (envp != NULL)
	{
		if (ft_strcmp(envp->name, name) == 0)
			return (envp->value);
		envp = envp->next;
	}
	return (NULL);
}

char	*build_path(char *dir_start, char *cmd, int dir_len)
{
	char	*full_path;

	full_path = malloc(dir_len + ft_strlen(cmd) + 2);
	if (full_path == NULL)
	{
		perror("minishell: malloc failed");
		exit(EXIT_FAILURE);
	}
	ft_strncpy(full_path, dir_start, dir_len);
	full_path[dir_len] = '/';
	full_path[dir_len + 1] = '\0';
	ft_strcat(full_path, cmd);
	return (full_path);
}

char	*check_dirs(char *cmd, t_env *envp, char *dir_start)
{
	char	*dir_end;
	size_t	dir_len;
	char	*full_path;

	if (my_getenv("PATH", envp) == NULL)
		perror("command not found");
	while ((dir_end = ft_strchr(dir_start, ':')))
	{
		dir_len = dir_end - dir_start;
		full_path = build_path(dir_start, cmd, dir_len);
		if (access(full_path, X_OK) == 0)
			return (full_path);
		free(full_path);
		dir_start = dir_end + 1;
	}
	return (NULL);
}

char	*get_cmdpath_full(char *cmd, t_env *envp)
{
	char	*path;
	char	*dir_start;

	dir_start = NULL;
	path = NULL;
	if (cmd[0] == '/')
		path = cmd;
	else
		dir_start = my_getenv("PATH", envp);
	path = check_dirs(cmd, envp, dir_start);
	return (path);
}

// int	is_builtin(char *cmd)
int	is_builtin(t_list *node)
{
	char			**builtins;
	struct s_slice	*slice;
	int i;

	builtins = get_builtins();
	i = 0;
	while (builtins[i])
	{
		slice = node->content;
		if (ft_strcmp(slice->start, builtins[i]) == 0)
			return (1);
		i++;
	}
	return (0);
}

// int	execute_builtin(char **command, t_env *env, int argc, char **argv, int *exit_status)
int	execute_builtin(t_node *node, t_piper *pip)
{
	int				i;
	char		**command;

	command = linked_list_to_array(node);
	if (ft_strcmp(command[0], "exit") == 0)
	{
		ft_exit(command, pip->exit_status);
		return 0; // Indicates that we should exit the shell
	}
	// Based on the first command, execute the correct function
	if (ft_strcmp(command[0], "env") == 0)
    {
        print_env_table(pip->envp);
        return 1;
    }
	i = 0;
	if (ft_strcmp(command[0], "echo") == 0)
	{
		i = 1;
		while (command[i] != NULL)
		{
			printf("%s ", command[i]);
			i++;
		}
		return (1); // success and continue the shell
	}
	if (ft_strcmp(command[0], "cd") == 0)
	{
		*exit_status = ft_cd(argc, env, argv);
		return 1; // Continue running the shell
	}
	// handling of the others is int he builtins.c: "cd", "pwd", "exit", "env",
	// "unset", "export"
	*exit_status = 0;
	fprintf(stderr, "minishell: command not found: %s\n", command[0]);
	return (1);
}

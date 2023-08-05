/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhasmi <lhasmi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 17:48:46 by lhasmi            #+#    #+#             */
/*   Updated: 2023/08/05 23:19:37 by lhasmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"
void	update_pwd(char *newpwd, t_env *env)
{
	t_env	*oldpwd;
	t_env	*pwd;

	oldpwd = env_lookup("OLDPWD", env);
	pwd = env_lookup("PWD", env);
	env_update(oldpwd, oldpwd->value, "OLDPWD");
	env_update(pwd, newpwd, "PWD");
}

int	change_to_home(t_piper *pip)
{
	t_env	*entry;
	char	*newpwd;
	int		result;

	entry = env_lookup("HOME", pip->envp);
	if (entry == NULL)
	{
		ft_printf_fd(STDERR_FILENO, "minishell: cd: HOME not set\n");
		return (1);
	}
	result = chdir(entry->value);
	if (result != 0)
	{
		ft_printf_fd(STDERR_FILENO, "minishell: cd: %s: %s\n", entry->name,
			strerror(errno));
		return (1);
	}
	newpwd = getcwd(NULL, 0);
	update_pwd(newpwd, pip->envp);
	return (0);
}

int	change_to_oldpwd(t_piper *pip)
{
	t_env	*oldpwd_entry;
	char	*newpwd;
	int		result;

	oldpwd_entry = env_lookup("OLDPWD", pip->envp);
	if (oldpwd_entry == NULL)
	{
		ft_printf_fd(STDERR_FILENO, "minishell: cd: OLDPWD not set\n");
		return (1);
	}
	result = chdir(oldpwd_entry->value);
	if (result != 0)
	{
		ft_printf_fd(STDERR_FILENO, "minishell: cd: %s: %s\n",
			oldpwd_entry->value, strerror(errno));
		return (1);
	}
	newpwd = getcwd(NULL, 0);
	update_pwd(newpwd, pip->envp);
	ft_printf_fd(STDOUT_FILENO, "%s\n", newpwd);
	return (0);
}

int	change_to_new_dir(char *new_dir_path, t_piper *pip)
{
	char	*newpwd;
	int		result;

	result = chdir(new_dir_path);
	if (result != 0)
	{
		ft_printf_fd(STDERR_FILENO, "minishell: cd: %s: %s\n", new_dir_path,
			strerror(errno));
		return (1);
	}
	newpwd = getcwd(NULL, 0);
	update_pwd(newpwd, pip->envp);
	return (0);
}

int	ft_cd(t_piper *pip, t_node *node)
{
    char	*path;
	int		result;

    if (node->commands->len == 1)
        result = change_to_home(pip);
    else
    {
        path = linked_list_to_array(node->commands)[1]; // assuming this is your second argument
        if (ft_strcmp(path, "-") == 0)
            result = change_to_oldpwd(pip);
        else
            result = change_to_new_dir(path, pip);
    }
    return (result);
}

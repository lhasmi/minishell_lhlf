/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhasmi <lhasmi@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 17:48:46 by lhasmi            #+#    #+#             */
/*   Updated: 2023/08/04 20:24:13 by lhasmi           ###   ########.fr       */
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

int	change_to_home(t_env *env)
{
	t_env	*entry;
	char	*newpwd;
	int		result;

	entry = env_lookup("HOME", env);
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
	update_pwd(newpwd, env);
	return (0);
}

int	change_to_oldpwd(t_env *env)
{
	t_env	*oldpwd_entry;
	char	*newpwd;
	int		result;

	oldpwd_entry = env_lookup("OLDPWD", env);
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
	update_pwd(newpwd, env);
	ft_printf_fd(STDOUT_FILENO, "%s\n", newpwd);
	return (0);
}

int	change_to_new_dir(char *new_dir_path, t_env *env)
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
	update_pwd(newpwd, env);
	return (0);
}

int	ft_cd(int argc, t_env *env, ...)
{
    va_list	args;
    char	**path;
    int		result;

    result = 0;
    va_start(args, env);
    path = va_arg(args, char **);
    va_end(args);
    if (argc == 1)
        result = change_to_home(env);
    else
    {
        if (ft_strcmp(*(path + 1), "-") == 0)
            result = change_to_oldpwd(env);
        else
            result = change_to_new_dir(*(path + 1), env);
    }
    return (result);
}

// int	ft_cd(int argc, ...)
// {
// 	va_list	args;
// 	char	**path;
// 	int		result;
// 	t_env	*env;

// 	result = 0;
// 	env = /*complete the code here*/
// 	va_start(args, argc);
// 	path = va_arg(args, char **);
// 	va_end(args);
// 	if (argc == 1)
// 		result = change_to_home(env);
// 	else
// 	{
// 		if (ft_strcmp(*(path + 1), "-") == 0)
// 			result = change_to_oldpwd(env);
// 		else
// 			result = change_to_new_dir(*(path + 1), env);
// 	}
// 	return (result);
// }

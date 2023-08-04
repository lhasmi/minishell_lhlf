/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution_helpers2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhasmi <lhasmi@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 22:48:41 by lhasmi            #+#    #+#             */
/*   Updated: 2023/08/03 22:05:58 by lhasmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"


int	ft_env_size(t_env *begin_list)
{
	if (begin_list == 0)
		return (0);
	else
		return (1 + ft_env_size(begin_list->next));
}

char	**env_to_charpp(t_env *env)
{
	int		size;
	char	**envp;
	int		i;
	char	*temp;

	size = ft_env_size(env);
	envp = (char **)malloc(sizeof(char *) * (size + 1));
	if (envp == NULL)
	{
		perror("malloc failed");
		exit(EXIT_FAILURE);
	}
	i = 0;
	while (env != NULL)
	{
		if(env->is_exported == 1 && env->value != NULL)
		{
			temp = ft_strjoin(env->name, "=");
			envp[i] = ft_strjoin(temp, env->value);
			free(temp);
		}
		else
			envp[i] = NULL; 
		env = env->next;
		i++;
	}
	envp[i] = NULL;
	return envp;
}

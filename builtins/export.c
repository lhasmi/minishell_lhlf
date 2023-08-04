/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhasmi <lhasmi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 17:48:58 by lhasmi            #+#    #+#             */
/*   Updated: 2023/07/31 20:55:08 by lhasmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"


int				ft_export(char **args)
{
	int		i;
	t_env	*env;

	i = 1;
	env = get_env(NULL, NULL);
	if (!args[1])
		print_export(env);
	else
	{
		while (args[i])
		{
			export_env(env, args[i]);
			i++;
		}
	}
	return (0);
}

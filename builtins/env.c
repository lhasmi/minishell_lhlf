/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhasmi <lhasmi@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 17:48:50 by lhasmi            #+#    #+#             */
/*   Updated: 2023/08/04 19:44:31 by lhasmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


// Environment variables, which might be stored in a global state variable or something similar.
#include "../include/minishell.h"

void ft_putchar(char c)
{
	write(1, &c, 1);
}

void ft_putstr(char *str)
{
	int i;

	i = 0;
	while (str[i])
		ft_putchar(str[i++]);
}

void	ft_env(char **env)
{
	int i;

	i = 0;
	while (env[i])
	{
		ft_putstr(env[i]);
		ft_putchar('\n');
		i++;
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhasmi <lhasmi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 17:48:50 by lhasmi            #+#    #+#             */
/*   Updated: 2023/08/06 14:00:34 by lhasmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	ft_env(t_piper *pip)
{
	t_env	*current;

	current = pip->envp;
	while (current)
	{
		ft_printf_fd(STDOUT_FILENO, "%s=%s\n", current->name, current->value);
		current = current->next;
	}
}

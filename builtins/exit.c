/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhasmi <lhasmi@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 17:48:54 by lhasmi            #+#    #+#             */
/*   Updated: 2023/08/04 23:28:12 by lhasmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	ft_exit(char **args, int *exit_status)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	j = 0;
	if (args[1] == NULL)
	{
		*exit_status = 0;
		return;
	}
	while (args[1][i])
	{
		if (ft_isdigit(args[1][i]))
			j++;
		i++;
	}
	if (j == i)
	{
		*exit_status = ft_atoi(args[1]);
		return;
	}
	else
	{
		str = ft_strjoin("exit: ", args[1]);
		ft_putendl_fd(str, 2);
		free(str);
		*exit_status = 255;
		return;
	}
}

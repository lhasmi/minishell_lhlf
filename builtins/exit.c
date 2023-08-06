/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhasmi <lhasmi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 17:48:54 by lhasmi            #+#    #+#             */
/*   Updated: 2023/08/06 21:39:35 by lhasmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	update_and_print_status(t_piper *pip, char **args, int i, int j)
{
	char	*str;

	if (j == i)
		pip->exit_status = ft_atoi(args[1]);
	else
	{
		str = ft_strjoin("exit: ", args[1]);
		ft_putendl_fd(str, 2);
		free(str);
		pip->exit_status = 255;
	}
}
//use exit function and associateit with fork
int	ft_exit(t_piper *pip, t_node *node)
{
	int		i;
	int		j;
	char	**args;

	args = linked_list_to_array(node);
	if (!args)
		return (1);
	i = 0;
	j = 0;
	if (args[1] == NULL)
	{
		pip->exit_status = 0;
		return (pip->exit_status);
	}
	while (args[1][i])
	{
		if (ft_isdigit(args[1][i]))
			j++;
		i++;
	}
	update_and_print_status(pip, args, i, j);
	return (pip->exit_status);
}

// void	ft_exit(char **args, int *exit_status)
// {
// 	int		i;
// 	int		j;
// 	char	*str;

// 	i = 0;
// 	j = 0;
// 	if (args[1] == NULL)
// 	{
// 		*exit_status = 0;
// 		return ;
// 	}
// 	while (args[1][i])
// 	{
// 		if (ft_isdigit(args[1][i]))
// 			j++;
// 		i++;
// 	}
// 	if (j == i)
// 	{
// 		*exit_status = ft_atoi(args[1]);
// 		return ;
// 	}
// 	else
// 	{
// 		str = ft_strjoin("exit: ", args[1]);
// 		ft_putendl_fd(str, 2);
// 		free(str);
// 		*exit_status = 255;
// 		return ;
// 	}
// }

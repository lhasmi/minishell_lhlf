/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhasmi <lhasmi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 17:48:42 by lhasmi            #+#    #+#             */
/*   Updated: 2023/07/31 21:44:15 by lhasmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

char	**get_builtins(void)
{
	static char	*builtins[8];

	builtins[0] = "cd";
	builtins[1] = "pwd";
	builtins[2] = "echo";
	builtins[3] = "exit";
	builtins[4] = "env";
	builtins[5] = "unset";
	builtins[6] = "export";
	builtins[7] = NULL;
	return (builtins);
}

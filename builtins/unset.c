/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhasmi <lhasmi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 17:49:04 by lhasmi            #+#    #+#             */
/*   Updated: 2023/07/31 21:36:21 by lhasmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int		ft_unset(char **args)
{
// I need to create a var table first to store the env variables,
// I need to create a function to print the table
// I need to create a linked list to store the env variables, each node having the name of the variable (name) and the value of the variable (value) and
// a flag to know if the variable is owned by me (is_owned) meaning allocated by me
// also a flag to know if the variable is exported or not (is_exported) because I need to know if I can printit in the table or not
//then I can remove them from the table
// I need to create a function to remove the env variables from the table
// I need to create a function to free the env variables, only the ones owned by me(is_owned) meaning allocated by me.
// not the ones that are already in the env (global env variables) for that i will put a flag in the env variables nodes
	return (0);
}

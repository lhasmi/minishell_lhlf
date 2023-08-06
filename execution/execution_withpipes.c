/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution_withpipes.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhasmi <lhasmi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 16:30:15 by lhasmi            #+#    #+#             */
/*   Updated: 2023/08/06 13:48:43 by lhasmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

// a function execute_node that takes a node and executes it
void	execute_node(t_piper *pip, t_node *node)
{
		int fd[2];
	pid_t	pid;

	if (node->is_pipe)
	{
		pipe(fd);
		pid = fork();
		if (pid == 0)
		{
			close(fd[0]);
			dup2(fd[1], STDOUT_FILENO);
			close(fd[1]);
			execute_node(pip, node->left);
			exit(EXIT_SUCCESS);
		}
		else
		{
			wait(NULL);
			close(fd[1]);
			dup2(fd[0], STDIN_FILENO);
			close(fd[0]);
			execute_node(pip, node->right);
		}
	}
	else
		execute_command(pip, node);
}

char	**linked_list_to_array(t_node *node)
{
	int				length;
	char			**array;
	struct s_slice	*slice;
	t_list          *current;
	int				i;

	length = ft_lstsize(node->commands);
	array = malloc((length + 1) * sizeof(char *));
	if (!array)
	{
		perror("malloc");
		return (NULL);
	}
	i = 0;
	current = node->commands;
	while (i < length)
	{
		slice = current->content;
		array[i] = ft_strndup(slice->start, slice->len);
		if (!array[i])
		{
			perror("strndup");
			return (NULL);
		}
		current = current->next;
		i++;
	}
	array[length] = NULL; // NULL-terminate the array
	return (array);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   piping_helpers.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhasmi <lhasmi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 13:47:21 by lhasmi            #+#    #+#             */
/*   Updated: 2023/08/05 15:11:14 by lhasmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	create_pipe(int pipefd[2])
{
	if (pipe(pipefd) == -1)
	{
		perror("pipe");
		return (1);
	}
	return (0);
}

int	fork_process(void)
{
	int	pid;

	pid = fork();
	if (pid < 0)
		perror("fork");
	return (pid);
}

void	close_fd(int fd)
{
	if (close(fd) == -1)
		perror("close");
}

void	dup2_fd(int oldfd, int newfd)
{
	if (dup2(oldfd, newfd) == -1)
		perror("dup2");
}

void	init_piper(t_piper *pip, int num_commands, char ***commands)
{
	pip->num_commands = num_commands;
	pip->commands = commands;
	pip->exit_status = 0;
	pip->in_fd = 0;
	pip->out_fd = 1;
}

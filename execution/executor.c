/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhasmi <lhasmi@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 17:50:40 by lhasmi            #+#    #+#             */
/*   Updated: 2023/08/04 23:44:03 by lhasmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	execute_command(char **command, t_env *envp, int argc, char **argv, int *exit_status)
{
	pid_t	pid;
	char	*cmd_path;
	int		status;
	char	**envpp;
	int		builtin_status;

	builtin_status = 1;
	if (is_builtin(*command))
	{
		builtin_status = execute_builtin(command, envp, argc, argv, exit_status);
		if (builtin_status == 0)
			return 0; // exit the shell
		else
			return 1; // continue running the shell
	}
	pid = fork();
	if (pid == 0)
	{
		cmd_path = get_cmdpath_full(command[0], envp);
		if (!cmd_path)
		{
			write(2, "minishell: command not found\n", 29);
			exit(EXIT_FAILURE);
		}
		envpp = env_to_charpp(envp);
		if (execve(cmd_path, command, envpp) == -1)
		{
			perror("minishell");
			exit(EXIT_FAILURE);
		}
	}
	else if (pid < 0)
		perror("minishell");
	else
	{
		waitpid(pid, &status, 0);
		*exit_status = WEXITSTATUS(status); // Save the exit status of the process
	}
	return 1; // Indicates that we should continue running the shell
}

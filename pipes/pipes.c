/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipes.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhasmi <lhasmi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 17:50:34 by lhasmi            #+#    #+#             */
/*   Updated: 2023/08/05 18:14:08 by lhasmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

// Redirection and pipes,
// which require manipulating file descriptors before exec-ing the process.
//has to be removed from here and put in execution/executor.c
void	execute_pipeline_command(t_piper *pip, int i, t_env *envp, int argc,
		char **argv)
{
	int	pid;
	int pipefd[2]; // fd [0] is the read end and fd [1] is the write end

	if (create_pipe(pipefd) != 0)
		return ;
	pid = fork_process();//main process forks a child process
	if (pid == 0) // child process
	{
		close_fd(pipefd[0]);                   // Close unused read end
		dup2_fd(pip->in_fd, STDIN_FILENO);     // Redirect input
		if (i != pip->num_commands - 1)
			// Don't redirect output for the last command
			dup2_fd(pipefd[1], STDOUT_FILENO); // Redirect output
		execute_command(pip->commands[i], envp, argc, argv, &pip->exit_status);
		pip->exit_status = WEXITSTATUS(pip->exit_status);
		// Execute the command
		exit(EXIT_FAILURE); // since this is called right after execute_command,
		// the closing of fd[1] is implicit
		// If we reach this point, there was an error
	}
	else if (pid > 0)
	{
		waitpid(pid, &pip->exit_status, 0);
		// Wait for the child process
		pip->exit_status = WEXITSTATUS(pip->exit_status);
		// Save the exit status of the process
		close_fd(pip->in_fd);
		close_fd(pipefd[1]);    // Close unused write end
		pip->in_fd = pipefd[0]; // Next child reads from here
	}
}

//execute node does what this does , so remove this function
void	execute_pipeline(t_piper *pip, t_env *envp, int argc, char **argv)
{
	int	i;

	i = 0;
	while (i < pip->num_commands)
	{
		execute_pipeline_command(pip, i, envp, argc, argv);
		++i;
	}
}

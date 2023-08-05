/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhasmi <lhasmi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 23:36:13 by lfiorini          #+#    #+#             */
/*   Updated: 2023/08/05 14:44:01 by lhasmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	minishell(t_env *envp, int argc, char **argv)
{
	char	*input;
	char	**command;
	int		exit_status;
	int		status;

	// char	**commands[2];
	// t_piper	pip;
	status = 1;
	while (1)
	{
		input = readline("minishell> ");
		command = parse_input(input);
		// commands[2] = {(char *[]){"ls", NULL}, (char *[]){"wc", "-l", NULL}};
		// init_piper(&pip, 2, commands);
		// execute_pipeline(&pip, envp, argc, argv);
		// printf("exit status: %d\n", pip.exit_status);
		status = execute_command(command, envp, argc, argv, &exit_status);
		if (status == 0)
			break ;
		free(input);
		free(command);
	}
}

int	main(int argc, char **argv, char **envp)
{
	t_env	*env;

	// Signal handling should be set up here, before entering the main loop.
	// Also set up any necessary initializations for the shell environment.
	(void)argc;
	(void)argv;
	env = init_env_table(envp);
	minishell(env, argc, argv);
	return (0);
}

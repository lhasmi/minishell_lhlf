/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhasmi <lhasmi@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 23:36:13 by lfiorini          #+#    #+#             */
/*   Updated: 2023/08/04 23:52:11 by lhasmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void minishell(t_env *envp, int argc, char **argv)
{
    char* input;
    char** command;
    int exit_status;
    int status;

    status = 1;
    while (1)
    {
        input = readline("minishell> ");
        command = parse_input(input);
        status = execute_command(command, envp, argc, argv, &exit_status);
        if (status == 0)
            break;
        free(input);
        free(command);
    }
}

int main(int argc, char **argv, char **envp)
{
    // Signal handling should be set up here, before entering the main loop.
    // Also set up any necessary initializations for the shell environment.
    (void)argc;
    (void)argv;
	t_env *env = init_env_table(envp);
    minishell(env, argc, argv);
    return (0);
}

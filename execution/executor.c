/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhasmi <lhasmi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 17:50:40 by lhasmi            #+#    #+#             */
/*   Updated: 2023/08/05 23:04:07 by lhasmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

// int	execute_command(char **command, t_env *envp, int argc, char **argv, int *exit_status)
//call diff modular functions and execute node will execute the whole tree for me
//if I call the root in itthe argc and argv are not available in the provided
//structure and are required for execute_builtin function.
void	execute_command(t_piper *piper, t_node *node)
{
    char	*cmd_path;
    int		status;
    char	**envpp;
    int		builtin_status;

    char **command = linked_list_to_array(node);
    builtin_status = 1;
    status = 0;
    if (is_builtin(*command))
    {
        builtin_status = execute_builtin(command, piper->envp, argc, argv, &piper->exit_status);
        if (builtin_status == 0)
            return;
    }
    piper->pid = fork();
    if (piper->pid == 0)
    {
        cmd_path = get_cmdpath_full(command[0], piper->envp);
        if (!cmd_path)
        {
            write(2, "minishell: command not found\n", 29);
            exit(EXIT_FAILURE);
        }
        envpp = env_to_charpp(piper->envp);
        if (execve(cmd_path, command, envpp) == -1)
        {
            perror("minishell");
            exit(EXIT_FAILURE);
        }
    }
    else if (piper->pid < 0)
        perror("minishell");
    else
    {
        waitpid(piper->pid, &status, 0);
        piper->exit_status = WEXITSTATUS(status);
    }
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhasmi <lhasmi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 22:49:27 by lhasmi            #+#    #+#             */
/*   Updated: 2023/08/05 23:12:43 by lhasmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTION_H
# define EXECUTION_H

# include "../include/minishell.h"

////////// executor.c /////////
int execute_command(char** command, t_env *env, int argc, char **argv, int *exit_status);

////////// execution_helpers.c /////
int	ft_strcmp(char *s1, char *s2);

/* my_getenv gets the value of env var from envp array.
'name' is the environment variable name.'envp' is the env array of strings*/
char* my_getenv(char* name, t_env *envp);
/* build_path constructs the full path to the executable command.
'dir_start' = directory path.'cmd' is the command to be executed.
'dir_len' is the length of the directory path.*/
char* build_path(char* dir_start, char* cmd, int dir_len);
/* check_dirs iterates through directories in PATH environment variable,
and checks if the command can be executed from the current directory.
'dir_start' is the starting directory in the PATH environment variable.*/
char* check_dirs(char* cmd, t_env *envp, char* dir_start);
/* get_cmdpath_full determines the full path of the command to be executed.
If command starts with '/', it is treated as full path.Otherwise, it searches through
the directories specified in PATH environment variable.*/
char	*get_cmdpath_full(char *cmd, t_env *envp);
int		is_builtin(t_list *node);
// int		execute_builtin(char** command, t_env *env, int argc, char **argv, int *exit_status);
int	execute_builtin(t_node *node, t_piper *pip);

////////// execution_helpers2.c /////
/* ft_env_size returns the number of elements in the env list.*/
int		ft_env_size(t_env *begin_list);
/* env_to_charpp converts the env list to an array of strings.*/
char	**env_to_charpp(t_env *env);

////////// execution_withpipes.c /////
char **linked_list_to_array(t_node *list);
void execute_node(t_piper *pip, t_node *current);

#endif

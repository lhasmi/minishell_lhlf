/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipes.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhasmi <lhasmi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 13:47:48 by lhasmi            #+#    #+#             */
/*   Updated: 2023/08/06 21:49:22 by lhasmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPES_H
# define PIPES_H

# include "../include/minishell.h"


typedef struct s_piper//struct for execution of pipes
{
	t_node	*root;
	int		exit_status;
	int		in_fd;
	int		out_fd;
	t_env	*envp;
	pid_t	pid;
}			t_piper;

int			create_pipe(int pipefd[2]);
int			fork_process(void);
void		close_fd(int fd);
void		dup2_fd(int oldfd, int newfd);
void	init_piper(t_piper *pip, t_node *root, t_env *envp);
void		execute_pipeline_command(t_piper *pip, int i, t_env *envp, int argc,
				char **argv);
void		execute_pipeline(t_piper *pip, t_env *envp, int argc, char **argv);

#endif

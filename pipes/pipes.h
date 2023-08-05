/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipes.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhasmi <lhasmi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 13:47:48 by lhasmi            #+#    #+#             */
/*   Updated: 2023/08/05 14:40:40 by lhasmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPES_H
# define PIPES_H

# include "../include/minishell.h"

typedef struct s_piper
{
	int		num_commands;
	char	***commands;
	int		exit_status;
	int		in_fd;
	int		out_fd;
}			t_piper;

int			create_pipe(int pipefd[2]);

int			fork_process(void);

void		close_fd(int fd);

void		dup2_fd(int oldfd, int newfd);

void		init_piper(t_piper *pp, int num_commands, char ***commands);

void		execute_pipeline_command(t_piper *pp, int i, t_env *envp, int argc,
				char **argv);

void		execute_pipeline(t_piper *pp, t_env *envp, int argc, char **argv);

#endif

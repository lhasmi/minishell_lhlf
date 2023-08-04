/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipes.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhasmi <lhasmi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 17:50:34 by lhasmi            #+#    #+#             */
/*   Updated: 2023/07/31 20:41:59 by lhasmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../include/minishell.h"
// Redirection and pipes, which require manipulating file descriptors before exec-ing the process.

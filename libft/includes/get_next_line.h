/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfiorini <lfiorini@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 03:26:39 by lfiorini          #+#    #+#             */
/*   Updated: 2023/04/23 02:58:58 by lfiorini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

typedef struct s_buffer
{
	char	buf[BUFFER_SIZE];
	int		idx;
	int		len;
}	t_buffer;

typedef struct s_string
{
	char	*str;
	int		len;
	int		size;
}	t_string;

t_string	gnl_init_string(void);
int			gnl_get_index(char *s, char c, int begin, int end);
int			gnl_update_line(t_string *l, t_buffer b);
t_string	gnl_optimize_string(t_string s);
void		*gnl_memcpy(void *dst, const void *src, size_t n);

char		*get_next_line(int fd);

#endif

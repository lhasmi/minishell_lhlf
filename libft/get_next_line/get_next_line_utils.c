/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfiorini <lfiorini@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 03:26:29 by lfiorini          #+#    #+#             */
/*   Updated: 2023/04/24 04:03:33 by lfiorini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/get_next_line.h"

t_string	gnl_init_string(void)
{
	t_string	s;

	s.str = 0;
	s.len = 0;
	s.size = 0;
	return (s);
}

int	gnl_get_index(char *s, char c, int begin, int end)
{
	int	i;

	i = begin;
	while (i < end)
	{
		if (s[i] == c)
			return (i);
		i++;
	}
	return (end - 1);
}

void	*gnl_memcpy(void *dst, const void *src, size_t n)
{
	size_t	i;

	if (!dst && !src)
		return (0);
	i = 0;
	while (i < n)
	{
		((char *) dst)[i] = ((const char *) src)[i];
		i++;
	}
	return (dst);
}

int	gnl_update_line(t_string *l, t_buffer b)
{
	t_string	tmp;

	tmp.len = gnl_get_index(b.buf, '\n', b.idx, b.len) - b.idx + 1 + l->len;
	if (l->len && tmp.len < l->size)
		gnl_memcpy(l->str + l->len, b.buf + b.idx, tmp.len - l->len);
	else
	{
		l->size = tmp.len * 10 + 1;
		tmp.str = (char *) malloc(sizeof(char) * (l->size));
		if (!tmp.str)
		{
			if (l->str)
				free(l->str);
			l->str = 0;
			return (0);
		}
		gnl_memcpy(tmp.str, l->str, l->len);
		gnl_memcpy(tmp.str + l->len, b.buf + b.idx, tmp.len - l->len);
		if (l->str)
			free(l->str);
		l->str = tmp.str;
	}
	l->len = tmp.len;
	l->str[l->len] = 0;
	return (1);
}

t_string	gnl_optimize_string(t_string s)
{
	t_string	opt;

	opt.str = 0;
	opt.len = s.len;
	opt.size = s.len + 1;
	if (!s.str || s.len + 1 == s.size)
		return (s);
	else
	{
		opt.str = (char *) malloc(sizeof(char) * opt.size);
		if (!opt.str)
		{
			free(s.str);
			return (opt);
		}
		gnl_memcpy(opt.str, s.str, opt.len);
		opt.str[opt.len] = 0;
		free(s.str);
		return (opt);
	}
}

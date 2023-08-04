/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+
	+:+     */
/*   By: lfiorini <lfiorini@student.42heilbronn.    +#+  +:+
	+#+        */
/*                                                +#+#+#+#+#+
	+#+           */
/*   Created: 2022/10/11 22:58:49 by lfiorini          #+#    #+#             */
/*   Updated: 2023/04/23 03:31:05 by lfiorini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"


size_t	ft_strlen(const char *s)
{
	size_t i;

	i = 0;
	if (s != NULL)
	{
		while (s[i] != '\0')
			i++;
	}
	return (i);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhasmi <lhasmi@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 14:03:55 by lailah            #+#    #+#             */
/*   Updated: 2023/08/04 20:33:59 by lhasmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

// #include "libft.h"

char	*ft_strcat(char *dest, const char *src)
{
	size_t	dest_len;

	dest_len = ft_strlen(dest);
	dest = ft_strcpy(dest + dest_len, src);
	return (dest);
}

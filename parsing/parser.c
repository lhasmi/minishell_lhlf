/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhasmi <lhasmi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 17:50:37 by lhasmi            #+#    #+#             */
/*   Updated: 2023/08/01 21:59:08 by lhasmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

// this implementation and does not yet handle quoting,
	// escaping & other shell-like features.

char	*ft_strtok(char *str, const char *delim)
{
	static char	*buffer;
	char		*token_start;
	char		*testChar;

	if (str != NULL)
		buffer = str;
	if (buffer == NULL)
		return (NULL);
	token_start = buffer;
	testChar = buffer;
	while (*testChar != '\0')
	{
		if (ft_strchr(delim, *testChar))
		{
			*testChar = '\0';
			buffer = testChar + 1;
			return (token_start);
		}
		testChar++;
	}
	buffer = NULL;
	return(token_start);
}

char	**parse_input(char *input)
{
	int		num_tokens;
	char	*token;
	int		max_tokens;
	char	**tokens;

	// Calculate the maximum possible number of tokens
	max_tokens = ft_strlen(input) / 2 + 1;
	// The worst case is when every character is a token
	tokens = malloc(sizeof(char *) * (max_tokens + 1));
	if (tokens == NULL)
		return (NULL);
	// Split the input into tokens
	num_tokens = 0;
	token = ft_strtok(input, " ");
	while (token != NULL)
	{
		tokens[num_tokens++] = token;
		token = ft_strtok(NULL, " ");
	}
	tokens[num_tokens] = NULL;
	return (tokens);
}

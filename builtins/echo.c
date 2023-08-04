/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhasmi <lhasmi@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 17:47:50 by lhasmi            #+#    #+#             */
/*   Updated: 2023/08/03 22:09:39 by lhasmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../include/minishell.h"

int	parse_echo_options(char **argv, int *i)
{
    // Declare a pointer to iterate over the argument characters
	char	*arg;
	int		n_option;
	n_option = 0;
    // Iterate over the arguments. If the argument begins with a '-',
    // it could be an option
	while (argv[*i] && argv[*i][0] == '-')
	{
        // Skip the initial '-' in the argument
		arg = argv[*i] + 1;
        // Check for 'n' characters in the argument (for -n option)
		while (*arg == 'n')
			arg++;
        // If we've gone through the entire argument and it only consisted
        // of 'n' characters, then the -n option is present
		if (*arg == '\0')
		{
			n_option = 1;
			(*i)++;
		}
        // If the argument contained characters other than 'n', it's not the -n option.
        // In this case, break out of the loop
		else
			break ;
	}
    // Return the -n option flag. If n_option == 1, the -n option was present
	return (n_option);
}


void	echo_argv(char **argv, int i)
{
	while (argv[i])
	{
		ft_putstr_fd(argv[i], STDOUT_FILENO);
		if (argv[i + 1] && argv[i][0] != '\0')
			ft_putchar_fd(' ', STDOUT_FILENO);
		i++;
	}
}

void	check_newline(int n_option)
{
	if (n_option == 0)
		ft_putchar_fd('\n', STDOUT_FILENO);
}

int	ft_echo(int argc, ...)
{
	int		i;
	int		n_option;
	char	**argv;
	va_list	args;

	va_start(args, argc);
	argv = va_arg(args, char **);
	if (argc <= 0)
		return (-1);
	i = 1;
	n_option = 0;
	if (argc > 1)
	{
		n_option = parse_echo_options(argv, &i);
		echo_argv(argv, i);
	}
	check_newline(n_option);
	va_end(args);
	return (0);
}

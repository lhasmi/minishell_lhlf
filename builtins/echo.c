/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhasmi <lhasmi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 17:47:50 by lhasmi            #+#    #+#             */
/*   Updated: 2023/08/06 13:20:40 by lhasmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../include/minishell.h"

int	parse_echo_options(char **argv, int *i)
{
	char	*arg;
	int		n_option;
	n_option = 0;
	while (argv[*i] && argv[*i][0] == '-')
	{
		arg = argv[*i] + 1;
		while (*arg == 'n')
			arg++;
		if (*arg == '\0')
		{
			n_option = 1;
			(*i)++;
		}
		else
			break ;
	}
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

int	ft_echo(t_piper *pip, t_node *node)
{
	int		i;
	int		n_option;
	char	**argv;

	argv = linked_list_to_array(node);
	if (!argv)
		return (-1);
	i = 1;
	n_option = 0;
	if (argv[1] != NULL)
	{
		n_option = parse_echo_options(argv, &i);
		echo_argv(argv, i);
	}
	check_newline(n_option);
	free_argv(argv);
	return (0);
}

// int	ft_echo(int argc, ...)
// {
// 	int		i;
// 	int		n_option;
// 	char	**argv;
// 	va_list	args;

// 	va_start(args, argc);
// 	argv = va_arg(args, char **);
// 	if (argc <= 0)
// 		return (-1);
// 	i = 1;
// 	n_option = 0;
// 	if (argc > 1)
// 	{
// 		n_option = parse_echo_options(argv, &i);
// 		echo_argv(argv, i);
// 	}
// 	check_newline(n_option);
// 	va_end(args);
// 	return (0);
// }

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhasmi <lhasmi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 21:13:13 by lhasmi            #+#    #+#             */
/*   Updated: 2023/08/05 21:13:15 by lhasmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

t_list	*slices_as_list(int num, struct s_slice *commands)
{
	t_list			*list = NULL;
	struct s_slice	*slice;
	int				i = 0;

	while (i < num)
	{
		slice = malloc(sizeof(struct s_slice));
		*slice = commands[i];
		ft_lstadd_back(&list, ft_lstnew(slice));
		i++;
	}
	return (list);
}

t_list	*redirections_as_list(int num, struct s_redirection *redirections)
{
	t_list					*list = NULL;
	struct s_redirection	*redirection;
	int						i = 0;

	while (i < num)
	{
		redirection = malloc(sizeof(struct s_redirection));
		*redirection = redirections[i];
		ft_lstadd_back(&list, ft_lstnew(redirection));
		i++;
	}
	return (list);
}

t_node	*make_tree(void)
{
	char *str = "echo hi | cat >>out >out2 | a=3 wc -l";
	t_node	*pipe1 = malloc(sizeof(t_node)); // root
	t_node	*pipe2 = malloc(sizeof(t_node));
	t_node	*command1 = malloc(sizeof(t_node));
	t_node	*command2 = malloc(sizeof(t_node));
	t_node	*command3 = malloc(sizeof(t_node));

	*pipe1 = (t_node) {
		.is_pipe = true,
		.left = command1,
		.right = pipe2,
		.commands = NULL,
		.redirections = NULL,
		.assignments = NULL
	};

	*pipe2 = (t_node) {
		.is_pipe = true,
		.left = command2,
		.right = command3,
		.commands = NULL,
		.redirections = NULL,
		.assignments = NULL
	};

	*command1 = (t_node) {
		.is_pipe = false,
		.left = NULL,
		.right = NULL,
		.commands = slices_as_list(2, (struct s_slice[2]) {
			{
				.start = str,
				.len = 4
			}, // means echo
			{
				.start = str + 5,
				.len = 2
			} // means hi
		}),
		.redirections = NULL,
		.assignments = NULL
	};
	*command2 = (t_node) {
		.is_pipe = false,
		.left = NULL,
		.right = NULL,
		.commands = slices_as_list(1, (struct s_slice[1]) {
			{
				.start = str + 10,
				.len = 3
			} // means cat
		}),
		.redirections = redirections_as_list(2, (struct s_redirection[2]) {
			{
				.type = REDIR_DOUBLE_GREAT,
				.data = (struct s_slice)
					{
						.start = str + 16,
						.len = 3
					}
			}, // means >>out
			{
				.type = REDIR_GREAT,
				.data = (struct s_slice)
					{
						.start = str + 21,
						.len = 4
					}
			} // means >out2
		}),
		.assignments = NULL
	};
	*command3 = (t_node) {
		.is_pipe = false,
		.left = NULL,
		.right = NULL,
		.commands = slices_as_list(2, (struct s_slice[2]) {
			{
				.start = str + 32,
				.len = 2
			}, // means wc
			{
				.start = str + 35,
				.len = 2
			} // means -l
		}),
		.redirections = NULL,
		.assignments = slices_as_list(1, (struct s_slice[1]) {
			{
				.start = str + 28,
				.len = 3
			} // means a=3
		})
	};

	// 	 |
	// echo	 |
	// 	cat		wc
	return (pipe1);
}

void	print_commands(t_list *list)
{
	struct s_slice	*slice;

	printf("commands: ");
	while (list)
	{
		slice = list->content;
		printf("%.*s ", slice->len, slice->start);
		list = list->next;
	}
	printf("\n");
}

void	print_redirections(t_list *list)
{
	struct s_redirection	*redirection;

	printf("redirection: ");
	while (list)
	{
		redirection = list->content;
		printf("[%d, %.*s] ", redirection->type, redirection->data.len, redirection->data.start);
		list = list->next;
	}
	printf("\n");
}

void	print_assignments(t_list *list)
{
	struct s_slice	*slice;

	printf("assignment: ");
	while (list)
	{
		slice = list->content;
		printf("[%.*s] ", slice->len, slice->start);
		list = list->next;
	}
	printf("\n");
}

void	print_tree(t_node *node)
{
	if (node == NULL)
		return ;
	printf("is_pipe: %d\n", node->is_pipe);
	print_commands(node->commands);
	print_redirections(node->redirections);
	print_assignments(node->assignments);
	printf("\n");
	print_tree(node->left);
	print_tree(node->right);
}

int main(void)
{
	t_node	*root = make_tree();
	print_tree(root);
	return (0);
}

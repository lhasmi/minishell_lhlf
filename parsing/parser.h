/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhasmi <lhasmi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 18:44:03 by lfiorini          #+#    #+#             */
/*   Updated: 2023/08/05 16:59:13 by lhasmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include <stdbool.h>
# include "../include/minishell.h"

// struct s_slice
// {
// 	int		start;
// 	int		len;
// };

//when we call the t_list the content will be a slice or in redirection it will be
// a redirection struct
typedef struct s_node
{
	bool			is_pipe;
	struct s_node	*left;
	struct s_node	*right;
	t_list	*commands;			// Linked list of t_slice
	t_list	*redirections;		// Linked list of t_redirection
	t_list	*assignments; 		// Linked list of t_slice
} t_node;

// struct s_node	*new_node(void);
// int				free_node(struct s_node *node);
// int				add_command(struct s_node *node, struct s_slice command);
// int				add_redirection(struct s_node *node, struct s_redirection redirection);
// int				add_assignment(struct s_node *node, struct s_slice assignment);
// int				free_tree(struct s_node *root);

typedef enum e_redirection_type
{
	REDIR_LESS,
	REDIR_DOUBLE_LESS,
	REDIR_GREAT,
	REDIR_DOUBLE_GREAT
} t_redirection_type;

typedef struct s_redirection
{
	enum e_redirection_type	type;
	struct s_slice			data;
} t_redirection;


// struct s_redirection	new_redirection(enum e_redirection_type type, struct s_slice data);

typedef struct s_parser
{
	struct s_lexer	*lexer;
	t_list			*current_token;
	struct s_node	*root;
	struct s_node	*current_node;
} t_parser;

// int	parser_init(struct s_parser *parser, struct s_lexer *lexer);
// int	parser_free(struct s_parser *parser);
// int	create_tree()

#endif

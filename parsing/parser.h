/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhasmi <lhasmi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 18:44:03 by lfiorini          #+#    #+#             */
/*   Updated: 2023/07/31 20:41:48 by lhasmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include <stdbool.h>


enum e_ast_node_type
{
	AST_NODE_CMD,
	AST_NODE_PIPE,
	AST_NODE_AND,
	AST_NODE_OR
};

struct s_ast_node
{
	enum e_ast_node_type		type;
	struct s_ast_node_content	*content;
	struct s_ast_node			*left;
	struct s_ast_node			*right;
};

struct s_ast_node_content
{
	t_ast_redirection_vector	redirection_in;
	t_ast_redirection_vector	redirection_out;
	t_sb_vector					assignment;
	t_sb_vector					command;
};

typedef enum e_ast_redirection_type
{
	REDIRCT_STDIN,
	REDIRECT_HEREDOC,
	REDIRECT_STDOUT,
	REDIRECT_STDOUT_APPEND
}	t_ast_redirection_type;

struct s_ast_redirection
{
	t_ast_redirection_type	type;
	t_ft_sb					content;
};

typedef enum e_parser_exit_code
{
	PARSER_SUCCESS,
	PARSER_FAILURE,
}			t_parser_exit_code;

struct s_parser
{
	bool				malloc_fail;
	struct s_ast_node	*head;
	struct s_ast_node	*current;
	struct s_token_list	*current_token;
};

#endif

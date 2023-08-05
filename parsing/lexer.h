/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhasmi <lhasmi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 19:27:22 by lfiorini          #+#    #+#             */
/*   Updated: 2023/08/05 17:14:31 by lhasmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEXER_H
# define LEXER_H

typedef enum e_token_type
{
	TOKEN_WORD,
	TOKEN_ASSIGNMENT_WORD,
	TOKEN_DLESS,
	TOKEN_DGREAT,
	TOKEN_LESS,
	TOKEN_GREAT,
	TOKEN_PIPE,
	TOKEN_EOF
} t_token_type;

struct s_slice
{
	// int	start;
	char	*start;
	int		len;
};

// struct s_slice	new_slice(int start, int len);

struct s_token
{
	struct s_slice		slice;
	enum e_token_type	type;
};

// struct s_token	new_token(struct s_slice slice, enum e_token_type type);


struct s_lexer
{
	t_list	*tokens;
	t_list	*current_token;
	char	*input;
};

// int	lexer_init(struct s_lexer *lexer, char *input);
// int	lexer_free(struct s_lexer *lexer);
// int	lexer_tokenize(struct s_lexer *lexer);
// int	lexer_add_token(struct s_lexer *lexer, struct s_token token);
// int	lexer_move_to_next_token(struct s_lexer *lexer);

#endif

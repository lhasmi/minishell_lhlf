# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lhasmi <lhasmi@student.42heilbronn.de>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/11 14:59:19 by lfiorini          #+#    #+#              #
#    Updated: 2023/08/04 20:51:14 by lhasmi           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	minishell
CC			=	gcc
RM			=	rm -rf
LIBFT		= 	libft/libft.a
CFLAGS		=	-g -Wall -Wextra -Werror -fsanitize=address
HEADER_FILES=	-I ./include -I libft/includes

ifeq ($(OS), Linux)
INCL_RDL_HEADER	= -I /home/linuxbrew/.linuxbrew/opt/readline/include/readline
INCL_RDL_LIB	= -lreadline -L /home/linuxbrew/.linuxbrew/opt/readline/lib
else
INCL_RDL_HEADER	= -I $(shell brew --prefix readline)/include
INCL_RDL_LIB	= -lreadline -L $(shell brew --prefix readline)/lib
endif


SRC	=	core/main.c \
		\
		envtable/envtable.c \
		envtable/envtable_utils.c \
		\
		builtins/env.c \
		builtins/echo.c \
		builtins/cd.c \
		builtins/exit.c \
		builtins/builtins.c \
		\
		execution/executor.c \
		execution/execution_helpers.c \
		execution/execution_helpers2.c \
		\
		parsing/parser.c \

OBJS = $(patsubst %.c,%.o,$(SRC))

all:$(NAME)


$(NAME): $(OBJS)
	cd libft && make
	$(CC) $(HEADER_FILES) -lreadline -lhistory $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME) $(INCL_RDL_LIB)

%.o: %.c
	@mkdir -p $(@D)
	$(CC) $(HEADER_FILES) $(INCL_RDL_HEADER) $(CFLAGS) -c $< -o $@

clean:
	@$(RM) $(OBJS)

fclean:	clean
	@cd libft && make fclean
	@$(RM) $(NAME)

re:	fclean all

.PHONY:	all bonus clean fclean re

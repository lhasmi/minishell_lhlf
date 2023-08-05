/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhasmi <lhasmi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 18:44:03 by lfiorini          #+#    #+#             */
/*   Updated: 2023/08/05 14:52:02 by lhasmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

///////////////////////////////////////////////
// Necessary includes for the allowed functions:
///////////////////////////////////////////////
#include <stdlib.h>     // For general functions such as malloc, free, exit etc
#include <sys/ioctl.h>  // Required for ioctl
#include <fcntl.h>      // Required for open
#include <term.h>       // Required for tgetent, tgetflag, tgetnum, tgetstr, tgoto, tputs
#include <curses.h>     // Required for tgetent, tgetflag, tgetnum, tgetstr, tgoto, tputs

#include <unistd.h>     // Provides access to the POSIX operating system APIs
#include <sys/wait.h>   // For wait and related functions
#include <stdio.h>      // For input/output
#include <readline/readline.h> // For readline function
#include <readline/history.h>  // For add_history function
#include <signal.h>     // For signal handling functions
#include <sys/types.h>  // For pid_t, etc
#include <sys/stat.h>   // For stat, fstat, lstat
#include <string.h>     // For string manipulation functions
#include <dirent.h>     // For directory handling functions
#include "../libft/includes/libft.h"
#include "../libft/includes/get_next_line.h"
#include "../libft/includes/ft_printf.h"
#include "../envtable/envtable.h"
#include "../builtins/builtins.h"
#include "../pipes/pipes.h"
#include "../execution/execution.h"

///////////////////////////////
// Supplementary handy includes:
//////////////////////////////
#include <ctype.h>      // Character handling functions (like isdigit, isalpha, etc)
#include <errno.h>      // For error handling, contains errno
#include <fnmatch.h>    // Filename matching types
#include <glob.h>       // Pathname pattern-matching types
#include <limits.h>     // Sizes of basic types
#include <locale.h>     // Localization (setlocale, etc)
#include <pwd.h>        // Password structure (provides user details)
#include <regex.h>      // Regular expression handling
#include <stdarg.h>     // Variable arguments
#include <stdbool.h>    // Boolean type and values
#include <termios.h>    // Terminal I/O interfaces


//////////// main.c /////////////
// void minishell();
// main();

/////////// parser.c ///////////
char** parse_input(char* input);
char* ft_strtok(char* str, const char* delim);


///////// redirections.c ///////

//////// pipes.c ///////////////

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pipex.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: quentinbeukelman <quentinbeukelman@stud      +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/04 17:24:44 by quentinbeuk   #+#    #+#                 */
/*   Updated: 2023/03/09 15:11:16 by qbeukelm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

/* to write, read, close, access, pipe, dup, dup2, execve, fork */
# include <unistd.h>
# include <sys/types.h>
# include <sys/uio.h>

/* malloc, free, exit */
# include <stdlib.h>

/* open, unlink */
# include <fcntl.h>

/* waitpid, wait */
# include <sys/wait.h>

/* strerror */
# include <string.h>

/* to perror */
# include <stdio.h>

/* libft */
# include "libft/includes/libft.h"

// Error messages
# define ERROR_INFILE "Infile"
# define ERROR_OUTFILE "Outfile"
# define ERROR_INPUT "Invalid number of arguments.\n"
# define ERROR_PIPE "Pipe"
# define ERROR_CMD "Command not found\n"

typedef struct s_pipex
{
	pid_t	pid1;
	pid_t	pid2;
	int		tube[2];
	int		infile;
	int		outfile;
	char	*paths;
	char	**cmd_paths;
	char	**cmd_args;
	char	*cmd;
}	t_pipex;

// ===== Child Process =====
char			*find_path(char **envp);
static char		*get_cmd(char **paths, char *cmd);
void			first_child(t_pipex pipex, char *argv[], char *envp[]);
void			second_child(t_pipex pipex, char *argv[], char *envp[]);

// ===== Free Process ======
void			free_parent(t_pipex *pipex);
void			child_free(t_pipex *pipex);
void			close_pipes(t_pipex *pipex);

// ===== Error =====
int				ft_message(char *error);
void			ft_error_message(char *error);
char			**protec(char **ptr);

#endif

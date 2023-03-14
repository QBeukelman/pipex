/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   child_process.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: quentinbeukelman <quentinbeukelman@stud      +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/04 17:58:51 by quentinbeuk   #+#    #+#                 */
/*   Updated: 2023/03/14 15:11:07 by qbeukelm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/pipex.h"

char	*find_path(char **envp)
/**
 * @brief      Find the PATH environment variable from an array of environment variables.
 * @param      envp  An array of strings containing the environment variables.
 * @return     A pointer to the start of the PATH string in the environment variables, or NULL if PATH is not found.
*/
{
	const char		*path_str;
	size_t			path_len;

	path_str = "PATH=";
	path_len = ft_strlen(path_str);
	while (*envp != NULL)
	{
		if (ft_strncmp(*envp, path_str, path_len) == 0)
			return (*envp + path_len);
		envp++;
	}
	return (NULL);
}

static char	*get_cmd(char **paths, char *cmd)
/**
 * @brief 	Searches for the command in the specified paths and returns the full path if found, or NULL if not found.
 * @param 	paths An array of strings containing the directories to search for the command.
 * @param 	cmd The name of the command to search for.
 * @return 	The full path of the command if found, or NULL if not found.
*/
{
	char	*tmp;
	char	*command;

	while (*paths)
	{
		tmp = ft_strjoin(*paths, "/");
		command = ft_strjoin(tmp, cmd);
		free(tmp);
		if (access(command, 0) == 0)
			return (command);
		free(command);
		paths++;
	}
	return (NULL);
}

void	first_child(t_pipex pipex, char *argv[], char *envp[])
/**
 * @brief 	1. Close the read end of the pipe.
 * 			2. Duplicate the write end of the pipe to stdout.
 * 			3. Duplicate the input file to stdin.
 * 			4. Split the command arguments.
 * 			5. Find the full path of the command.
 * 			6. Execute the command.

 * @param 	pipex The pipex struct containing the necessary file descriptors and paths for the pipe and command.
 * @param 	argv The argument vector containing the command-line arguments.
 * @param 	envp The environment vector containing the environment variables.
*/
{
	close(pipex.tube[0]);
	if (dup2(pipex.tube[1], STDOUT_FILENO) == -1)
	{
		perror("dup2");
		exit(EXIT_FAILURE);
	}
	if (dup2(pipex.infile, STDIN_FILENO) == -1)
	{
		perror("dup2");
		exit(EXIT_FAILURE);
	}
	pipex.cmd_args = protec(ft_split(argv[2], ' '));
	pipex.cmd = get_cmd(pipex.cmd_paths, pipex.cmd_args[0]);
	if (!pipex.cmd)
	{
		child_free(&pipex);
		ft_message(ERROR_CMD);
		exit(1);
	}
	execve(pipex.cmd, pipex.cmd_args, envp);
}

void	second_child(t_pipex pipex, char *argv[], char *envp[])
/**
 * @brief 	Duplicates the read end of the pipe to stdin and the output file to stdout,
 *       	sets up the command arguments and path, and executes the command for the second child process.
*/
{
	close(pipex.tube[1]);
	if (dup2(pipex.tube[0], STDIN_FILENO) == -1)
	{
		perror("dup2");
		exit(EXIT_FAILURE);
	}
	if (dup2(pipex.outfile, STDOUT_FILENO) == -1)
	{
		perror("dup2");
		exit(EXIT_FAILURE);
	}
	pipex.cmd_args = protec(ft_split(argv[3], ' '));
	pipex.cmd = get_cmd(pipex.cmd_paths, pipex.cmd_args[0]);
	if (!pipex.cmd)
	{
		child_free(&pipex);
		ft_message(ERROR_CMD);
		exit(1);
	}
	execve(pipex.cmd, pipex.cmd_args, envp);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pipex.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: quentinbeukelman <quentinbeukelman@stud      +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/04 16:43:18 by quentinbeuk   #+#    #+#                 */
/*   Updated: 2023/03/07 10:58:56 by quentinbeuk   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

/*

*	    infile                                             outfile
*	as stdin for cmd1                                 as stdout for cmd2           
*	       |                        PIPE                        ↑
*	       |           |---------------------------|            |
*	       ↓             |                       |              |
*	      cmd1   -->    end[1]       ↔       end[0]   -->     cmd2           
*	                     |                       |
*	            cmd1   |---------------------------|  end[0]
*	           output                             reads end[1]
*	         is written                          and sends cmd1
*	          to end[1]                          output to cmd2
*	       (end[1] becomes                      (end[0] becomes 
*	        cmd1 stdout)                           cmd2 stdin)
		
Read from infile, execute cmd1 with infile as input, send the output to cmd2, 
which will write to outfile. 

pipe() sends the output of the first execve() as input to the second execve(); 
fork() runs two processes (i.e. two commands) in one single program; 
dup2() swaps our files with stdin and stdout. 

*/

int	main(int argc, char *argv[], char *envp[])
/**
 * @brief      The main function for the pipex program.
 * 				1. Assign infile and outfile.
 * 						O_TRUNC - truncate the file to zero length if it already exists.
 * 						O_CREAT - create the file if it does not exist.
 * 						O_RDWR - open the file for both reading and writing.
 * 						0000644 - read-write for the owner and read-only for group and others.
 * 				2. Assign the pipe.
 * 				3. Get path from envp.
 * 				4. Fork the process.
 * 				5. Close process & waitpid.
 * 
 * @param[in]  argc   The number of command-line arguments.
 * @param      argv   An array of strings containing the command-line arguments.
 * @param      envp   An array of strings containing the environment variables.
 * 
 * @return     An integer indicating whether the program ran successfully or not.
*/
{
	t_pipex		pipex;

	if (argc != 5)
		return (ft_message(ERROR_INPUT));
	pipex.infile = open(argv[1], O_RDONLY);
	if (pipex.infile < 0)
		ft_error_message(ERROR_INFILE);
	pipex.outfile = open(argv[argc - 1], O_TRUNC | O_CREAT | O_RDWR, 0000644);
	if (pipex.outfile < 0)
		ft_error_message(ERROR_OUTFILE);
	if (pipe(pipex.tube) < 0)
		ft_error_message(ERROR_PIPE);
	pipex.paths = find_path(envp);
	pipex.cmd_paths = ft_split(pipex.paths, ':');
	pipex.pid1 = fork();
	if (pipex.pid1 == 0)
		first_child(pipex, argv, envp);
	pipex.pid2 = fork();
	if (pipex.pid2 == 0)
		second_child(pipex, argv, envp);
	close_pipes(&pipex);
	waitpid(pipex.pid1, NULL, 0);
	waitpid(pipex.pid2, NULL, 0);
	free_parent(&pipex);
	return (EXIT_SUCCESS);
}

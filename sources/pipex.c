/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pipex.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: quentinbeukelman <quentinbeukelman@stud      +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/04 16:43:18 by quentinbeuk   #+#    #+#                 */
/*   Updated: 2023/03/09 16:45:29 by qbeukelm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

/*

*		┌────────┐
*		|  pipe  |
*		└───┬────┘
*			|
*		┌───┴────┐
*		| fork() |
*		└───┬────┘
*			|
*		┌───┴────┐			┌────────┐
*		| child  |			| parent |
*		| cmd1   |			| cmd2   |
*		└───┬────┘			└───┬────┘
*			|					|
*			dup2()				dup2()
*			|					|
*			close				close
*			end[0]				end[1]
*			|					|
*			execve()			execve()
*			(cmd1)				(cmd2)
		
Read from infile, execute cmd1 with infile as input, send the output to cmd2, 
which will write to outfile. 

*	pipe() 		A successfull call to pipe() returns two open file descriptors, each
*				for read[0] and write[1] ends of the pipe. Simply put, a pipe allows
*				communication between two processes. Sends the output of the first 
*				execve() as input to the second execve().

*	fork()		Allows one process, the parent, to create a new process, the child.
*				After fork has completed its work, two processess exist, in each,
*				exicution continues from the point where fork returns. Each process
*				has seperate copies of the stack, data and heap.
*					fork() = 0 -> Child process
*					fork() > 0 -> Parent process

*	dup2()	 	Makes a duplicate of the file discriptor given in oldfd, using the
*				descriptor number supplied in newfd. A successful dup2() return the 
*				number of duplicate discriptor. In this case, dup2() is used to swaps
*				our files with stdin and stdout.

*	waitpid()	Wait for the child to terminate. If no child of the calling process
*				has yet terminated, the call blocks untill one of the children 
*				terminates. If a child has already terminated by the time of the 
*				call, wait() returns immediatly. This pid argument enables the 
*				selection of the child to be waited for. If pid is 0, wait or 
*				any child in the same process group as the caller, 'parent'.

*	execve()	Load a new program with params, (pathname, argv, envp), into a 
*				processes memory. The stack, data and heap are freshly created 
*				for the program.

*	envp		Specifies the environment list for the new program. It is a 
*				NULL turminated list of pointers to character strings that 
*				form name=value.

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
	pipex.cmd_paths = protec(ft_split(pipex.paths, ':'));
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

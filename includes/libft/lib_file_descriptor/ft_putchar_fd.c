/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putchar_fd.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: qbeukelm <qbeukelm@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/12 10:15:59 by qbeukelm      #+#    #+#                 */
/*   Updated: 2022/12/02 11:52:30 by quentinbeuk   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

// Output (using write(2)), the character 'c' to the given file descriptor

// Paramaters:
// c: the character to output.
// fd: the file descripter on which to write.

// Return Value: none.

// Notes:
// A file descriptor is a number that is unique accross the process.
// They represent a key to handle an inout or output resource.
// Use (man open(2)) when testing.

// file descriptors		file
// 0					STDIN
// 1					STDOUT
// 2					STDERR

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, sizeof(c));
}

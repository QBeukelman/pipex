/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   error.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: quentinbeukelman <quentinbeukelman@stud      +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/07 09:31:28 by quentinbeuk   #+#    #+#                 */
/*   Updated: 2023/03/09 15:11:44 by qbeukelm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/pipex.h"

int	ft_message(char *error)
{
	write(2, error, ft_strlen(error));
	return (1);
}

void	ft_error_message(char *error)
{
	perror(error);
	exit (1);
}

char	**protec(char **ptr)
{
	if (ptr == NULL)
		exit (1);
	return (ptr);
}
